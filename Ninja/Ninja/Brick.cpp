#include "Brick.h"



CBrick::CBrick(float X, float Y, int W, int H)
{
	this->x = X;
	this->y = Y;
	
	this->width = W;
	this->height = H;
	this->type = eType::BRICK;
}

void CBrick::getStartEnd(float &xStart, float &xEnd)
{
	xStart = this->x;
	xEnd = this->x + this->width;
}





void CBrick::Render()
{
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(this->width / 2, this->height / 2);
	}
	//DebugOut(L"[INFO]Toa Do Brick: %f, %f\n", x, y);
}



void CBrick::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + width;
	bottom = y + height;
}


CBrick::~CBrick()
{
}
