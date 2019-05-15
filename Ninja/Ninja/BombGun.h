#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"

#define BOMGUN_TO_CENTERX 10
#define BOMGUN_TO_CENTERY 13
class CBombGun :
	public CGameObject
{
public:
	CBombGun(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~CBombGun();
};

