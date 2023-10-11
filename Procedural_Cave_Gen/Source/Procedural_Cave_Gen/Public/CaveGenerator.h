#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CaveGenerator.generated.h"

UCLASS()
class PROCEDURAL_CAVE_GEN_API ACaveGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACaveGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, meta = (ClampMin = 0, ClampMax = 100))
	unsigned int randomFillPercent = 45;

	FString seed;

	unsigned char width = 60;
	unsigned char height = 60;

	float timer = 3.0f;

	TArray<TArray<char>> cave;

	void GenerateCave();

	void RandomFillCave();
	void SmoothCave();
	unsigned char GetNeighbouringWalls(unsigned char _x, unsigned char _y);
	void GenerateNewCave(float DeltaTime);


	void TestGizmos(unsigned char _x, unsigned char _y);
};
