#include "CaveGenerator.h"

// Sets default values
ACaveGenerator::ACaveGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACaveGenerator::BeginPlay()
{
	Super::BeginPlay();
	
	GenerateCave();
}

// Called every frame
void ACaveGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GenerateNewCave(DeltaTime);
}

void ACaveGenerator::GenerateCave()
{
	cave.Init(TArray<unsigned char>(), width);
	
	for (unsigned char x = 0; x < width; x++)
	{
		cave[x].Init(0, height);
	}

	RandomFillCave();

	for (unsigned char i = 0; i < 5; i++)
	{
		SmoothCave();
	}

	meshGen.GenerateMesh(cave, 1, GetWorld());
}

void ACaveGenerator::RandomFillCave()
{
	FDateTime time = FDateTime::Now();
	seed = time.ToString();
	uint32 seedHash = FCrc::StrCrc32(*seed);
	FRandomStream randomStream(seedHash);

	for (unsigned char x = 0; x < width; x++)
	{
		for (unsigned char y = 0; y < height; y++)
		{
			float randomValue = randomStream.FRandRange(0, 100);

			if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
			{
				cave[x][y] = 1;
			}

			cave[x][y] = (randomValue < randomFillPercent) ? 1 : 0;	
		}
	}
}

void ACaveGenerator::SmoothCave()
{
	for (unsigned char x = 0; x < width; x++)
	{
		for (unsigned char y = 0; y < height; y++)
		{
			unsigned short neighbouringWalls = GetNeighbouringWalls(x, y);

			if (neighbouringWalls > 4)
			{
				cave[x][y] = 1;
			}
			else if (neighbouringWalls < 4)
			{
				cave[x][y] = 0;
			}
		}
	}
}

unsigned char ACaveGenerator::GetNeighbouringWalls(unsigned char _x, unsigned char _y)
{
	unsigned char wallCount = 0;

	for (unsigned char x = _x - 1; x <= _x + 1; x++)
	{
		for (unsigned char y = _y - 1; y <= _y + 1; y++)
		{
			if (x >= 0 && x < width && y >= 0 && y < height)
			{
				if (x != _x || y != _y)
				{
					wallCount += cave[x][y];
				}
			}

			else
			{
				wallCount++;
			}
		}
	}

	return wallCount;
}

void ACaveGenerator::GenerateNewCave(float DeltaTime)
{
	timer -= 1.0f * DeltaTime;

	if (timer <= 0)
	{
		GenerateCave();
		timer = 5.0f;
	}
}

