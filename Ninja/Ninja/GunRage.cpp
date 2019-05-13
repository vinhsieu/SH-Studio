#include "GunRage.h"



GunRage::GunRage(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::GunRage;
	LoadAni();
}

void GunRage::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(1100, 58, 60, 74, 92, tex);
	sprites->Add(1101, 83, 60, 101, 92, tex);
	sprites->Add(1102, 127, 60, 157, 92, tex);
	sprites->Add(1103, 159, 60, 187, 92, tex);

	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(1100);
	ani->Add(1101);
	animations->Add(1061, ani);
	AddAnimation(1061);
}

void GunRage::Render()
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

void GunRage::Update(DWORD dt)
{
	CGameObject::Update(dt);
}


GunRage::~GunRage()
{
}
