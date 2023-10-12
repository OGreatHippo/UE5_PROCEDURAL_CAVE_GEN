#include "ControlNode.h"

ControlNode::ControlNode()
{
}

ControlNode::~ControlNode()
{
}

ControlNode::ControlNode(FVector _pos, bool _active, unsigned char squareSize) : Node(_pos)
{
	active = _active;

	//Might be wrong
	pos = _pos;

	//Might need to create NewObject for above and right node first -> above = NewObject<Node>();
	above = new Node();
	above->pos = pos + FVector(0.0f, 1.0f, 0.0f) * squareSize / 2;
	right = new Node();
	right->pos = pos + FVector(1.0f, 0.0f, 0.0f) * squareSize / 2;
}
