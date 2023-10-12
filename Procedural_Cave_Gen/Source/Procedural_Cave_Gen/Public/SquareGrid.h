#pragma once

#include "CoreMinimal.h"
#include "Square.h"

class PROCEDURAL_CAVE_GEN_API SquareGrid
{
public:
	SquareGrid();
	~SquareGrid();

	TArray<TArray<Square>> squares;
	SquareGrid(TArray<TArray<unsigned char>> _cave, unsigned char _squareSize);
};
