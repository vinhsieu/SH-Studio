#include "ItemRedPoint.h"



ItemRedPoint::ItemRedPoint(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemRedPoint_Lasing_Time;
	this->type = eType::Item_Red_Point;
	LoadAni();
}


void ItemRedPoint::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(271, 194, 91, 210, 106, tex);
}

void ItemRedPoint::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(271)->Draw(this->x + ItemRedPoint_To_Center_X, this->y + ItemRedPoint_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemRedPoint_To_Center_X, ItemRedPoint_To_Center_Y);
	}
}

void ItemRedPoint::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}

ItemRedPoint::~ItemRedPoint()
{
}
