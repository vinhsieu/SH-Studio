#pragma once
#include"Texture.h"
#include"Sprite.h"

#define CEnemyDie_Effect_Die_Speed 0.1f
#define CEnemyDie_Effect_Die_TimeLast 160
class CEnemyDie
{
	//GSprite * _sprite;
	float x;
	float y;
	float xOp;
	float yOp;
	bool isFinish;
	DWORD ActiveTime;
public:
	CEnemyDie(float xHost, float yHost, int WidthHost, int HightHost);
	~CEnemyDie();
	void Render();
	void Update(DWORD dt);
	void LoadAni();


	bool GetIsFinish();
	void SetIsFinish(bool b);
};

