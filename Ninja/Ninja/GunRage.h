#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"


#define GUNRAGE_TO_CENTERX 10
#define GUNRAGE_TO_CENTERY 15
class CGunRage :
	public CGameObject
{
public:
	CGunRage(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~CGunRage();
};

