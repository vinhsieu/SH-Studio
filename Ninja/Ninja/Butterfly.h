#pragma once
#include "CGameObject.h"
#include"ItemsManager.h"
#include"Items.h"
#define Butterfly_To_Center_X 7
#define Butterfly_To_Center_Y 9
class Butterfly :
	public CGameObject
{
	Items * items;
	int TypeItems;
public:
	Butterfly(float x, float y, int TypeItem);
	void Update(DWORD dt);
	void Render();
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void SubHealth(int th);
	~Butterfly();
};

