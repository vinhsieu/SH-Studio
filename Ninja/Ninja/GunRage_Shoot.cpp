#include "GunRage_Shoot.h"
#include"Ninja.h"
#include"Sound.h"

GunRage_Shoot::GunRage_Shoot()
{
	isFinished = true;
	this->vx = 0.1f;
	
	LoadAni();
}


GunRage_Shoot::~GunRage_Shoot()
{
}

void GunRage_Shoot::Attach(float Hx, float Hy, int HDirection)
{
	if (!isFinished)
	{
		return;
	}

	Sound::GetInstance()->Play(eSound::sound_GunRage_Attack);
	isFinished = false;
	this->Health = 1;
	ModifyPositionFitHost(Hx, Hy, HDirection);
}

void GunRage_Shoot::Render()
{
	if (this->Health == 0)
	{
		return;
	}
	CSprites * sprites = CSprites::GetInstance();
	
	sprites->Get(31)->Draw(this->x+ GunRage_Shoot_To_Center_X, this->y+ GunRage_Shoot_To_Center_Y, this->nx, CCamera::GetInstance()->Tranform());
	
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(GunRage_Shoot_To_Center_X, GunRage_Shoot_To_Center_Y);
	}
}

void GunRage_Shoot::Update(DWORD dt)
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

void GunRage_Shoot::ModifyPositionFitHost(float x, float y, int Direction)
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
	this->nx = Direction;
}

void GunRage_Shoot::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	// di chuyen bt
	sprites->Add(31, 196, 69, 204, 72, tex);

}

void GunRage_Shoot::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x;
	top = this->y;
	right = left + 8;
	bottom = top + 3;
}

void GunRage_Shoot::CheckCollision()
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
