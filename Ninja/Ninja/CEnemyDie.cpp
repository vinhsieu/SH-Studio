#include "CEnemyDie.h"
#include"Sprite.h"
#include"Camera.h"


int firstimage = 1;
CEnemyDie::CEnemyDie(float xHost, float yHost,int WidthHost,int HightHost)
{
	isFinish = false;
	this->x = xHost + WidthHost / 2 - 5;
	this->y = yHost + HightHost / 2 - 5;
	this->xOp = x;
	this->yOp = y;
	this->ActiveTime = GetTickCount();
	LoadAni();
}


CEnemyDie::~CEnemyDie()
{
}

void CEnemyDie::Render()
{
	CSprites *sprites = CSprites::GetInstance();
	if (firstimage)
	{
		sprites->Get(100)->Draw(x, y, 0, CCamera::GetInstance()->Tranform());
		firstimage = 0;
	}
	else
	{
		sprites->Get(101)->Draw(x, yOp, 0, CCamera::GetInstance()->Tranform());//tren trai
		sprites->Get(101)->Draw(xOp, yOp, -1, CCamera::GetInstance()->Tranform());//Tren phai
		sprites->Get(102)->Draw(x, y, 0, CCamera::GetInstance()->Tranform());//Duoi trai
		sprites->Get(102)->Draw(xOp, y, -1, CCamera::GetInstance()->Tranform());//Duoi phai
	}
}

void CEnemyDie::Update(DWORD dt)
{
	DWORD now = GetTickCount();
	if (now - ActiveTime < CEnemyDie_Effect_Die_TimeLast)
	{
		x -= CEnemyDie_Effect_Die_Speed * dt;// Hinh tren trai
		xOp += CEnemyDie_Effect_Die_Speed * dt;// Hinh tren phai
		y += CEnemyDie_Effect_Die_Speed * dt;
		yOp -= CEnemyDie_Effect_Die_Speed * dt;;
	}
	else
	{
		this->isFinish = true;
	}
}

void CEnemyDie::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);

	sprites->Add(100, 358, 94, 374, 110, tex);
	sprites->Add(101, 317, 83, 327, 98, tex);//tren
	sprites->Add(102, 317, 106, 327, 121, tex);// duoi


	
}

bool CEnemyDie::GetIsFinish()
{
	return this->isFinish;
}

void CEnemyDie::SetIsFinish(bool b)
{
}
