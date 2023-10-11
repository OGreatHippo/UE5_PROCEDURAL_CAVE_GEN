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

}

void ACaveGenerator::GenerateCave()
{
	cave.Init(TArray<char>(), width);
	
	for (unsigned char x = 0; x < width; x++)
	{
		cave[x].Init(0, height);
	}

	RandomFillCave();
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

			cave[x][y] = (randomValue < randomFillPercent) ? 1 : 0;

			TestGizmos(x, y);
		}
	}
}

void ACaveGenerator::TestGizmos(unsigned char _x, unsigned char _y)
{
	if (!cave.IsEmpty())
	{
		FColor cubeColour = (cave[_x][_y] == 1) ? FColor::Black : FColor::White;
		FVector position = FVector(-width / 2 + _x + 0.5f, 0.0f, -height / 2 + _y + 0.5f);

		DrawDebugSolidBox(GetWorld(), position, FVector(0.5f), cubeColour, true);
	}
}

