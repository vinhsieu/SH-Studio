#pragma once

#include "Scene.h"
#include"define.h"
class SceneManager 
{
	static SceneManager * _instance;
	int State;
	Scene * _scene;

public:
	SceneManager();
	~SceneManager();
	static SceneManager * GetInstance();
	void SetScene(Scene * x);
	int getState();
	void SetStateSituation(int);
	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	void LoadResources();
	void Update(DWORD dt);
	void Render();
};

