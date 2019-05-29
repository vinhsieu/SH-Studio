#pragma once
#include "Items.h"


#define ItemBlueStack_Lasting_Time 20000
#define ItemBlueStack_To_Center_X 8
#define ItemBlueStack_To_Center_Y 10
class ItemBlueStack :
	public Items
{
public:
	ItemBlueStack(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemBlueStack();
};

