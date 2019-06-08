#include "BlackBird.h"



BlackBird::BlackBird(float x, float y, int TypeItem)
{
	CGameObject::CGameObject();
	this->HealthBackup = Health;
	this->x = x;
	this->y = y;
	this->xBackup = x;
	this->yBackup = y;
	this->type = eType::Black_Bird;
	this->TypeItems = TypeItem;
	items = ItemsManager::GetInstance()->itemGenerator(this->x, this->y, TypeItem);
	LoadAni();
}

void BlackBird::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

void BlackBird::Render()
{
	if (this->Health == 0)
	{
		return;
	}
	this->animations[0]->Render(this->x + BlackBird_To_Center_X, this->y + BlackBird_To_Center_Y, 0, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BlackBird_To_Center_X, BlackBird_To_Center_Y);
	}
}

void BlackBird::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(211, 118, 133, 136, 152, tex);
	sprites->Add(212, 139, 135, 157, 152, tex);
	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(211);
	ani->Add(212);
	animations->Add(2006, ani);
	AddAnimation(2006);
}

void BlackBird::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + BlackBird_To_Center_X * 2;
	bottom = y + BlackBird_To_Center_Y * 2;
}

void BlackBird::SubHealth(int th)
{
	ItemsManager::GetInstance()->AddItem(this->items);
	CGameObject::SubHealth(th);

}

BlackBird::~BlackBird()
{
}
