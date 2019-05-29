#include "ItemBlueStack.h"



ItemBlueStack::ItemBlueStack(float x, float y)
{
	CGameObject::CGameObject();
	Items::Items(x, y);
	this->x = x;
	this->y = y;
	this->TimeDisplayMax = ItemBlueStack_Lasting_Time;
	this->type = eType::Item_BlueStack;
	LoadAni();
}


void ItemBlueStack::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(246, 3, 91, 18, 106, tex);
}

void ItemBlueStack::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(246)->Draw(this->x + ItemBlueStack_To_Center_X, this->y + ItemBlueStack_To_Center_Y, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(ItemBlueStack_To_Center_X, ItemBlueStack_To_Center_Y);
	}
}

void ItemBlueStack::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 16;
}

ItemBlueStack::~ItemBlueStack()
{
}
