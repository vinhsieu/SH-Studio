#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"

#define FOOTBALLGUY_TO_CENTERX 8
#define FOOTBALLGUY_TO_CENTERY 16
#define FOOTBALLGUY_JUMP_SPEED_Y 0.6f


class CFootballguy :
	public CGameObject
{
	bool isActive;
	bool isJumping;
public:
	CFootballguy(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void SubHealth(int th);
	void CheckCollisionWithBrick();

	void SetDefault();
	~CFootballguy();
};

