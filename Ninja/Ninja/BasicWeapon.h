#pragma once
#include "CWeapon.h"
//#include"Ninja.h"

#define BASIC_WEAPON_TIME 300
#define BASIC_WEAPON_TO_CENTER_Y 4
#define BASIC_WEAPON_TO_CENTER_X 8
class CBasicWeapon :
	public CWeapon
{
	
public:
	CBasicWeapon();
	~CBasicWeapon();
	void Attach();
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void ModifyPositionFitNinja();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	

	
};

