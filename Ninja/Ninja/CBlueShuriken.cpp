#include "CBlueShuriken.h"
#include"Ninja.h"
#include"Sound.h"

CBlueShuriken::CBlueShuriken()
{
	isFinished = true;
	this->type = eType::BlueShuriken;
	this->vx = CBLUESHURIKEN_SPEED;
	this->vy = 0.0f;
	LoadAni();
}


CBlueShuriken::~CBlueShuriken()
{
}

void CBlueShuriken::Attach()
{
	isFinished = false;
	//lastAttach = GetTickCount();
	this->Health = 1;
	Ninja::GetInstance()->GetPosition(this->x, this->y);
	this->SetDirection(Ninja::GetInstance()->GetDirection());

	Sound::GetInstance()->Play(eSound::sound_Blue_Shuriken);
	ModifyPositionFitHost();
}

void CBlueShuriken::Render()
{
	if (!isFinished)
	{
		animations[0]->Render(this->x+ CBLUESHURIKEN_TO_CENTER_X, this->y+ CBLUESHURIKEN_TO_CENTER_Y, 0, 1, CCamera::GetInstance()->Tranform());
		if (IS_BBOX_DEBUGGING)
		{
			RenderBoundingBox(CBLUESHURIKEN_TO_CENTER_X, CBLUESHURIKEN_TO_CENTER_Y);
		}
	}

}

void CBlueShuriken::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	//DebugOut(L"dt: %lu", dt);
	//DebugOut(L"H: %d\n", this->Health);
	if (this->Health != 0)
	{
		if (!CheckOutOfCamera())
		{
			isFinished = true;
			return;
		}
		if (nx*vx < 0)
		{
			vx *= -1;
		}
		CGameObject::Update(dt);
		
		CheckCollision(coObjects);
	}

}

void CBlueShuriken::ModifyPositionFitHost()
{
	if (this->nx == 1)
	{
		this->x = this->x + 20;
		this->y = this->y + 3;
	}
	else
	{
		this->x = this->x - 9;
		this->y = this->y + 3;
	}
}

void CBlueShuriken::LoadAni()
{
	
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);
	if (animations->Get(1500) != NULL)
	{
		return;
	}
	// di chuyen bt
	sprites->Add(10, 8, 117, 16, 124, tex);
	sprites->Add(11, 23, 117, 31, 124, tex);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10);
	ani->Add(11);
	animations->Add(1500, ani);
	this->AddAnimation(1500);
	
}

void CBlueShuriken::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x;
	top = this->y;
	right = left + 9;
	bottom = top + 7;
}

void CBlueShuriken::CheckCollision(vector<LPGAMEOBJECT>* coObjects)
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


	for (UINT i = 0; i < list_Enemy.size(); i++)
	{

		if (AABBcollision(list_Enemy.at(i))&& list_Enemy.at(i)->GetHealth()!=0)
		{
			list_Enemy[i]->SubHealth(2);
			Sound::GetInstance()->Play(eSound::sound_Enemy_Die);
			this->Health = 0;
			isFinished = true;
			return;
			
		}
	}
	CheckCollisEnemyWeapon();
	x += dx;//Update neu nhu khong co va cham
	y += dy;
}
