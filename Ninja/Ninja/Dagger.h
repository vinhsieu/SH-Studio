#pragma once
#include"CGameObject.h"
#include"define.h"
#include"Texture.h"
#include"Dagger_Throw.h"


#define DAGGER_SPEED_X 0.01f
#define DAGGER_SPEED_Y 0.00f

#define ANI_DAGGER_NOTATT 1000
#define ANI_DAGGER_ATT 1001

#define DAGGER_ACTIVE_WEAPON 100

#define DAGGER_T0_CENTERX 10
#define DAGGER_T0_CENTERY 17

class CDagger : public CGameObject
{
	Dagger_Throw * mWeapon;
	int AniDirection;
public:
	CDagger(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollisionWithBrick();
	void SubHealth(int th);
	~CDagger();
};

