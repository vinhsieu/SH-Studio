#include "BrownBird.h"






BrownBird::BrownBird(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::BrownBird;
	LoadAni();
}

void BrownBird::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);
	sprites->Add(600, 478, 73, 494, 90, tex);
	sprites->Add(601, 504, 59, 523, 95, tex);
	LPANIMATION ani;
	//Bay
	ani = new CAnimation(100);
	ani->Add(600);
	ani->Add(601);
	animations->Add(1011, ani);
	AddAnimation(1011);
}

void BrownBird::Render()
{
	CCamera * mCamera = CCamera::GetInstance();
	D3DXVECTOR2 trans = D3DXVECTOR2(320 / 2 - mCamera->GetPosition().x,
		208 / 2 - mCamera->GetPosition().y);

	this->animations.at(0)->Render(this->x, this->y, isAttach, this->nx, trans);
}

void BrownBird::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

BrownBird::~BrownBird()
{
}
