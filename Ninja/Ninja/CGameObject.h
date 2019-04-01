#pragma once
#include<d3dx9.h>
#include<d3d9.h>
#include"CGame.h"
#include"Sprite.h"
#include<vector>

class CGameObject
{
protected:
	float x;
	float y;

	float vx;
	float vy;

	int isLeft;

	int nx;
	//int isAttach;
	int currentState;

	 static vector<LPANIMATION> animations;
	
public:
	void SetState(int state) { this->currentState = state; }
	static void AddAnimation(int aniId);



	CGameObject();
	void Update(DWORD);
	void Render();
	void SetPosition(float x, float y);
	void SetSpeed(float vx, float vy);
	int GetState() { return currentState; };
	~CGameObject();
};

