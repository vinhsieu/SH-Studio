#pragma once
#include "CGameObject.h"
#include"Boss_bullet.h"
#include"Grid.h"
#include"CBoard.h"
#define BOSS_TO_CENTERX 21
#define BOSS_TO_CENTERY 24
#define BOSS_JUMP_Y 0.6
#define Time_Change_Direction 1500
class Boss :
	public CGameObject
{
	//static Boss * _instance;
	Boss_bullet * mWeapon[3];
	bool isJumping;
	DWORD TimeEarned;
public:
	Boss(int id);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void SubHealth(int th);
	//static Boss * GetInstance();
	~Boss();
};

