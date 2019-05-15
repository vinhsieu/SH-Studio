#pragma once
#include "CGameObject.h"
#include"define.h"
#include"Texture.h"
#define BROWNBIRD_TO_CENTERX 9
#define BROWNBIRD_TO_CENTERY 7
class CBrownBird :
	public CGameObject
{
public:
	CBrownBird(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~CBrownBird();
};

