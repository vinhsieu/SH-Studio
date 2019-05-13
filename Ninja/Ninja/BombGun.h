#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class CBombGun :
	public CGameObject
{
public:
	CBombGun(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~CBombGun();
};

