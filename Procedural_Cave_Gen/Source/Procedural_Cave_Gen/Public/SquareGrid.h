#pragma once

#include "CoreMinimal.h"
#include "Square.h"

class PROCEDURAL_CAVE_GEN_API SquareGrid
{
public:
	SquareGrid();
	~SquareGrid();

	TArray<TArray<Square>> squares;
	SquareGrid(TArray<TArray<int>> _cave, int _squareSize);
};
