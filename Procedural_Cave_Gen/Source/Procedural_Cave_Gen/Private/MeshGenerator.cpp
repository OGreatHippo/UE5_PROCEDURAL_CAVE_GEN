#include "MeshGenerator.h"

MeshGenerator::MeshGenerator()
{
}

MeshGenerator::~MeshGenerator()
{
	
}

void MeshGenerator::GenerateMesh(TArray<TArray<int>> _cave, int _squareSize, UProceduralMeshComponent* _mesh)
{
	squareGrid = new SquareGrid(_cave, _squareSize);

	vertices = TArray<FVector>();
	triangles = TArray<int>();

	for (int x = 0; x < squareGrid->squares.Num(); x++)
	{
		for (int y = 0; y < squareGrid->squares[x].Num(); y++)
		{
			TrigangulateSquare(squareGrid->squares[x][y]);
		}
	}

	_mesh = NewObject<UProceduralMeshComponent>();

	_mesh->CreateMeshSection(0, vertices, triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);
}

void MeshGenerator::TrigangulateSquare(Square _square)
{
	TArray<Node*> points;

	switch (_square.configuration)
	{
	case 0:
		break;

		// 1 points:
	case 1:
		points.Add(_square.centreBottom);
		points.Add(_square.bottomLeft);
		points.Add(_square.centreLeft);

		MeshFromPoints(points);
		break;
	case 2:
		points.Add(_square.centreRight);
		points.Add(_square.bottomRight);
		points.Add(_square.centreBottom);

		MeshFromPoints(points);
		break;
	case 4:
		points.Add(_square.centreTop);
		points.Add(_square.topRight);
		points.Add(_square.centreRight);

		MeshFromPoints(points);
		break;
	case 8:
		points.Add(_square.topLeft);
		points.Add(_square.centreTop);
		points.Add(_square.centreLeft);

		MeshFromPoints(points);
		break;

		// 2 points:
	case 3:
		points.Add(_square.centreRight);
		points.Add(_square.bottomRight);
		points.Add(_square.bottomLeft);
		points.Add(_square.centreLeft);

		MeshFromPoints(points);
		break;
	case 6:
		points.Add(_square.centreTop);
		points.Add(_square.topRight);
		points.Add(_square.bottomRight);
		points.Add(_square.centreBottom);

		MeshFromPoints(points);
		break;
	case 9:
		points.Add(_square.topLeft);
		points.Add(_square.centreTop);
		points.Add(_square.centreBottom);
		points.Add(_square.bottomLeft);

		MeshFromPoints(points);
		break;
	case 12:
		points.Add(_square.topLeft);
		points.Add(_square.topRight);
		points.Add(_square.centreRight);
		points.Add(_square.centreLeft);

		MeshFromPoints(points);
		break;
	case 5:
		points.Add(_square.centreTop);
		points.Add(_square.topRight);
		points.Add(_square.centreRight);
		points.Add(_square.centreBottom);
		points.Add(_square.bottomLeft);
		points.Add(_square.centreLeft);

		MeshFromPoints(points);
		break;
	case 10:
		points.Add(_square.topLeft);
		points.Add(_square.centreTop);
		points.Add(_square.centreRight);
		points.Add(_square.bottomRight);
		points.Add(_square.centreBottom);
		points.Add(_square.centreLeft);

		MeshFromPoints(points);
		break;

		// 3 point:
	case 7:
		points.Add(_square.centreTop);
		points.Add(_square.topRight);
		points.Add(_square.bottomRight);
		points.Add(_square.bottomLeft);
		points.Add(_square.centreLeft);

		MeshFromPoints(points);
		break;
	case 11:
		points.Add(_square.topLeft);
		points.Add(_square.centreTop);
		points.Add(_square.centreRight);
		points.Add(_square.bottomRight);
		points.Add(_square.bottomLeft);

		MeshFromPoints(points);
		break;
	case 13:
		points.Add(_square.topLeft);
		points.Add(_square.topRight);
		points.Add(_square.centreRight);
		points.Add(_square.centreBottom);
		points.Add(_square.bottomLeft);

		MeshFromPoints(points);
		break;
	case 14:
		points.Add(_square.topLeft);
		points.Add(_square.topRight);
		points.Add(_square.bottomRight);
		points.Add(_square.centreBottom);
		points.Add(_square.centreLeft);

		MeshFromPoints(points);
		break;

		// 4 point:
	case 15:
		points.Add(_square.topLeft);
		points.Add(_square.topRight);
		points.Add(_square.bottomRight);
		points.Add(_square.bottomLeft);

		MeshFromPoints(points);
		break;

	default:
		break;
	}
}

void MeshGenerator::MeshFromPoints(TArray<Node*>& _points)
{
	AssignVertices(_points);

	if (_points.Num() >= 3)
	{
		CreateTriangle(_points[0], _points[1], _points[2]);
	}
	if (_points.Num() >= 4)
	{
		CreateTriangle(_points[0], _points[2], _points[3]);
	}
	if (_points.Num() >= 5)
	{
		CreateTriangle(_points[0], _points[3], _points[4]);
	}
	if (_points.Num() >= 6)
	{
		CreateTriangle(_points[0], _points[4], _points[5]);
	}
}

void MeshGenerator::AssignVertices(TArray<Node*>& _points)
{
	for (int i = 0; i < _points.Num(); i++)
	{
		if (_points[i]->vertexIndex == -1)
		{
			_points[i]->vertexIndex = vertices.Num();
			vertices.Add(_points[i]->pos);
		}
	}
}

void MeshGenerator::CreateTriangle(Node* a, Node* b, Node* c)
{
	triangles.Add(a->vertexIndex);
	triangles.Add(b->vertexIndex);
	triangles.Add(c->vertexIndex);
}
