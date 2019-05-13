#include "Panther.h"



Panther::Panther(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::Panther;
	LoadAni();
}

void Panther::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(800, 314, 79, 346, 93, tex);
	sprites->Add(801, 355, 77, 381, 93, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(800);
	ani->Add(801);
	animations->Add(1031, ani);
	AddAnimation(1031);
	
}

void Panther::Render()
{
	CCamera * mCamera = CCamera::GetInstance();
	D3DXVECTOR2 trans = D3DXVECTOR2(320 / 2 - mCamera->GetPosition().x,
		208 / 2 - mCamera->GetPosition().y);
	
		this->animations.at(0)->Render(this->x, this->y, isAttach, this->nx, trans);
	
}

void Panther::Update(DWORD dt)
{
	CGameObject::Update(dt);
}


Panther::~Panther()
{
}
