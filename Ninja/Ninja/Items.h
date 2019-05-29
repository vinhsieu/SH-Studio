#pragma once
#include"CGameObject.h"
#define Item_GRAVITY			0.002f
class Items : public CGameObject
{
protected:
	DWORD TimeDisplayMax; // thời gian tối đa cho phép hiển thị.
	DWORD TimeDisplayed; // Thời gian đã hiển thị.

	bool isFinished;
public:
	Items();
	Items(float x, float y);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *listObj);
	virtual void Render();
	bool getIsFinished();
	~Items();
};

