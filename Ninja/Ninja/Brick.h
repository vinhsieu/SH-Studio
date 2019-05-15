#pragma once
#include "CGameObject.h"
class CBrick :
	public CGameObject
{
	int width;
	int height;
public:
	CBrick(float X, float Y, int W, int H);
	
	void Render();
	
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~CBrick();
};

