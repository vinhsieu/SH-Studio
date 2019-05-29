#pragma once
#include "Items.h"


#define ItemFreezeTime_Lasting_Time 20000 // Thoi Gian Ton Tai
#define ItemFreezeTime_To_Center_X 8
#define ItemFreezeTime_To_Center_Y 10
class ItemFreezeTime :
	public Items
{
public:
	ItemFreezeTime(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemFreezeTime();
};

