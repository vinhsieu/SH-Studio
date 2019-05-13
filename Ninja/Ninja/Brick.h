#pragma once
#include "CGameObject.h"
class Brick :
	public CGameObject
{
	int width;
	int height;
public:
	Brick(float X, float Y, int W, int H);
	
	void Render();
	
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~Brick();
};

