#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
#include"BombGun_Fired.h"


#define BOMGUN_TO_CENTERX 10
#define BOMGUN_TO_CENTERY 13

#define DELTA_TIME_BETWEEN 30
#define BOMGUN_ACTIVE_WEAPON 128

class CBombGun :
	public CGameObject
{
	DWORD lastBulletAttach;
	BombGun_Fired * mWeapon;

public:
	CBombGun(int id,float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void WeaponAttach();
	void SubHealth(int th);
	~CBombGun();
};

