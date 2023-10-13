#pragma once

#include "CoreMinimal.h"

class PROCEDURAL_CAVE_GEN_API Node
{
public:
	Node();
	~Node();

	FVector pos;
	int vertexIndex = -1;

	Node(FVector _pos);
};
