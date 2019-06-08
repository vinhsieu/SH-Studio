#pragma once
#include"Texture.h"
#include"CGame.h"
#include"Sprite.h"
#define MAX_HEALTH 16
#define CELL_TO_CENTER_X 2.5f
#define CELL_TO_CENTER_Y 3.5f
class CBoardHealth
{
	static CBoardHealth * _instance;
public:
	CBoardHealth();
	~CBoardHealth();
	void Draw(int HealthPlayer, int HealthEnemy);
	static CBoardHealth * GetInstance();
	void LoadSprite();
};

