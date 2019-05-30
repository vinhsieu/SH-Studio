#include "Panther.h"
#include"Ninja.h"


CPanther::CPanther(float x, float y, int Direction)
{
	CGameObject::CGameObject();
	this->x = this->xBackup = x;
	this->y = this->yBackup = y;
	this->nx = this->nxBackup = Direction;
	this->HealthBackup = Health;
	this->isActive = false;
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
	if (!isActive)
	{
		return;
	}
	this->animations.at(0)->Render(this->x+PANTHER_TO_CENTEX, this->y+PANTHER_TO_CENTEY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(PANTHER_TO_CENTEX,PANTHER_TO_CENTEY);
	}
}

void CPanther::Update(DWORD dt)
{
	if (this->Health == 0)
	{
		return;
	}
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	float xNinja, yNinja;
	Ninja::GetInstance()->GetPosition(xNinja, yNinja);
	if (((this->x - xNinja)*nx < 0&& fabs(this->x - xNinja)<PANTHER_ACTIVE_AREA))
	{
		isActive = true;
	}
	if (isActive)
	{
		CGameObject::Update(dt);
		x += dx;
		y += dy;
	}
	
}

void CPanther::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 26;
	bottom = y + 17;
}

void CPanther::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y, PANTHER_TO_CENTEX * 2, PANTHER_TO_CENTEY * 2);
	}
	CGameObject::SubHealth(th);
}


CPanther::~CPanther()
{
}
