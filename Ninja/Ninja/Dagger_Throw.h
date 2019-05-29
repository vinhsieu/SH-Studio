#pragma once
#include "CWeapon.h"
#include"Texture.h"

#define Dagger_Throw_Gravity 0.002f
#define Dagger_Throw_Start_SpeedY 0.3f
#define Dagger_Throw_To_Center_X 4
#define Dagger_Throw_To_Center_Y 7
#define Dagger_Delay_Between_Shoots 1000

class Dagger_Throw :
	public CWeapon
{
	
public:
	Dagger_Throw();
	~Dagger_Throw();

	void Attach(float x,float y,int Direction);
	void Render();
	void Update(DWORD dt);
	void ModifyPositionFitHost(float x, float y, int Direction);
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollision();
};

