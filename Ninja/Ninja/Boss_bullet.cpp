#include "Boss_bullet.h"
#include"Ninja.h"


Boss_bullet::Boss_bullet()
{
	isFinished = true;
	this->vx = 0.1f;

	LoadAni();
}


Boss_bullet::~Boss_bullet()
{
}

void Boss_bullet::Attach(float Hx, float Hy, int HDirection)
{
	if (!isFinished)
	{
		return;
	}

	//Sound::GetInstance()->Play(eSound::sound_GunRage_Attack);
	isFinished = false;
	this->Health = 1;
	ModifyPositionFitHost(Hx, Hy, HDirection);
}

void Boss_bullet::Render()
{
	if (this->Health == 0)
	{
		return;
	}
	CSprites * sprites = CSprites::GetInstance();

	sprites->Get(402)->Draw(this->x + Boss_bullet_To_Center_X, this->y + Boss_bullet_To_Center_Y, this->nx, CCamera::GetInstance()->Tranform());

	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(Boss_bullet_To_Center_X, Boss_bullet_To_Center_Y);
	}
}

void Boss_bullet::Update(DWORD dt)
{
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	CGameObject::Update(dt);
	if (!CheckOutOfCamera())
	{
		isFinished = true;
		return;
	}
	x += dx;
	//y += dy;
	CheckCollision();
}

void Boss_bullet::ModifyPositionFitHost(float x, float y, int Direction)
{
	if (Direction == 1)
	{
		this->x = x + 26;
		this->y = y + 6;
	}
	else
	{
		this->x = x;
		this->y = y + 6;
	}
	this->nx = -Direction;
}

void Boss_bullet::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	// di chuyen bt
	sprites->Add(402, 443, 273, 448, 278, tex);
}

void Boss_bullet::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x;
	top = this->y;
	right = left + 5;
	bottom = top + 5;
}

void Boss_bullet::CheckCollision()
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
