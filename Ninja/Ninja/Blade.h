#pragma once
#include"CGameObject.h"
#include"define.h"
#include"Texture.h"

#define BLADE_TO_CENTERX 11
#define BLADE_TO_CENTERY 17
#define BLADE_VX 0.2f
class CBlade:public CGameObject
{
public:
	CBlade(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~CBlade();
};

