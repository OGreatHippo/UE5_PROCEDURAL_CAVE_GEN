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
}

