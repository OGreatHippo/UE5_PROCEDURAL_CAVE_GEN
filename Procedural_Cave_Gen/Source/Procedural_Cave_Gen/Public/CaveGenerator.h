#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MeshGenerator.h"
#include "CaveGenerator.generated.h"

class UProceduralMeshComponent;

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

	int width = 60;
	int height = 60;

	float timer = 3.0f;

	TArray<TArray<int>> cave;

	void GenerateCave();

	void RandomFillCave();
	void SmoothCave();
	int GetNeighbouringWalls(int _x, int _y);
	void GenerateNewCave(float DeltaTime);

	MeshGenerator meshGen;

	UProceduralMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Material)
	UMaterialInterface* material;
};
