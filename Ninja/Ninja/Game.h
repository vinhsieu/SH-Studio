#pragma once

#include"CGame.h"
#include"SceneManager.h"
#include"Scene_Game.h"
#include"KeyBoard.h"
#include"Game_Over.h"
#include"Scene_Intro.h"
#include"Scene_End.h"
class Game
{
	SceneManager *mSceneManager;

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

