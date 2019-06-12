#pragma once
#include "CWeapon.h"
#define Hadoken_To_Center_X 4
#define Hadoken_To_Center_Y 10
#define TimeChange_Image 56
#define Time_Last 1000
class CHaDoKen :
	public CWeapon
{
	float R;//Duong Kinh Hinh Tron Lon
	bool isChange;//Lam giong nhu xoay
	DWORD TimeChangeImage;
	DWORD TimeLast;
public:
	CHaDoKen();
	~CHaDoKen();

	void Attach();
	void Render();
	void CalSingleFlame(float xHost, float yHost, float R, bool isChange, float &xS1, float &yS1, float &xS2, float &yS2, float &xS3, float &yS3);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void ModifyPositionFitHost();
	void LoadAni();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollision(vector<LPGAMEOBJECT>* coObjects);
};

