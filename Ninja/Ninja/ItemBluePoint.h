#pragma once
#include "Items.h"

#define ItemBluePoint_Lasting_Time 20000
#define ItemBluePoint_To_Center_X 8
#define ItemBluePoint_To_Center_Y 10
class ItemBluePoint :
	public Items
{
public:
	ItemBluePoint(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemBluePoint();
};

