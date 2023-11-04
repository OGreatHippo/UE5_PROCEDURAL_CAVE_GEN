#include "CaveGenerator.h"
#include "ProceduralMeshComponent.h"

// Sets default values
ACaveGenerator::ACaveGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshComponent"));
	

}

// Called when the game starts or when spawned
void ACaveGenerator::BeginPlay()
{
	Super::BeginPlay();

	mesh->SetMaterial(0, material);
	mesh->SetComponentTickEnabled(true);

	GenerateCave();
}

// Called every frame
void ACaveGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GenerateNewCave(DeltaTime);
}

void ACaveGenerator::GenerateCave()
{
	cave.Init(TArray<int>(), width);
	
	for (int x = 0; x < width; x++)
	{
		cave[x].Init(0, height);
	}

	RandomFillCave();

	for (int i = 0; i < 5; i++)
	{
		SmoothCave();
	}

	meshGen.GenerateMesh(cave, 1, mesh);
}

void ACaveGenerator::RandomFillCave()
{
	FDateTime time = FDateTime::Now();
	seed = time.ToString();
	uint32 seedHash = FCrc::StrCrc32(*seed);
	FRandomStream randomStream(seedHash);

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
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
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			int neighbouringWalls = GetNeighbouringWalls(x, y);

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

int ACaveGenerator::GetNeighbouringWalls(int _x, int _y)
{
	int wallCount = 0;

	for (int x = _x - 1; x <= _x + 1; x++)
	{
		for (int y = _y - 1; y <= _y + 1; y++)
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

