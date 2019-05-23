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
	bool CheckOutOfCamera();
	bool GetisFinished();
	
};

