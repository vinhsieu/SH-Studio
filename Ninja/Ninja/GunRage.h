#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class CGunRage :
	public CGameObject
{
public:
	CGunRage(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~CGunRage();
};

