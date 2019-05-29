#include "ItemRedStack.h"



ItemRedStack::ItemRedStack(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemRedStack_Lasting_Time;
	this->type = eType::Item_RedStack;
	LoadAni();
}


void ItemRedStack::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(251, 22, 91, 37, 106, tex);
}

void ItemRedStack::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(251)->Draw(this->x + ItemRedStack_To_Center_X, this->y + ItemRedStack_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemRedStack_To_Center_X, ItemRedStack_To_Center_Y);
	}
}

void ItemRedStack::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}

ItemRedStack::~ItemRedStack()
{
}
