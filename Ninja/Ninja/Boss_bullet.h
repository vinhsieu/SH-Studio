#pragma once
#include "CWeapon.h"
#define Boss_bullet_To_Center_X 2.5
#define Boss_bullet_To_Center_Y 2.5
class Boss_bullet :
	public CWeapon
{
public:
	Boss_bullet();
	~Boss_bullet();

	void Attach(float x, float y, int Direction);
	void Render();
	void Update(DWORD dt);
	void ModifyPositionFitHost(float x, float y, int Direction);
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollision();
};

