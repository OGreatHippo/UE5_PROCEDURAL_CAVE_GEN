#pragma once

#include "CoreMinimal.h"
#include "SquareGrid.h"

class PROCEDURAL_CAVE_GEN_API MeshGenerator
{
public:
	MeshGenerator();
	~MeshGenerator();

	SquareGrid* squareGrid;
	TArray<FVector> vertices;
	TArray<unsigned char> triangles;

	void GenerateMesh(TArray<TArray<unsigned char>> _cave, unsigned char _squareSize /*, UStaticMeshComponent* _mesh*/);
	void TrigangulateSquare(Square _square);
	void MeshFromPoints(TArray<Node*>& _points);
	void AssignVertices(TArray<Node*>& _points);
	void CreateTriangle(Node* a, Node* b, Node* c);
};
