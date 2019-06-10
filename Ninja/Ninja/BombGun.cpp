#include "BombGun.h"
#include"Ninja.h"
#include"Grid.h"


CBombGun::CBombGun(int id,float x, float y, int Direction)
{
	CGameObject::CGameObject();
	this->id = id;
	this->x =this->xBackup= x;
	this->y =this->yBackup= y;
	this->nx =this->nxBackup= Direction;
	this->HealthBackup = this->Health;
	this->type = eType::BombGun;
	mWeapon = new BombGun_Fired();
	mWeapon->SetID(this->id * 10);
	Grid::GetInstance()->AddObj(this->id, mWeapon);
	LoadAni();
}

void CBombGun::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(900, 383, 68, 415, 93, tex);
	sprites->Add(901, 414, 68, 444, 93, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(200);
	ani->Add(900);
	ani->Add(901);
	animations->Add(1041, ani);
	AddAnimation(1041);
}

void CBombGun::Render()
{
	CSprites * sprites = CSprites::GetInstance();
	if (this->Health == 0)
	{
		return;
	}
	if (isAttach)
	{
		sprites->Get(900)->Draw(this->x + BOMGUN_TO_CENTERX, this->y + BOMGUN_TO_CENTERY, this->nx, CCamera::GetInstance()->Tranform());
	}
	else
	{
		sprites->Get(901)->Draw(this->x + BOMGUN_TO_CENTERX, this->y + BOMGUN_TO_CENTERY, this->nx, CCamera::GetInstance()->Tranform());
	}
	//this->animations.at(0)->Render(this->x+BOMGUN_TO_CENTERX, this->y+BOMGUN_TO_CENTERY, 0, this->nx, CCamera::GetInstance()->Tranform());
	if (!mWeapon->GetisFinished())
	{
		mWeapon->Render();
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BOMGUN_TO_CENTERX,BOMGUN_TO_CENTERY);
	}
}

void CBombGun::Update(DWORD dt)
{
	if (this->Health == 0)
	{
		return;
	}
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	float tempX, tempY;
	Ninja::GetInstance()->GetPosition(tempX, tempY);
	if (tempX - this->x < 0)
	{
		this->nx = -1;
	}
	else
	{
		this->nx = 1;
	}

	if (mWeapon->GetisFinished())
	{
		isAttach = 1;
		mWeapon->Attach(x, y, nx);
	}
	else
	{
		isAttach = 0;
		mWeapon->Update(dt);
	}

}

void CBombGun::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 26;
	bottom = y + 26;
}

void CBombGun::WeaponAttach()
{
}

void CBombGun::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y, BOMGUN_TO_CENTERX * 2, BOMGUN_TO_CENTERY * 2);
	}
	CGameObject::SubHealth(th);
}


CBombGun::~CBombGun()
{
	SAFE_DELETE(mWeapon);
}
