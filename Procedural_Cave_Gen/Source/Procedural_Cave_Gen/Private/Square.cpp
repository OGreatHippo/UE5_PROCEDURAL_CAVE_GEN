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

	if (topLeft->active)
	{
		configuration += 8;
	}
	if (topRight->active)
	{
		configuration += 4;
	}
	if (bottomRight->active)
	{
		configuration += 2;
	}
	if (bottomLeft->active)
	{
		configuration += 1;
	}

	UE_LOG(LogTemp, Warning, TEXT("The config value is: %d"), configuration);
}
