#pragma once
#include "CWeapon.h"
#include"Texture.h"

#define CBLUESHURIKEN_TO_CENTER_X 5
#define CBLUESHURIKEN_TO_CENTER_Y 4
#define CBLUESHURIKEN_SPEED 0.3f
class CBlueShuriken :
	public CWeapon
{
	bool isAllowAttackBoss;
public:
	CBlueShuriken();
	~CBlueShuriken();


	void Attach();
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void ModifyPositionFitHost();
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollision(vector<LPGAMEOBJECT>* coObjects);
};

