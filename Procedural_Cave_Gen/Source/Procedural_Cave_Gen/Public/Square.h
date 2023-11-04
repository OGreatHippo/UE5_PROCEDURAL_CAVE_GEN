#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "ControlNode.h"

class PROCEDURAL_CAVE_GEN_API Square
{
public:
	Square();
	~Square();

	ControlNode* topLeft;
	ControlNode* topRight;
	ControlNode* bottomRight;
	ControlNode* bottomLeft;

	Node* centreTop;
	Node* centreRight;
	Node* centreBottom;
	Node* centreLeft;

	int configuration = 0;

	Square(ControlNode* _topLeft, ControlNode* _topRight, ControlNode* _bottomRight, ControlNode* _bottomLeft);
};
