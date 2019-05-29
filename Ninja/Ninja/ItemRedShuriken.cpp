#include "ItemRedShuriken.h"



ItemRedShuriken::ItemRedShuriken(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemRedShuriken_Lasting_Time;
	this->type = eType::Item_RedShuriken;
	LoadAni();
}


void ItemRedShuriken::LoadAni()
{

	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(236, 70, 90, 86, 106, tex);
}

void ItemRedShuriken::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(236)->Draw(this->x + ItemRedShuriken_To_Center_X, this->y + ItemRedShuriken_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemRedShuriken_To_Center_X, ItemRedShuriken_To_Center_Y);
	}
}

void ItemRedShuriken::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}

ItemRedShuriken::~ItemRedShuriken()
{
}
