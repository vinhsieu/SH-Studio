#pragma once
#include "Scene.h"
#include "Scene.h"
#include"SceneManager.h"
#include"Scene_Game.h"
#include"Font.h"
#include"Sprite.h"
#include"Texture.h"
//#include"Scene_Intro.h"
class Game_Over :
	public Scene
{
	int previousState;
	bool isPressedKey;
	DWORD TimeBling;

	DWORD TimeBetweenBling;
	Font *mFont;
	bool isDrawStartFont;
public:
	Game_Over(int previousState);
	~Game_Over();
	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	void LoadResources();
	void Update(DWORD dt);
	void Render();
};

