#include "CRedShuriken.h"
#include"Ninja.h"
#include"Sound.h"


CRedShuriken::CRedShuriken()
{
	isFinished = true;
	this->vx = CREDSHURIKEN_SPEED;
	LoadAni();
	this->type = eType::RedShuriken;
}


CRedShuriken::~CRedShuriken()
{
}

void CRedShuriken::Attach()
{
	if (isFinished == false)
	{
		return;
	}

	isFinished = false;
	lastTimeChangeDirection = GetTickCount();
	//lastAttach = GetTickCount();
	this->Health = 1;
	Ninja::GetInstance()->GetPosition(this->x, this->y);
	this->SetDirection(Ninja::GetInstance()->GetDirection());
	ModifyPositionFitHost();
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	Sound::GetInstance()->Play(eSound::sound_Red_Shuriken);
}

void CRedShuriken::Render()
{
	if (!isFinished)
	{
		animations[0]->Render(this->x + CREDSHURIKEN_TO_CENTER_X, this->y + CREDSHURIKEN_TO_CENTER_Y, 0, 1, CCamera::GetInstance()->Tranform());
		if (IS_BBOX_DEBUGGING)
		{
			RenderBoundingBox(CREDSHURIKEN_TO_CENTER_X, CREDSHURIKEN_TO_CENTER_Y);
		}
	}
}

void CRedShuriken::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->Health == 0)
	{
		return;
	}
	if (!CheckOutOfCamera())
	{
		isFinished = true;
		return;
	}
	float xNinja, yNinja;
	Ninja::GetInstance()->GetPosition(xNinja, yNinja);
	DWORD now = GetTickCount();
	if (fabs(this->x - xNinja) > 80)
	{
		this->vy = (yNinja - this->y) / (60 * dt);
		if (xNinja - this->x < 0)
		{
			vx = -1*fabs(vx);
		}
		else
		{
			vx = fabs(vx);
		}
	}
	
	CGameObject::Update(dt);
	CheckCollision(coObjects);
	
}

void CRedShuriken::ModifyPositionFitHost()
{
	if (this->nx == 1)
	{
		this->x = this->x +25;
		this->y = this->y + 3;
	}
	else
	{
		this->x = this->x - 19;
		this->y = this->y + 3;
	}
}

void CRedShuriken::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);
	// di chuyen bt
	sprites->Add(41, 44, 111, 60, 127, tex);
	sprites->Add(42, 65, 111, 81, 127, tex);

	LPANIMATION ani;
	ani = new CAnimation(50);
	ani->Add(41);
	ani->Add(42);
	animations->Add(1541, ani);
	this->AddAnimation(1541);
}

void CRedShuriken::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x;
	top = this->y;
	right = left + 16;
	bottom = top + 16;
}

void CRedShuriken::CheckCollision(vector<LPGAMEOBJECT>* coObjects)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	vector<LPGAMEOBJECT> list_Enemy;
	list_Enemy.clear();
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (coObjects->at(i)->GetType() != eType::BRICK)
			list_Enemy.push_back(coObjects->at(i));
	}
	if (AABBcollision(Ninja::GetInstance()))
	{
		isFinished = true;

		//this->vx = 0;// Update som hon Attack nen Set ve 0 de khoi Collis voi Ninja
		return;
	}

	for (UINT i = 0; i < list_Enemy.size(); i++)
	{

		if (AABBcollision(list_Enemy.at(i)) && list_Enemy.at(i)->GetHealth() != 0)
		{
			list_Enemy[i]->SubHealth(2);
			Sound::GetInstance()->Play(eSound::sound_Enemy_Die);
			//this->Health = 0;
			//this->vx = 0;// Update som hon Attack nen Set ve 0 de khoi Collis voi Ninja
			//return;

		}
	}
	CheckCollisEnemyWeapon();
	x += dx;//Update neu nhu khong co va cham
	y += dy;
}
