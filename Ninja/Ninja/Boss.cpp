#include "Boss.h"
#include"Sound.h"

Boss * Boss::_instance = NULL;
int bulletFinished = 0;
Boss::Boss()
{
	this->x = 25;
	this->y = 130;
	this->nx = -1;
	this->xBackup = this->x;
	this->yBackup = this->y;
	this->nxBackup = this->nx;

	this->Health = 16;
	this->HealthBackup = 16;
	TimeEarned = 0;
	for (int i = 0; i < 3; i++)
	{
		mWeapon[i] = new Boss_bullet();
		mWeapon[i]->SetID(this->id * 100 + i);
		Grid::GetInstance()->AddObj(this->id, mWeapon[i]);
	}
	this->type = eType::BOSS;
	//DebugOut(L"health:%d\n", this->Health);
	LoadAni();
}

void Boss::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();


	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);
	sprites->Add(400, 346, 253, 388, 301, tex);
	sprites->Add(401, 388, 247, 436, 301, tex);
}

void Boss::Render()
{
	CSprites * sprites = CSprites::GetInstance();
	if (isJumping)
	{
		sprites->Get(400)->Draw(this->x+ BOSS_TO_CENTERX, this->y+ BOSS_TO_CENTERY, nx, CCamera::GetInstance()->Tranform());
	}
	else
	{
		sprites->Get(401)->Draw(this->x+ BOSS_TO_CENTERX, this->y+ BOSS_TO_CENTERY, nx, CCamera::GetInstance()->Tranform());
	}
	for (int i = 0; i < 3; i++)
	{
		if (!mWeapon[i]->GetisFinished())
		{
			mWeapon[i]->Render();
		}
	}
	if(IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BOSS_TO_CENTERX,BOSS_TO_CENTERY);
	}
}

void Boss::Update(DWORD dt)
{
	//DebugOut(L"health:%d\n", this->Health);
	//DebugOut(L"x=%f,y=%f\n", this->x, this->y);

	CBoard::GetInstance()->SetBossHealth(this->Health);
	if (this->Health == 0)
	{
		for (auto x : mWeapon)
		{
			x->setIsFinished(true);
		}
		return;
	}
	//TimeEarned += dt;
	vy += 0.002f*dt;
	if (this->y > 130)
	{
		this->vx = 0;
		this->vy = 0;
		isJumping = false;
		this->y = 130;
	}
	if (this->y == 130)
	{
		if (this->x < 25)
		{
			this->x = 25;
		}
		if (TimeEarned > Time_Change_Direction)
		{
			Sound::GetInstance()->Play(eSound::sound_Boss_Jump_Hit_Wall);
			this->vy = -BOSS_JUMP_Y;
			isJumping = true;
			this->nx *= -1;
			this->vx = 0.27f;
			TimeEarned = 0;
		}
		else
		{
			TimeEarned += dt;
		}
	}
	
	if (nx*vx < 0)// Dieu huong van toc theo huong
	{
		vx *= -1;
	}
	//Xu Li mWeapon
	for (int i = 0; i < 3; i++)
	{
		if (!mWeapon[i]->GetisFinished())
		{
			mWeapon[i]->Update(dt);
		}
		else
		{
			bulletFinished++;
		}
	}
	if (bulletFinished == 3&&!isJumping)
	{
		bulletFinished = 0;
		if (this->nx == 1)
		{
			mWeapon[0]->Attach(x - 10, y - 20, nx);
			mWeapon[1]->Attach(x - 20, y, nx);
			mWeapon[2]->Attach(x - 40, y + 15, nx);
		}
		else
		{
			mWeapon[0]->Attach(x + 30, y - 20, nx);
			mWeapon[1]->Attach(x + 20, y, nx);
			mWeapon[2]->Attach(x + 0, y + 15, nx);
		}
		
	}
	else
	{
		bulletFinished = 0;
	}
	CGameObject::Update(dt);
	this->x += dx;
	this->y += dy;
	
}

void Boss::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = this->x+5;
	top = this->y;
	right =left + 30;
	bottom = top + 45;
}

void Boss::SubHealth(int th)
{

	if (this->Health == 1)
	{
		Sound::GetInstance()->Play(eSound::sound_Boss_Die);
		EffectManager::GetInstance()->AddEffect(this->x+5, this->y+5, BOSS_TO_CENTERX * 2, BOSS_TO_CENTERY * 2,1);
		Timer::GetInstance()->plusPoint();// Het Man
	}
	CGameObject::SubHealth(th);
}

Boss * Boss::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Boss();
	}
	return _instance;
}


Boss::~Boss()
{
}
