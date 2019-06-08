#pragma once
#include "Scene.h"
#include"SceneManager.h"
#include"Scene_Game.h"
#include"Font.h"
#include"Sprite.h"
#include"Texture.h"

class Scene_End :
	public Scene
{
	bool isPressedKey;
	DWORD TimeBling;

	DWORD TimeBetweenBling;
	Font *mFont;
	bool isDrawStartFont;
public:
	Scene_End();
	~Scene_End();
	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	void LoadResources();
	void Update(DWORD dt);
	void Render();
};

