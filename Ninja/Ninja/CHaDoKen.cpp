#include "CHaDoKen.h"
#include"Ninja.h"
#include"Sound.h"

CHaDoKen::CHaDoKen()
{
	isFinished = true;
	this->vx = 0.2f;
	this->vy = -0.1;
	isChange = false;
	TimeChangeImage = 0;
	TimeLast = 0;
	LoadAni();
	this->type = eType::Hadoken;
	R = 5;
}


CHaDoKen::~CHaDoKen()
{
}

void CHaDoKen::Attach()
{
	if (isFinished == false)
	{
		return;
	}
	Ninja::GetInstance()->GetPosition(this->x, this->y);
	this->SetDirection(Ninja::GetInstance()->GetDirection());
	isFinished = false;
	this->Health = 1;
	ModifyPositionFitHost();
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	Sound::GetInstance()->Play(eSound::sound_Hadoken);
}

void CHaDoKen::Render()
{
	if (this->Health == 0)
	{
		return;
	}
	CSprites * sprites = CSprites::GetInstance();
	float xC1, yC1, xC2, yC2, xC3, yC3;//Toa Do Cac Cum
	//cum 1
	xC1 = this->x + 10;
	yC1 = isChange ? this->y + 10 : this->y + 10 + R;
	//Cum 2
	yC2 = isChange ? (yC1 + 0.75*R) : (yC1 - 0.75*R);
	xC2 = xC1 - (sqrt(3) / 4)*R;
	//Cum 3
	xC3 = xC1 + (sqrt(3) / 4)*R;;
	yC3 = isChange ? (yC1 + 0.75*R) : (yC1 - 0.75*R);

	//257
	//Cum 1
	float xS1, yS1, xS2, yS2, xS3, yS3;
	CalSingleFlame(xC1, yC1, this->R, !isChange, xS1, yS1, xS2, yS2, xS3, yS3);
	//DebugOut(L"xS1, yS1, xS2, yS2, xS3, yS3: %f,%f,%f,%f,%f,%f\n", xS1, yS1, xS2, yS2, xS3, yS3);
	sprites->Get(257)->Draw(xS1 + Hadoken_To_Center_X, yS1 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	sprites->Get(257)->Draw(xS2 + Hadoken_To_Center_X, yS2 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	sprites->Get(257)->Draw(xS3 + Hadoken_To_Center_X, yS3 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	//Cum 2
	CalSingleFlame(xC2, yC2, this->R, !isChange, xS1, yS1, xS2, yS2, xS3, yS3);
	//DebugOut(L"xS1, yS1, xS2, yS2, xS3, yS3: %f,%f,%f,%f,%f,%f\n", xS1, yS1, xS2, yS2, xS3, yS3);
	sprites->Get(257)->Draw(xS1 + Hadoken_To_Center_X, yS1 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	sprites->Get(257)->Draw(xS2 + Hadoken_To_Center_X, yS2 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	sprites->Get(257)->Draw(xS3 + Hadoken_To_Center_X, yS3 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	//Cum 3
	CalSingleFlame(xC3, yC3, this->R, !isChange, xS1, yS1, xS2, yS2, xS3, yS3);
	//DebugOut(L"xS1, yS1, xS2, yS2, xS3, yS3: %f,%f,%f,%f,%f,%f\n\n", xS1, yS1, xS2, yS2, xS3, yS3);
	sprites->Get(257)->Draw(xS1 + Hadoken_To_Center_X, yS1 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	sprites->Get(257)->Draw(xS2 + Hadoken_To_Center_X, yS2 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	sprites->Get(257)->Draw(xS3 + Hadoken_To_Center_X, yS3 + Hadoken_To_Center_X, this->nx, CCamera::GetInstance()->Tranform());
	
	
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(0.5*R+5, 0.5*R + 5);
	}
}

void CHaDoKen::CalSingleFlame(float xHost, float yHost, float R, bool isChange, float & xS1, float & yS1, float & xS2, float & yS2, float & xS3, float & yS3)
{
	R = R*0.35;
	//cum 1
	xS1 = xHost + 5;
	yS1 = isChange ? yHost + 5 : yHost + 5 + R;
	//Cum 2
	yS2 = isChange ? yS1 + 0.75*R : yS1 - 0.75*R;
	xS2 = xS1 - (sqrt(3) / 4)*R;
	//Cum 3
	xS3 = xS1 + (sqrt(3) / 4)*R;;
	yS3 = isChange ? yS1 + 0.75*R : yS1 - 0.75*R;
}

void CHaDoKen::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	TimeChangeImage += dt;
	TimeLast += dt;
	if (TimeChangeImage >= TimeChange_Image)
	{
		this->isChange = !isChange;
		TimeChangeImage = 0;
	}
	R = 10 * TimeLast / 100;
	if (R < 30)
	{
		R = 30;
	}
	if (TimeLast >= Time_Last)
	{
		this->isFinished = true;
		TimeLast = 0;
	}

	CGameObject::Update(dt);
	x += dx;
	y += dy;
	CheckCollision(coObjects);
}

void CHaDoKen::ModifyPositionFitHost()
{
	this->y -= 20;
}

void CHaDoKen::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NINJA);
	// di chuyen bt
	sprites->Add(257, 300, 90, 308, 110, tex);
}

void CHaDoKen::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x-(R*0.5f-10);
	top = this->y;
	right = this->x + 10 + R;
	bottom = top + 1.5f*R + 10;
}

void CHaDoKen::CheckCollision(vector<LPGAMEOBJECT>* coObjects)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	vector<LPGAMEOBJECT> list_Enemy;
	list_Enemy.clear();
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (coObjects->at(i)->GetType() != eType::BRICK)
			list_Enemy.push_back(coObjects->at(i));

	}


	for (UINT i = 0; i < list_Enemy.size(); i++)
	{

		if (AABBcollision(list_Enemy.at(i)) && list_Enemy.at(i)->GetHealth() != 0)
		{
			list_Enemy[i]->SubHealth(2);
			Sound::GetInstance()->Play(eSound::sound_Enemy_Die);
		}
	}
	CheckCollisEnemyWeapon();
}

