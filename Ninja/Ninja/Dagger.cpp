#include "Dagger.h"
#include"Ninja.h"





CDagger::CDagger(float x, float y, int Direction)
{
	this->x =this->xBackup= x;
	this->y =this->yBackup= y;
	this->nx =this->nxBackup= Direction;
	this->HealthBackup = Health;
	this->vx = DAGGER_SPEED_X;
	this->type = eType::Dagger;
	mWeapon = new Dagger_Throw();
	LoadAni();
}

void CDagger::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);
	
	sprites->Add(500, 409, 14, 437, 46,tex);
	sprites->Add(501, 444, 14, 473, 46,tex);
	sprites->Add(502, 491, 3, 515, 57, tex);

	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(500);
	ani->Add(501);
	animations->Add(1000, ani);
	//Danh
	ani = new CAnimation(100);
	ani->Add(501);
	ani->Add(502);
	animations->Add(1001, ani);
	AddAnimation(1000);
	AddAnimation(1001);
	

}

void CDagger::Render()
{
	if (this->Health == 0)
	{
		return;
	}
	


	if (isAttach = -1)
	{
		this->animations.at(0)->Render(this->x+DAGGER_T0_CENTERX, this->y+DAGGER_T0_CENTERY, 0, AniDirection,CCamera::GetInstance()->Tranform());
	}
	else
	{
		
		this->animations.at(1)->Render(this->x+DAGGER_T0_CENTERX, this->y+DAGGER_T0_CENTERY, 0, AniDirection, CCamera::GetInstance()->Tranform());
	}
	if (!mWeapon->GetisFinished())
	{
		mWeapon->Render();
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(DAGGER_T0_CENTERX, DAGGER_T0_CENTERY);
	}
}

void CDagger::Update(DWORD dt)
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
		AniDirection = -1;
	}
	else
	{
		AniDirection = 1;
	}
	if (mWeapon->GetisFinished() && abs(tempX - this->x) < DAGGER_ACTIVE_WEAPON)
	{
		isAttach = 1;
		mWeapon->Attach(x,y,nx);
	}
	if (!mWeapon->GetisFinished())
	{
		mWeapon->Update(dt);
	}
	//DebugOut(L"isAttach: %d\n",this->isAttach);
	CGameObject::Update(dt);
	x += dx;
	y += dy;
	
}

void CDagger::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 26;
	bottom = y + 33;
}

CDagger::~CDagger()
{
}
