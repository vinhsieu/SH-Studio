#include "ItemBluePoint.h"



ItemBluePoint::ItemBluePoint(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemBluePoint_Lasting_Time;
	this->type = eType::Item_Blue_Point;
	LoadAni();
}


void ItemBluePoint::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(266, 173, 91, 189, 106, tex);

}

void ItemBluePoint::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(266)->Draw(this->x + ItemBluePoint_To_Center_X, this->y + ItemBluePoint_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemBluePoint_To_Center_X, ItemBluePoint_To_Center_Y);
	}
}

void ItemBluePoint::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}

ItemBluePoint::~ItemBluePoint()
{
}
