#pragma once
#include "CWeapon.h"

#define CREDSHURIKEN_TO_CENTER_X 8
#define CREDSHURIKEN_TO_CENTER_Y 8
class CRedShuriken :
	public CWeapon
{
	DWORD lastTimeChangeDirection;
public:
	CRedShuriken();
	~CRedShuriken();
	void Attach();
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void ModifyPositionFitHost();
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollision(vector<LPGAMEOBJECT>* coObjects);
};

