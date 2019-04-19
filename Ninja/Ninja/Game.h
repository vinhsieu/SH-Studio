#pragma once
#include"Ninja.h"
#include"Camera.h"
#include"CGame.h"
#include"CGameObject.h"
#include"GameMap.h"
#include"Texture.h"
#include"Sprite.h"
#include "KeyBoard.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define MAX_FRAME_RATE 30
#define WINDOW_CLASS_NAME L"BT1"
#define MAIN_WINDOW_TITLE L"BT1"
#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 100)
#define ID_TEX_NINJA 0
#define ID_TEX_BACKGROUND 1

class Game
{
	CGame * Cgame;
	Ninja * ninja;
	Camera *mCamera;
	GameMap *gamemap;
	CKeyHandler * keyboard;
public:
	
	Game();
	void GameInit(HWND);
	void LoadResources();
	void Render();
	void Update(DWORD dt);
	int Run();
	~Game();
};

