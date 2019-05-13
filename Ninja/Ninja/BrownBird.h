#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class BrownBird :
	public CGameObject
{
public:
	BrownBird(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~BrownBird();
};

