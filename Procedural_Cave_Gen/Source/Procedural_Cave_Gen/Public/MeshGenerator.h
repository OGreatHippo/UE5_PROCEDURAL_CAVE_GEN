#pragma once

#include "CoreMinimal.h"
#include "SquareGrid.h"

class PROCEDURAL_CAVE_GEN_API MeshGenerator
{
public:
	MeshGenerator();
	~MeshGenerator();

	SquareGrid* squareGrid;

	void GenerateMesh(TArray<TArray<unsigned char>> _cave, unsigned char _squareSize, /*only for gizmos */ UWorld* _world);

	void TestGizmos(UWorld* _world);
};
