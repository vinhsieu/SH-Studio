#pragma once
#include "CWeapon.h"
#include "Texture.h"

#define BombGun_Fired_To_Center_X 4
#define BombGun_Fired_To_Center_Y 2
#define BomGun_Fired_Delay_Shoot 2000
class BombGun_Fired :
	public CWeapon
{
	DWORD lastTimeAttach;
public:
	BombGun_Fired();
	~BombGun_Fired();

	void Attach(float x, float y, int Direction);
	void Render();
	void Update(DWORD dt);
	void ModifyPositionFitHost(float x, float y, int Direction);
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollision();
};

