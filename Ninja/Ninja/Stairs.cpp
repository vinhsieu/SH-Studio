#include "Stairs.h"



Stairs::Stairs(float X, float Y, int W, int H, int Multifunc)
{
	this->x = X;
	this->y = Y;
	this->Width = W;
	this->Height = H;
	this->AllowToClimb = Multifunc;
	this->yStart = Y;
	this->yEnd = Y + Height;
	this->type = eType::STAIR;
}


void Stairs::Render()
{
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(this->Width / 2, this->Height / 2);
	}
}

int Stairs::GetAllowToClimb()
{
	return this->AllowToClimb;
}

void Stairs::getStartEnd(float & yStart, float & yEnd)
{
	yStart = this->yStart;
	yEnd = this->yEnd;
}



void Stairs::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + Width;
	bottom = y + Height;
}

Stairs::~Stairs()
{
}
