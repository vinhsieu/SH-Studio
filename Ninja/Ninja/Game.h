#pragma once
#include"Ninja.h"
#include"Camera.h"
#include"CGame.h"
#include"CGameObject.h"
#include"GameMap.h"
#include"Texture.h"
#include"Sprite.h"
#include "KeyBoard.h"
#include"Sound.h"
#include"Grid.h"
#include"EffectManager.h"
#include"ItemsManager.h"
class Game
{
	EffectManager *listEffect;
	CGame * Cgame;
	Ninja * ninja;
	GameMap *gamemap;
	CKeyHandler * keyboard;
	Grid *mGrid;
	ItemsManager * listItem;
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

