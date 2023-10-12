#include "Square.h"

Square::Square()
{
}

Square::~Square()
{
}

Square::Square(ControlNode* _topLeft, ControlNode* _topRight, ControlNode* _bottomRight, ControlNode* _bottomLeft)
{
	topLeft = _topLeft;
	topRight = _topRight;
	bottomRight = _bottomRight;
	bottomLeft = _bottomLeft;

	centreTop = topLeft->right;
	centreRight = bottomRight->above;
	centreBottom = bottomLeft->right;
	centreLeft = bottomLeft->above;
}
