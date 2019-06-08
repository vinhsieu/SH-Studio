#include "Butterfly.h"



Butterfly::Butterfly(float x, float y, int TypeItem)
{
	CGameObject::CGameObject();
	this->HealthBackup = Health;
	this->x = x;
	this->y = y;
	this->xBackup = x;
	this->yBackup = y;
	this->type = eType::ButterFly;
	this->TypeItems = TypeItem;
	items = ItemsManager::GetInstance()->itemGenerator(this->x,this->y,TypeItem);
	LoadAni();
}

void Butterfly::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

void Butterfly::Render()
{
	if (this->Health == 0)
	{
	    HealthBackup = 0;
		return;
	}
	this->animations[0]->Render(this->x+ Butterfly_To_Center_X, this->y+ Butterfly_To_Center_Y, 0, 0, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(Butterfly_To_Center_X, Butterfly_To_Center_Y);
	}
}

void Butterfly::LoadAni()
{

	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(200, 83, 139, 98, 152, tex);
	sprites->Add(201, 98, 136, 114, 153, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(200);
	ani->Add(201);
	animations->Add(2000, ani);
	AddAnimation(2000);
}

void Butterfly::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + Butterfly_To_Center_X*2;
	bottom = y + Butterfly_To_Center_Y*2;
}

void Butterfly::SubHealth(int th)
{
	ItemsManager::GetInstance()->AddItem(this->items);
	CGameObject::SubHealth(th);
}


Butterfly::~Butterfly()
{
}
