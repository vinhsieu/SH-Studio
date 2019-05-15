#include "Footballguy.h"



CFootballguy::CFootballguy(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::Footballguy;
	LoadAni();
}

void CFootballguy::LoadAni()
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

void CFootballguy::Render()
{
	
	if (isAttach = -1)
	{
		this->animations.at(0)->Render(this->x+FOOTBALLGUY_TO_CENTERX, this->y+FOOTBALLGUY_TO_CENTERY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	}
	else
	{
		this->animations.at(1)->Render(this->x+FOOTBALLGUY_TO_CENTERX, this->y+FOOTBALLGUY_TO_CENTERY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(FOOTBALLGUY_TO_CENTERX,FOOTBALLGUY_TO_CENTERY);
	}
}

void CFootballguy::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

void CFootballguy::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 18;
	bottom = y + 33;
}


CFootballguy::~CFootballguy()
{
}
