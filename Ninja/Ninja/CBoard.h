#pragma once
#include"Sprite.h"
#include"Camera.h"
#include"Texture.h"
#define CBOARD_TO_CENTER_X 166
#define CBOARD_TO_CENTER_Y 16
class CBoard
{
	static CBoard * _instance;
	int Score;
	LPDIRECT3DSURFACE9 board;
	int nNinjaLife;
	int x, y;
public:
	CBoard();
	void Render();
	void Update();
	void LoadAni();
	static CBoard * GetInstance();
	~CBoard();
};

