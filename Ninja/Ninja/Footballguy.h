#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"

#define FOOTBALLGUY_TO_CENTERX 10
#define FOOTBALLGUY_TO_CENTERY 14

class CFootballguy :
	public CGameObject
{
public:
	CFootballguy(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void SubHealth(int th);
	~CFootballguy();
};

