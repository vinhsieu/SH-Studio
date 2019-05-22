#pragma once
#include "CWeapon.h"
#include"Texture.h"

#define CBLUESHURIKEN_TO_CENTER_X 5
#define CBLUESHURIKEN_TO_CENTER_Y 4
#define CBLUESHURIKEN_SPEED 0.5f
class CBlueShuriken :
	public CWeapon
{
public:
	CBlueShuriken();
	~CBlueShuriken();


	void Attach();
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void ModifyPositionFitNinja();
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollision(vector<LPGAMEOBJECT>* coObjects);
};

