#include "BombGun_Fired.h"
#include"Ninja.h"
#include"Sound.h"
bool FirstAni;
BombGun_Fired::BombGun_Fired()
{
	isFinished = true;
	FirstAni = true;
	this->vx = 0.2f;
	lastTimeAttach = GetTickCount();
	LoadAni();
}


BombGun_Fired::~BombGun_Fired()
{
}

void BombGun_Fired::Attach(float Hx, float Hy, int HDirection)
{
	DWORD now = GetTickCount();
	if (!isFinished || now-lastTimeAttach<BomGun_Fired_Delay_Shoot)
	{
		return;
	}

	Sound::GetInstance()->Play(eSound::sound_BombGun_Attack);
	lastTimeAttach = now;
	isFinished = false;
	this->Health = 1;
	ModifyPositionFitHost(Hx, Hy, HDirection);
	FirstAni = true;
}

void BombGun_Fired::Render()
{
	if (this->Health == 0)
	{
		return;
	}
	CSprites * sprites = CSprites::GetInstance();
	if (FirstAni)
	{
		sprites->Get(21)->Draw(this->x+ BombGun_Fired_To_Center_X, this->y+ BombGun_Fired_To_Center_Y, this->nx, CCamera::GetInstance()->Tranform());
		FirstAni = false;
	}
	else
	{
		sprites->Get(22)->Draw(this->x+ BombGun_Fired_To_Center_X, this->y+ BombGun_Fired_To_Center_Y, this->nx, CCamera::GetInstance()->Tranform());
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BombGun_Fired_To_Center_X, BombGun_Fired_To_Center_Y);
	}
}

void BombGun_Fired::Update(DWORD dt)
{
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	CGameObject::Update(dt);
	if (!CheckOutOfCamera())
	{
		isFinished = true;
		FirstAni = true;
		return;
	}
	x += dx;
	//y += dy;
	CheckCollision();
}

void BombGun_Fired::ModifyPositionFitHost(float x, float y, int Direction)
{
	if (Direction == 1)
	{
		this->x = x + 26;
		this->y = y + 3;
	}
	else
	{
		this->x = x;
		this->y = y + 3;
	}
	this->nx = Direction;
}

void BombGun_Fired::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	// di chuyen bt
	sprites->Add(21, 446, 64, 456, 80, tex);
	sprites->Add(22, 463, 70, 471, 74, tex);
	//LPANIMATION ani;
	////Di Binh Thuong
	//ani = new CAnimation(50);
	//ani->Add(11);
	//animations->Add(11, ani);
	//AddAnimation(11);
}

void BombGun_Fired::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x;
	top = this->y;
	right = left + 8;
	bottom = top + 4;
}

void BombGun_Fired::CheckCollision()
{
	if (AABBcollision(Ninja::GetInstance()))
	{
		Ninja::GetInstance()->SubHealth(1);
		Ninja::GetInstance()->SetState(NINJA_STATE_BEING_HURT);
		Ninja::GetInstance()->StartUntouchable();
		this->Health = 0;
		isFinished = true;
		FirstAni = true;
	}
}
