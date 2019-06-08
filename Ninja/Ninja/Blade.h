#pragma once
#include"CGameObject.h"
#include"define.h"
#include"Texture.h"

#define BLADE_TO_CENTERX 9
#define BLADE_TO_CENTERY 17
#define BLADE_VX 0.04f
#define BLADE_ACTIVE_AREA (SCREEN_WIDTH-30)/2
class CBlade:public CGameObject
{
	bool isActive;
public:
	CBlade(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckCollisionWithBrick();
	void SubHealth(int th);
	void SetDefault();
	~CBlade();
};

