#include "ItemFreezeTime.h"



ItemFreezeTime::ItemFreezeTime(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemFreezeTime_Lasting_Time;
	this->type = eType::Item_Freeze_Time;
	LoadAni();
}


void ItemFreezeTime::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(241, 246, 91, 258, 106, tex);
}

void ItemFreezeTime::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(241)->Draw(this->x + ItemFreezeTime_To_Center_X, this->y + ItemFreezeTime_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemFreezeTime_To_Center_X, ItemFreezeTime_To_Center_Y);
	}
}

void ItemFreezeTime::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}

ItemFreezeTime::~ItemFreezeTime()
{
}
