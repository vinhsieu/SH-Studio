#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
class CPanther :
	public CGameObject
{
public:
	CPanther(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~CPanther();
};
