#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class CFootballguy :
	public CGameObject
{
public:
	CFootballguy(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~CFootballguy();
};

