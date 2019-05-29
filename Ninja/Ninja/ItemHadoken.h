#pragma once
#include "Items.h"
#define ItemHadoken_Lasting_Time 20000
#define ItemHadoken_To_Center_X 8
#define ItemHadoken_To_Center_Y 10
class ItemHadoken :
	public Items
{
public:
	ItemHadoken(float x, float y);
	void LoadAni();
	void Render();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~ItemHadoken();
};

