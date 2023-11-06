#pragma once

#include "CoreMinimal.h"
#include "Node.h"

class PROCEDURAL_CAVE_GEN_API ControlNode : public Node
{
public:
	ControlNode();
	~ControlNode();

	bool active;
	Node* above;
	Node* right;

	FVector pos = FVector(0, 0, 0);

	ControlNode(FVector _pos, bool _active, int squareSize);
};
