#pragma once
#include "Items.h"

#define ItemBlueShuriken_Lasting_Time 20000
#define ItemBlueShuriken_To_Center_X 8
#define ItemBlueShuriken_To_Center_Y 10
class ItemBlueShuriken :
	public Items
{
public:
	ItemBlueShuriken(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemBlueShuriken();
};

