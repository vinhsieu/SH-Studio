#pragma once
#include "CGameObject.h"
#include"ItemsManager.h"
#define BlackBird_To_Center_X 9
#define BlackBird_To_Center_Y 9
class BlackBird :
	public CGameObject
{
	Items * items;
	int TypeItems;
public:
	BlackBird(float x, float y, int TypeItem);
	void Update(DWORD dt);
	void Render();
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void SubHealth(int th);
	~BlackBird();
};

