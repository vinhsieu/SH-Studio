#include "Footballguy.h"



Footballguy::Footballguy(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::Footballguy;
	LoadAni();
}

void Footballguy::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(1000, 3, 60, 19, 92, tex);
	sprites->Add(1001, 22, 60, 40, 92, tex);

	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(1000);
	ani->Add(1001);
	animations->Add(1051, ani);
	AddAnimation(1051);
}

void Footballguy::Render()
{
	CCamera * mCamera = CCamera::GetInstance();
	D3DXVECTOR2 trans = D3DXVECTOR2(320 / 2 - mCamera->GetPosition().x,
		208 / 2 - mCamera->GetPosition().y);
	if (isAttach = -1)
	{
		this->animations.at(0)->Render(this->x, this->y, isAttach, this->nx, trans);
	}
	else
	{
		this->animations.at(1)->Render(this->x, this->y, isAttach, this->nx, trans);
	}
}

void Footballguy::Update(DWORD dt)
{
}


Footballguy::~Footballguy()
{
}
