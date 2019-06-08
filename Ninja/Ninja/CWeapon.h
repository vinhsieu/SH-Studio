#pragma once
#include "CGameObject.h"
class CWeapon :
	public CGameObject
{
protected:
	bool isFinished;
	DWORD lastAttach;
public:
	CWeapon();
	~CWeapon();

	virtual void Attach();
	virtual void ModifyPositionFitHost();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects=NULL);
	virtual void CheckCollision(vector<LPGAMEOBJECT>* coObjects);
	virtual void CheckCollisEnemyWeapon();
	bool CheckOutOfCamera();
	bool GetisFinished();
	void setIsFinished(bool isFinished);
	void SubHealth(int th);
};

