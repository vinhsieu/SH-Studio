#include "Blade.h"



Blade::Blade(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	this->type = eType::Blade;
}

void Blade::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(700, 209, 60, 241, 92, tex);
	sprites->Add(701, 240, 60, 270, 92, tex);
	sprites->Add(702, 282, 52, 300, 99, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(700);
	ani->Add(701);
	ani->Add(702);
	animations->Add(1021, ani);
	AddAnimation(1021);
}

void Blade::Render()
{
	RenderBoundingBox();
	this->animations.at(0)->Render(this->x, this->y, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	
}

void Blade::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

void Blade::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x /*- 12*/;
	top = y /*- 16*/;
	right = x + 32;
	bottom = y + 32;
}


Blade::~Blade()
{
}
