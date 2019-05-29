#include "GunRage.h"
#include"Ninja.h"
#include"Grid.h"

int shootAgain = 0;
bool again=false;
CGunRage::CGunRage(int id,float x, float y, int Direction)
{
	CGameObject::CGameObject();
	this->id = id;
	this->x = this->xBackup = x;
	this->y = this->yBackup = y;
	this->nx = this->nxBackup = Direction;
	this->HealthBackup = this->Health;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::GunRage;
	for (int i = 0; i < 3; i++)
	{
		mWeapon[i] = new GunRage_Shoot();
		mWeapon[i]->SetID(this->id*10 + i);
		Grid::GetInstance()->AddObj(this->id, mWeapon[i]);
	}
	lastTimeBullet = GetTickCount();
	lastTimeShoot = GetTickCount();
	LoadAni();
}

void CGunRage::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(1100, 58, 60, 74, 92, tex);
	sprites->Add(1101, 83, 60, 101, 92, tex);
	sprites->Add(1102, 127, 60, 157, 92, tex);
	sprites->Add(1103, 159, 60, 187, 92, tex);

	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(1100);
	ani->Add(1101);
	animations->Add(1061, ani);
	
	ani = new CAnimation(100);
	ani->Add(1102);
	ani->Add(1103);
	animations->Add(1062 , ani);
	AddAnimation(1061);
	AddAnimation(1062);
}

void CGunRage::Render()
{
	if (this->Health == 0)
	{
		return;
	}

	if (isAttach == -1)
	{
		this->animations.at(0)->Render(this->x+GUNRAGE_TO_CENTERX, this->y+GUNRAGE_TO_CENTERY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	}
	else
	{
		if (this->animations.at(1)->Render(this->x + GUNRAGE_TO_CENTERX, this->y + GUNRAGE_TO_CENTERY, isAttach, this->nx, CCamera::GetInstance()->Tranform()) == -1)
		{
			this->isAttach = -1;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (!mWeapon[i]->GetisFinished())
		{
			mWeapon[i]->Render();
		}
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(GUNRAGE_TO_CENTERX,GUNRAGE_TO_CENTERY);
	}
}

void CGunRage::Update(DWORD dt)
{
	if (this->Health == 0)// Het mau ko update
	{
		return;
	}
	if (nx*vx < 0)// Dieu huong van toc theo Ninja
	{
		vx *= -1;
	}
	float tempX, tempY;
	Ninja::GetInstance()->GetPosition(tempX, tempY);
	if (tempX - this->x < 0)// quay huong theo ninja
	{
		this->nx = -1;
	}
	else
	{
		this->nx = 1;
	}
	CGameObject::Update(dt);
	for (int i = 0; i < 3; i++)
	{
		if (!mWeapon[i]->GetisFinished())
		{
			mWeapon[i]->Update(dt);
		}
		else
		{
			shootAgain++;
		}
	}
	for(int i=0;i<3;i++)
	{
		
		DWORD now = GetTickCount();
		if (now - lastTimeShoot > TIME_DELAY_SHOOT&&shootAgain == 3)
		{
			again = true;
			lastTimeShoot = now;
		}
		else
		{
			shootAgain = 0;
		}
		if (now - lastTimeBullet > TIME_BETWEEN_TWO_BULLET&&mWeapon[i]->GetisFinished()&&again)
		{
			mWeapon[i]->Attach(x,y,nx);
			this->isAttach = 1;
			lastTimeBullet = now;
			if (i == 2) { again = false; shootAgain = 0; };
		}
	}
}

void CGunRage::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 18;
	bottom = y + 33;
}

void CGunRage::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y, GUNRAGE_TO_CENTERX * 2, GUNRAGE_TO_CENTERY * 2);
	}
	CGameObject::SubHealth(th);
}


CGunRage::~CGunRage()
{
}
