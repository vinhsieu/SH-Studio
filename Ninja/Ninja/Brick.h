#pragma once
#include "CGameObject.h"
class CBrick :
	public CGameObject
{
	float xStart;
	float xEnd;
	int width;
	int height;
public:
	CBrick(float X, float Y, int W, int H);
	void getStartEnd(float &xStart,float &xEnd);
	void Render();
	
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~CBrick();
};

