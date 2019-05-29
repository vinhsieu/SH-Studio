#include "ItemHealth.h"



ItemHealth::ItemHealth(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemHealth_Lasting_Time;
	this->type = eType::Item_Heath;
	LoadAni();
}


void ItemHealth::LoadAni()
{

	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(261, 230, 90, 242, 106, tex);

}

void ItemHealth::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(261)->Draw(this->x + ItemHealth_To_Center_X, this->y + ItemHealth_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemHealth_To_Center_X, ItemHealth_To_Center_Y);
	}
}

void ItemHealth::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}

ItemHealth::~ItemHealth()
{
}
