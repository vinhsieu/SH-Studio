#pragma once
#include "Items.h"


#define ItemRedStack_Lasting_Time 20000
#define ItemRedStack_To_Center_X 8
#define ItemRedStack_To_Center_Y 10

class ItemRedStack :
	public Items
{
public:
	ItemRedStack(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemRedStack();
};

