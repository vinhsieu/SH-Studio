#include "CWeapon.h"
#include"Sound.h"


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

void CWeapon::ModifyPositionFitHost()
{
}

void CWeapon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}

void CWeapon::CheckCollision(vector<LPGAMEOBJECT>* coObjects)
{

	//vector<LPCOLLISIONEVENT> coEvents;
	//vector<LPCOLLISIONEVENT> coEventsResult;

	//coEvents.clear();

	vector<LPGAMEOBJECT> list_Enemy;
	list_Enemy.clear();
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (coObjects->at(i)->GetType() != eType::BRICK)
		{
				list_Enemy.push_back(coObjects->at(i));
		}
	}


	for (UINT i = 0; i < list_Enemy.size(); i++)
	{
		if (AABBcollision(list_Enemy.at(i))&& list_Enemy.at(i)->GetHealth()!=0)
		{
			if (list_Enemy.at(i)->GetType() != eType::BOSS)
			{
				list_Enemy[i]->SubHealth(2);
				Sound::GetInstance()->Play(eSound::sound_Enemy_Die);
				Ninja::GetInstance()->plusPoint(100);
			}
			else
			{
				list_Enemy[i]->SubHealth(1);
				this->isFinished = true;
			}
			//return;
			//DebugOut(L"co va cham\n");
		}
	}
	CheckCollisEnemyWeapon();
}

void CWeapon::CheckCollisEnemyWeapon()
{
	vector<CWeapon *>listEnemyWeapon;
	Grid::GetInstance()->GetListBullet(listEnemyWeapon);
	for (auto x : listEnemyWeapon)
	{
		if (!x->GetisFinished() && AABBcollision(x))
		{
			x->setIsFinished(true);
			x->SubHealth(1);
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

bool CWeapon::GetisFinished()
{
	return isFinished;
}

void CWeapon::setIsFinished(bool isFinished)
{
	this->isFinished = isFinished;
}

void CWeapon::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y, 2 * 2, 3 * 2);
	}
	CGameObject::SubHealth(th);
}



