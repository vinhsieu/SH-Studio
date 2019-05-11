#include "Dagger.h"






CDagger::CDagger(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	LoadAni();
}

void CDagger::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);
	
	sprites->Add(500, 409, 14, 437, 46,tex);
	sprites->Add(501, 444, 14, 473, 46,tex);
	sprites->Add(502, 491, 3, 515, 57, tex);

	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(50);
	ani->Add(500);
	ani->Add(501);
	animations->Add(1000, ani);
	//Danh
	ani = new CAnimation(50);
	ani->Add(501);
	ani->Add(502);
	animations->Add(1001, ani);
	this->animations.push_back(animations->Get(1000));
	this->animations.push_back(animations->Get(1001));

}

void CDagger::Render()
{
	CCamera * mCamera = CCamera::GetInstance();
	D3DXVECTOR2 trans = D3DXVECTOR2(320 / 2 - mCamera->GetPosition().x,
		208 / 2 - mCamera->GetPosition().y);
	if (isAttach = -1)
	{
		animations.at(0)->Render(this->x, this->y, isAttach, this->nx, trans);
	}
	else
	{
		animations.at(1)->Render(this->x, this->y, isAttach, this->nx, trans);
	}
}

void CDagger::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

CDagger::~CDagger()
{
}
