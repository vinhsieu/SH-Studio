#include "ItemHadoken.h"



ItemHadoken::ItemHadoken(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemHadoken_Lasting_Time;
	this->type = eType::Item_Hadoken;
	LoadAni();
}


void ItemHadoken::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(256, 110, 90, 126, 106, tex);
}

void ItemHadoken::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(256)->Draw(this->x + ItemHadoken_To_Center_X, this->y + ItemHadoken_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemHadoken_To_Center_X, ItemHadoken_To_Center_Y);
	}
}

void ItemHadoken::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}

ItemHadoken::~ItemHadoken()
{
}
