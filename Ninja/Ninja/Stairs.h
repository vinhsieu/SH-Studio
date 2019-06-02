#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class Stairs :
	public CGameObject
{
	int AllowToClimb; //Cho phep Ninja Leo, 1 la cho leo, -1 la khong cho leo
	int Width;
	int Height;
	float yStart;
	float yEnd;
public:
	Stairs(float X, float Y, int W, int H, int Multifunc);
	void Render();
	int GetAllowToClimb(); //1 la cho leo, -1 la khong cho leo
	void getStartEnd(float &yStart,float &yEnd);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~Stairs();
};

