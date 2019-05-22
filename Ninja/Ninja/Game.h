#pragma once
#include"Ninja.h"
#include"Camera.h"
#include"CGame.h"
#include"CGameObject.h"
#include"GameMap.h"
#include"Texture.h"
#include"Sprite.h"
#include "KeyBoard.h"
#include"Dagger.h"
#include"Brick.h"
#include"Grid.h"

class Game
{
	CGame * Cgame;
	Ninja * ninja;
	GameMap *gamemap;
	CKeyHandler * keyboard;
	Grid *mGrid;
	CCamera * mCamera = CCamera::GetInstance();
	vector<LPGAMEOBJECT> objStatic;
	vector<LPGAMEOBJECT> objDynamic;
	vector<LPGAMEOBJECT> obj;
public:
	
	Game();
	void GameInit(HWND);
	void LoadResources();
	void Render();
	void Update(DWORD dt);
	int Run();
	~Game();
};

