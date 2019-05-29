#include "BasicWeapon.h"
#include"Ninja.h"
#include"Sound.h"

CBasicWeapon::CBasicWeapon()
{
	isFinished = true;
}


CBasicWeapon::~CBasicWeapon()
{
}

void CBasicWeapon::Attach()
{
	isFinished = false;
	lastAttach = GetTickCount();
	Sound::GetInstance()->Play(eSound::sound_Normal_Attack);
}

void CBasicWeapon::Render()
{
	CGameObject::Render();
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BASIC_WEAPON_TO_CENTER_X, BASIC_WEAPON_TO_CENTER_Y);
	}
}

//bool CBasicWeapon::GetisFinished()
//{
//	DebugOut(L"isFinished: %d\n", isFinished);
//	return isFinished;
//	
//}

void CBasicWeapon::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x;
	top = this->y;
	right = left + 16;
	bottom = top + 8;
}

void CBasicWeapon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	CGameObject::Update(dt);
	Ninja::GetInstance()->GetPosition(this->x,this->y);
	this->SetDirection(Ninja::GetInstance()->GetDirection());
	ModifyPositionFitNinja();

	CheckCollision(coObjects);
	DWORD now = GetTickCount();
	
	if (now - lastAttach > BASIC_WEAPON_TIME)
	{
		isFinished = true;
	}
	

}

void CBasicWeapon::ModifyPositionFitNinja()
{
	if (this->nx==1)
	{
		this->x = this->x + 20;
		this->y = this->y + 3;
	}
	else
	{
		this->x = this->x - 20;
		this->y = this->y + 3;
	}
	
}
