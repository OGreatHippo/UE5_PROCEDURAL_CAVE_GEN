#pragma once

#include "CoreMinimal.h"
#include "SquareGrid.h"
#include "MeshDescription.h"

class PROCEDURAL_CAVE_GEN_API MeshGenerator
{
public:
	MeshGenerator();
	~MeshGenerator();

	SquareGrid* squareGrid;

	TArray<FVector> vertices;

	TArray<int> triangles;

	FMeshDescription meshDescription;

	void GenerateMesh(TArray<TArray<int>> _cave, int _squareSize, UStaticMeshComponent* _mesh);
	void TrigangulateSquare(Square _square);
	void MeshFromPoints(TArray<Node*>& _points);
	void AssignVertices(TArray<Node*>& _points);
	void CreateTriangle(Node* a, Node* b, Node* c);
};
