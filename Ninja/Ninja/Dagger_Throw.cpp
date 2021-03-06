#include "Dagger_Throw.h"
#include"Ninja.h"

int FlipX=1;
Dagger_Throw::Dagger_Throw()
{
	isFinished = true;
	LoadAni();
	this->lastAttach = GetTickCount();
}


Dagger_Throw::~Dagger_Throw()
{
}

void Dagger_Throw::Attach(float Hx, float Hy, int HDirection)
{
	DWORD now = GetTickCount();
	if (!isFinished||now-lastAttach<Dagger_Delay_Between_Shoots)
	{
		return;
	}
	this->lastAttach = now;
	isFinished = false;
	this->Health = 1;
	ModifyPositionFitHost(Hx, Hy, HDirection);
	vy = -Dagger_Throw_Start_SpeedY;
	float xNinja,yNinja;
	Ninja::GetInstance()->GetPosition(xNinja, yNinja);
	this->vx = (xNinja - this->x) / (60 * dt);
}

void Dagger_Throw::Render()
{
	if (this->Health == 0)
	{
		return;
	}
	CSprites * sprites = CSprites::GetInstance();
	FlipX *= -1;
	animations[0]->Render(this->x+ Dagger_Throw_To_Center_X, this->y+ Dagger_Throw_To_Center_Y, 0, FlipX, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(Dagger_Throw_To_Center_X, Dagger_Throw_To_Center_Y);
	}
}

void Dagger_Throw::Update(DWORD dt)
{
	CGameObject::Update(dt);
	vy += Dagger_Throw_Gravity * dt;
	if (!CheckOutOfCamera())
	{
		isFinished = true;
		return;
	}
	x += dx;
	y += dy;
	CheckCollision();
}

void Dagger_Throw::ModifyPositionFitHost(float x, float y, int Direction)
{
	if (Direction == 1)
	{
		this->x = x + 26;
		this->y = y + 10;
	}
	else
	{
		this->x = x;
		this->y = y + 10;
	}
}

void Dagger_Throw::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);
	
	// di chuyen bt
	sprites->Add(11, 526, 9, 535, 24, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(50);
	ani->Add(11);
	animations->Add(11, ani);
	AddAnimation(11);
}

void Dagger_Throw::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x;
	top = this->y;
	right = left + 8;
	bottom = top + 14;
}

void Dagger_Throw::CheckCollision()
{
	if (AABBcollision(Ninja::GetInstance()))
	{
		if (Ninja::GetInstance()->getUntouchable())
		{
			return;
		}
		Ninja::GetInstance()->SubHealth(1);
		Ninja::GetInstance()->SetState(NINJA_STATE_BEING_HURT);
		Ninja::GetInstance()->StartUntouchable();
		this->Health = 0;
		isFinished = true;
	}

}
