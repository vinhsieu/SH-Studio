#include "Panther.h"



CPanther::CPanther(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::Panther;
	LoadAni();
}

void CPanther::LoadAni()
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

void CPanther::Render()
{
	
		this->animations.at(0)->Render(this->x+PANTHER_TO_CENTEX, this->y+PANTHER_TO_CENTEY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
		if (IS_BBOX_DEBUGGING)
		{
			RenderBoundingBox(PANTHER_TO_CENTEX,PANTHER_TO_CENTEY);
		}
}

void CPanther::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

void CPanther::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 26;
	bottom = y + 17;
}


CPanther::~CPanther()
{
}
