#include "SquareGrid.h"

SquareGrid::SquareGrid()
{
}

SquareGrid::~SquareGrid()
{
}

SquareGrid::SquareGrid(TArray<TArray<unsigned char>> _cave, unsigned char _squareSize)
{
	unsigned char nodeCountX = _cave.Num();
	unsigned char nodeCountY = (nodeCountX > 0) ? _cave[0].Num() : 0;

	unsigned short caveWidth = nodeCountX * _squareSize;
	unsigned short caveHeight = nodeCountY * _squareSize;

	TArray<TArray<ControlNode*>> controlNodes;

	controlNodes.SetNum(nodeCountX);

	for (unsigned char x = 0; x < nodeCountX; x++)
	{
		controlNodes[x].SetNum(nodeCountY);

		for (unsigned char y = 0; y < nodeCountY; y++)
		{
			FVector pos = FVector(-caveWidth / 2 + x * _squareSize + _squareSize / 2, 0, -caveHeight / 2 + y * _squareSize + _squareSize / 2);
			controlNodes[x][y] = new ControlNode(pos, _cave[x][y] == 1, _squareSize);
		}
	}

	squares.SetNum(nodeCountX - 1);

	for (unsigned char x = 0; x < nodeCountX - 1; x++)
	{
		squares[x].SetNum(nodeCountY - 1);

		for (unsigned char y = 0; y < nodeCountY - 1; y++)
		{
			squares[x][y] = Square(controlNodes[x][y + 1], controlNodes[x + 1][y + 1], controlNodes[x + 1][y], controlNodes[x][y]);
		}
	}
}
