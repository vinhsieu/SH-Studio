#pragma once
#include "CWeapon.h"

#define GunRage_Shoot_To_Center_X 4
#define GunRage_Shoot_To_Center_Y 2


class GunRage_Shoot :
	public CWeapon
{
public:
	GunRage_Shoot();
	~GunRage_Shoot();

	void Attach(float x, float y, int Direction);
	void Render();
	void Update(DWORD dt);
	void ModifyPositionFitHost(float x, float y, int Direction);
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollision();
};

