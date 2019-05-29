#include "BrownBird.h"
#include"Ninja.h"




CBrownBird::CBrownBird(float x, float y, int Direction)
{
	this->x =this->xBackup= x;
	this->y =this->yBackup= y;
	this->nx =this->nxBackup= Direction;
	this->HealthBackup=this->Health;
	this->type = eType::BrownBird;
	lastTimeChangeDirection= GetTickCount();
	LoadAni();
}

void CBrownBird::LoadAni()
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

void CBrownBird::Render()
{
	if (this->Health == 0)
	{
		return;
	}
	float tempX, tempY;
	int AniDirection;
	Ninja::GetInstance()->GetPosition(tempX, tempY);
	if (tempX - this->x<0)
	{
		AniDirection = -1;
	}
	else
	{
		AniDirection = 1;
	}
	this->animations.at(0)->Render(this->x+BROWNBIRD_TO_CENTERX, this->y+BROWNBIRD_TO_CENTERY, 0,AniDirection, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BROWNBIRD_TO_CENTERX,BROWNBIRD_TO_CENTERY);
	}
}

void CBrownBird::Update(DWORD dt)
{
	if (this->Health == 0)
	{
		return;
	}
	Ninja::GetInstance()->GetPosition(xNinja, yNinja);
	DWORD now = GetTickCount();
	if (now - lastTimeChangeDirection > DELTA_TIME_CHANGE_DIRECTION)
	{
		this->vx = (xNinja - this->x) / (60*dt);
		this->vy = (yNinja - this->y) / (60*dt);
		lastTimeChangeDirection = now;
	}
	if (abs(vx) < 0.08)
	{
		vx = (vx*0.08) / abs(vx);
	}
	if (abs(vy) < 0.03)
	{
		vy = (vy*0.03) / abs(vy);
	}
	
	CGameObject::Update(dt);
	this->x += dx;
	this->y += dy;
}

void CBrownBird::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x +18;
	bottom = y + 15;
}

void CBrownBird::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y,BROWNBIRD_TO_CENTERX * 2, BROWNBIRD_TO_CENTERY * 2);
	}
	CGameObject::SubHealth(th);
}

CBrownBird::~CBrownBird()
{
}
