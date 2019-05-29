#pragma once
#include "Items.h"

#define ItemRedShuriken_Lasting_Time 20000
#define ItemRedShuriken_To_Center_X 8
#define ItemRedShuriken_To_Center_Y 10
class ItemRedShuriken :
	public Items
{
public:
	ItemRedShuriken(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemRedShuriken();
};

