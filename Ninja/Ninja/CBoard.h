#pragma once
#include"Sprite.h"
#include"define.h"
#include"Font.h"
#include"CBoardHealth.h"
#include"Ninja.h"
#include"SceneManager.h"
#include<iostream>
#include <iomanip>
#include <string>
#include"ItemRedShuriken.h"
#include"ItemBlueShuriken.h"
#include"Timer.h"
#include"Boss.h"
using namespace std;
#define CBOARD_TO_CENTER_X 166
#define CBOARD_TO_CENTER_Y 16

class CBoard
{
	static CBoard * _instance;
	Font *mFont;
	CBoardHealth *mCBoardHealth;

	int BossHealth;
	int Score;
	int nNinjaLife;
	int nNinjaHealth;
	int remainingTime;
	eType NinjaExtraWeaponType;
	int Spirit;//Dan

	string FillNumber(string s, UINT MaxNumber);
	int x, y;
public:
	CBoard();
	void Render();
	void Update();
	void LoadAni();
	void SetBossHealth(int health);
	static CBoard * GetInstance();
	~CBoard();
};

