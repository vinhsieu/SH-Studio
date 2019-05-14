#pragma once
#include"CGameObject.h"
#include"define.h"
#include"Texture.h"

class CBlade:public CGameObject
{
public:
	CBlade(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~CBlade();
};

