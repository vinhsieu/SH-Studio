#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class Stairs :
	public CGameObject
{
public:
	Stairs(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~Stairs();
};

