#pragma once
#include"CGameObject.h"
#include"define.h"
#include"Texture.h"

class Blade:public CGameObject
{
public:
	Blade(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~Blade();
};

