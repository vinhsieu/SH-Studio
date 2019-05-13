#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class Panther :
	public CGameObject
{
public:
	Panther(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~Panther();
};

