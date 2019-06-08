#include "CEnemyDie.h"
#include"Sprite.h"
#include"Camera.h"



CEnemyDie::CEnemyDie(float xHost, float yHost,int WidthHost,int HightHost,int TypeEnemy)
{
	this->firstimage = 1;
	this->typeBoss = TypeEnemy;
	this->TimeEarn = 0;
	isFinish = false;
	if (TypeEnemy==0)
	{
		this->x = xHost + WidthHost / 2 - 5;
		this->y = yHost + HightHost / 2 - 5;
		this->xOp = x;
		this->yOp = y;
	}
	else
	{
		this->x = xHost;
		this->y = yHost;
		this->xOp = xHost + WidthHost / 2 - 5;
		this->yOp = yHost + HightHost / 2 - 5;
	}
	this->ActiveTime = GetTickCount();
	LoadAni();
}


CEnemyDie::~CEnemyDie()
{
}

void CEnemyDie::Render()
{
	CSprites *sprites = CSprites::GetInstance();
	if (typeBoss == 0)
	{
		if (firstimage)
		{
			sprites->Get(100)->Draw(x, y, 0, CCamera::GetInstance()->Tranform());
			firstimage = 0;
		}
		else
		{
			sprites->Get(101)->Draw(x + CEnemy_RegularDie_To_Center_X, yOp + CEnemy_RegularDie_To_Center_Y, 0, CCamera::GetInstance()->Tranform());//tren trai
			sprites->Get(101)->Draw(xOp + CEnemy_RegularDie_To_Center_X, yOp + CEnemy_RegularDie_To_Center_Y, -1, CCamera::GetInstance()->Tranform());//Tren phai
			sprites->Get(102)->Draw(x + CEnemy_RegularDie_To_Center_X, y + CEnemy_RegularDie_To_Center_Y, 0, CCamera::GetInstance()->Tranform());//Duoi trai
			sprites->Get(102)->Draw(xOp + CEnemy_RegularDie_To_Center_X, y + CEnemy_RegularDie_To_Center_Y, -1, CCamera::GetInstance()->Tranform());//Duoi phai
		}
	}
	else
	{
		DebugOut(L"first:%d", firstimage);
		if (firstimage==1)
		{
			DebugOut(L"this\n");
			sprites->Get(103)->Draw(x, y, 0, CCamera::GetInstance()->Tranform());
			sprites->Get(103)->Draw(xOp, yOp, 0, CCamera::GetInstance()->Tranform());

		}
		else
		{
			DebugOut(L"That\n");
			sprites->Get(103)->Draw(xOp, y, 0, CCamera::GetInstance()->Tranform());
			sprites->Get(103)->Draw(x, yOp, 0, CCamera::GetInstance()->Tranform());
		}
	}
}

void CEnemyDie::Update(DWORD dt)
{
	DWORD now = GetTickCount();
	if (typeBoss == 0)
	{
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
	else
	{
		TimeEarn += dt;
		if (TimeEarn > CEnemyDie_Effect_BossDie_TimeLast)
		{
			firstimage *= -1;
			TimeEarn = 0;
		}
	}
}

void CEnemyDie::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);
	//Linh Thuong
	sprites->Add(100, 358, 94, 374, 110, tex);
	sprites->Add(101, 317, 83, 327, 98, tex);//tren
	sprites->Add(102, 317, 106, 327, 121, tex);// duoi
	//Boss

	sprites->Add(103, 384, 85, 416, 117, tex);

	
}

bool CEnemyDie::GetIsFinish()
{
	return this->isFinish;
}

void CEnemyDie::SetIsFinish(bool b)
{
}
