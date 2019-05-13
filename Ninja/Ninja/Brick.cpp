#include "Brick.h"



Brick::Brick(float X, float Y, int W, int H)
{
	this->x = X + W / 2;
	this->y = Y + H / 2;
	
	this->width = W;
	this->height = H;
	this->type = eType::BRICK;
}





void Brick::Render()
{
	RenderBoundingBox();
	DebugOut(L"[INFO]Toa Do Brick: %f, %f\n", x, y);
}



void Brick::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + width;
	bottom = y + height;
}


Brick::~Brick()
{
}
