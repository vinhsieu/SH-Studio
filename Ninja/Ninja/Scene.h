#pragma once
#include"CGame.h"
#include"define.h"

#define NORMAL 0
#define Ninja_Die 1
#define Ninja_Out_Of_Life 2 // Gameover


class Scene
{
protected:
	int State;// Dang o Scene nao
	int StateSituation;// Su kien xay ra trong Scene
public:
	Scene();
	virtual void KeyState(BYTE *state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
	int getState();
	virtual void SetStateSituation(int statesituation);
	virtual void LoadResources() = 0;
	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0;
	~Scene();
};

