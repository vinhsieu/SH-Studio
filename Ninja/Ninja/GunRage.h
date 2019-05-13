#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class GunRage :
	public CGameObject
{
public:
	GunRage(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~GunRage();
};

