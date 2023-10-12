#include "MeshGenerator.h"

MeshGenerator::MeshGenerator()
{
}

MeshGenerator::~MeshGenerator()
{
}

void MeshGenerator::GenerateMesh(TArray<TArray<unsigned char>> _cave, unsigned char _squareSize, /*only for gizmos */ UWorld* _world)
{
	squareGrid = new SquareGrid(_cave, _squareSize);

	TestGizmos(_world);
}

void MeshGenerator::TestGizmos(UWorld* _world)
{
	if (squareGrid)
	{
		for (unsigned char x = 0; x < squareGrid->squares.Num(); x++)
		{
			for (unsigned char y = 0; y < squareGrid->squares[x].Num(); y++)
			{
				FColor cubeColour = (squareGrid->squares[x][y].topLeft->active == 1) ? FColor::Black : FColor::White;
				FVector position = FVector(squareGrid->squares[x][y].topLeft->pos);

				DrawDebugSolidBox(_world, position, FVector(0.5f), cubeColour, true);

				FColor trcubeColour = (squareGrid->squares[x][y].topRight->active == 1) ? FColor::Black : FColor::White;
				FVector trposition = FVector(squareGrid->squares[x][y].topRight->pos);

				DrawDebugSolidBox(_world, trposition, FVector(0.5f), trcubeColour, true);

				FColor brcubeColour = (squareGrid->squares[x][y].bottomRight->active == 1) ? FColor::Black : FColor::White;
				FVector brposition = FVector(squareGrid->squares[x][y].bottomRight->pos);

				DrawDebugSolidBox(_world, brposition, FVector(0.5f), brcubeColour, true);

				FColor blcubeColour = (squareGrid->squares[x][y].bottomLeft->active == 1) ? FColor::Black : FColor::White;
				FVector blposition = FVector(squareGrid->squares[x][y].bottomLeft->pos);

				DrawDebugSolidBox(_world, blposition, FVector(0.5f), blcubeColour, true);

				/*DrawDebugSolidBox(_world, squareGrid->squares[x][y].centreTop->pos, FVector(0.5f), FColor::Silver, true);
				DrawDebugSolidBox(_world, squareGrid->squares[x][y].centreRight->pos, FVector(0.5f), FColor::Silver, true);
				DrawDebugSolidBox(_world, squareGrid->squares[x][y].centreBottom->pos, FVector(0.5f), FColor::Silver, true);
				DrawDebugSolidBox(_world, squareGrid->squares[x][y].centreLeft->pos, FVector(0.5f), FColor::Silver, true);*/

				//UE_LOG(LogTemp, Warning, TEXT("Hello"));
			}
		}	
	}
}
