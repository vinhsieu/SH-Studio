#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
#include"GunRage_Shoot.h"

#define GUNRAGE_TO_CENTERX 10
#define GUNRAGE_TO_CENTERY 15
#define GUNRAGE_TIME_CHANGE_DIRECTION 300
#define TIME_BETWEEN_TWO_BULLET 200
#define TIME_DELAY_SHOOT 3000
class CGunRage :
	public CGameObject
{
	DWORD timeChangeDirection;
	DWORD lastTimeBullet;
	DWORD lastTimeShoot;
	GunRage_Shoot * mWeapon[3];
public:
	CGunRage(int id,float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void SubHealth(int th);
	~CGunRage();
};

