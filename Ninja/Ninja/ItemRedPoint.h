#pragma once
#include "Items.h"


#define ItemRedPoint_Lasing_Time 20000
#define ItemRedPoint_To_Center_X 8
#define ItemRedPoint_To_Center_Y 10
class ItemRedPoint :
	public Items
{
public:
	ItemRedPoint(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemRedPoint();
};

