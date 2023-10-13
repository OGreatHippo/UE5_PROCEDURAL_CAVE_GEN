#include "SquareGrid.h"

SquareGrid::SquareGrid()
{
}

SquareGrid::~SquareGrid()
{
}

SquareGrid::SquareGrid(TArray<TArray<int>> _cave, int _squareSize)
{
	int nodeCountX = _cave.Num();
	int nodeCountY = (nodeCountX > 0) ? _cave[0].Num() : 0;

	int caveWidth = nodeCountX * _squareSize;
	int caveHeight = nodeCountY * _squareSize;

	TArray<TArray<ControlNode*>> controlNodes;

	controlNodes.SetNum(nodeCountX);

	for (int x = 0; x < nodeCountX; x++)
	{
		controlNodes[x].SetNum(nodeCountY);

		for (int y = 0; y < nodeCountY; y++)
		{
			FVector pos = FVector(-caveWidth / 2 + x * _squareSize + _squareSize / 2, 0, -caveHeight / 2 + y * _squareSize + _squareSize / 2);
			controlNodes[x][y] = new ControlNode(pos, _cave[x][y] == 1, _squareSize);
		}
	}

	squares.SetNum(nodeCountX - 1);

	for (int x = 0; x < nodeCountX - 1; x++)
	{
		squares[x].SetNum(nodeCountY - 1);

		for (int y = 0; y < nodeCountY - 1; y++)
		{
			squares[x][y] = Square(controlNodes[x][y + 1], controlNodes[x + 1][y + 1], controlNodes[x + 1][y], controlNodes[x][y]);
		}
	}
}
