#include "CWeapon.h"



CWeapon::CWeapon()
{
	isFinished = true;
}


CWeapon::~CWeapon()
{
}

void CWeapon::Attach()
{
	isFinished = false;
	lastAttach = GetTickCount();
}

void CWeapon::ModifyPositionFitNinja()
{
}

void CWeapon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}

void CWeapon::CheckCollision(vector<LPGAMEOBJECT>* coObjects)
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

		if (AABBcollision(list_Enemy.at(i)))
		{
			list_Enemy[i]->SubHealth(2);
			//return;
			//DebugOut(L"co va cham\n");
		}
	}

}

bool CWeapon::CheckOutOfCamera()
{
	RECT camera=CCamera::GetInstance()->GetBound();
	RECT weapon;
	float left, top, right, bottom;
	GetBoundingBox(left, top, right, bottom);
	weapon.left = left;
	weapon.top = top;
	weapon.right = right;
	weapon.bottom = bottom;

	return CGame::GetInstance()->isContain(camera,weapon);
}

bool CWeapon::GetisAttaching()
{
	return isFinished;
}

