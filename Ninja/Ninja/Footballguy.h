#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class Footballguy :
	public CGameObject
{
public:
	Footballguy(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~Footballguy();
};

