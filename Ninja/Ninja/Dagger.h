#pragma once
#include"CGameObject.h"
#include"define.h"
#include"Texture.h"

#define DAGGER_SPEED_X 0.01f
#define DAGGER_SPEED_Y 0.01f

#define ANI_DAGGER_NOTATT 1000
#define ANI_DAGGER_ATT 1001

class CDagger : public CGameObject
{
public:
	CDagger(float x, float y, int Direction);
	void LoadAni();
	void Render();
	void Update(DWORD dt);
	~CDagger();
};

