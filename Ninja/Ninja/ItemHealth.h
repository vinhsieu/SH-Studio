#pragma once
#include "Items.h"
#define ItemHealth_Lasting_Time 20000
#define ItemHealth_To_Center_X 8
#define ItemHealth_To_Center_Y 10
class ItemHealth :
	public Items
{
public:
	ItemHealth(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemHealth();
};

