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
	virtual void ModifyPositionFitNinja();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void CheckCollision(vector<LPGAMEOBJECT>* coObjects);
	bool CheckOutOfCamera();
	bool GetisAttaching();
	
};

