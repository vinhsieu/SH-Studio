#include "ItemBlueShuriken.h"



ItemBlueShuriken::ItemBlueShuriken(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemBlueShuriken_Lasting_Time;
	this->type = eType::Item_BlueShuriken;
	LoadAni();
}

void ItemBlueShuriken::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	
	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(230, 50, 90, 66, 106, tex);
	
}

void ItemBlueShuriken::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(230)->Draw(this->x + ItemBlueShuriken_To_Center_X, this->y + ItemBlueShuriken_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemBlueShuriken_To_Center_X, ItemBlueShuriken_To_Center_Y);
	}
}

void ItemBlueShuriken::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}



ItemBlueShuriken::~ItemBlueShuriken()
{
}
