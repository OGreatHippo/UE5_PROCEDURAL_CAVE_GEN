#pragma once

#include "CoreMinimal.h"
#include "Node.h"

class PROCEDURAL_CAVE_GEN_API ControlNode : Node
{
public:
	ControlNode();
	~ControlNode();

	bool active;
	Node* above;
	Node* right;

	FVector pos;

	ControlNode(FVector _pos, bool _active, unsigned char squareSize);
};
