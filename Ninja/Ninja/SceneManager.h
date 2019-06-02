#pragma once

#include "Scene.h"
#include"define.h"
class SceneManager 
{
	static SceneManager * _instance;

	Scene * _scene;
public:
	SceneManager();
	~SceneManager();
	static SceneManager * GetInstance();
	void SetScene(Scene * x);

	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	void LoadResources();
	void Update(DWORD dt);
	void Render();
};

