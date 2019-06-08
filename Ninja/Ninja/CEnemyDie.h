#pragma once
#include"Texture.h"
#include"Sprite.h"

#define CEnemyDie_Effect_Die_Speed 0.1f
#define CEnemyDie_Effect_Die_TimeLast 160
#define CEnemy_RegularDie_To_Center_X 10
#define CEnemy_RegularDie_To_Center_Y 7
#define CEnemyDie_Effect_BossDie_TimeLast 80

class CEnemyDie
{
	int typeBoss;
	int firstimage;//Hinh dau hoac la doi goc voi boss

	DWORD TimeEarn;
	float x;
	float y;
	float xOp;
	float yOp;
	bool isFinish;
	
	DWORD ActiveTime;
public:
	CEnemyDie(float xHost, float yHost, int WidthHost, int HightHost,int typeBoss);//type Boss: 0 la linh thuong, 1 la boss
	~CEnemyDie();
	void Render();
	void Update(DWORD dt);
	void LoadAni();


	bool GetIsFinish();
	void SetIsFinish(bool b);
};

