#pragma once
#include "CGameObject.h"
#include"define.h"

#define PANTHER_TO_CENTEX 14
#define PANTHER_TO_CENTEY 9
#define PANTHER_ACTIVE_AREA (SCREEN_WIDTH-30)/2
#define PANTHER_VX 0.12;
class CPanther :
	public CGameObject
{
	bool isActive;
	bool isJumping;
public:
	CPanther(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void SubHealth(int th);
	void CheckCollisionWithBrick();
	void SetDefault();
	~CPanther();
};

