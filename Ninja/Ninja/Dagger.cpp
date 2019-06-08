#include "Dagger.h"
#include"Ninja.h"
#include"Grid.h"
#include"Brick.h"



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
	
	ani = new CAnimation(225);
	ani->Add(500);
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
	
	CSprites *sprite = CSprites::GetInstance();

	if (isAttach == -1)
	{
		//sprite->Get(502)->Draw(this->x + DAGGER_T0_CENTERX, this->y + DAGGER_T0_CENTERY, AniDirection, CCamera::GetInstance()->Tranform());

		this->animations.at(0)->Render(this->x+DAGGER_T0_CENTERX, this->y+DAGGER_T0_CENTERY, 0, AniDirection,CCamera::GetInstance()->Tranform());
	}
	else
	{
		if (this->animations.at(1)->Render(this->x + DAGGER_T0_CENTERX, this->y + DAGGER_T0_CENTERY, 0, AniDirection, CCamera::GetInstance()->Tranform()) == -1)
		{
			this->isAttach = -1;
		}
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

	if (tempX - this->x < 0)//Huong Ani Khac Huong Di
	{
		AniDirection = -1;
	}
	else
	{
		AniDirection = 1;
	}
	if (mWeapon->GetisFinished() && fabs(tempX - this->x) < DAGGER_ACTIVE_WEAPON)
	{
		isAttach = 1;
		mWeapon->Attach(x,y,nx);
	}
	else
	{
		isAttach = -1;
	}
	if (!mWeapon->GetisFinished())
	{
		mWeapon->Update(dt);
	}
	this->vy += 0.002*dt;
	CGameObject::Update(dt);
	CheckCollisionWithBrick();
}

void CDagger::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 26;
	bottom = y + 33;
}

void CDagger::CheckCollisionWithBrick()
{
	//Objects dua vao chi duoc dua vao brick
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	vector<LPGAMEOBJECT> list_Brick;
	list_Brick.clear();

	Grid::GetInstance()->ListStatic(list_Brick);
	CalcPotentialCollisions(&list_Brick, coEvents);

	//DebugOut(L"coObjects: %d ,coEvents: %d\n",coObjects->size(), coEvents.size());

	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
		// ?ang ko va ch?m tr?c y
	   //DebugOut(L"Khong Co Va Cham\n");
	}
	else
	{

		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			CBrick *currentBrick = dynamic_cast<CBrick *>(e->obj);
			x += min_tx * dx + nx * 0.4f;
			if (ny == -1)
			{
				y += min_ty * dy + ny * 0.4f;
			}
			else
			{
				y += dy;
			}
			float xBrickStart = 0;
			float xBrickEnd = 0;
			currentBrick->getStartEnd(xBrickStart, xBrickEnd);
			if (this->x < xBrickStart)
			{
				this->nx = 1;
			}
			if (this->x + DAGGER_T0_CENTERX * 2 > xBrickEnd)
			{
				this->nx = -1;
			}
		}

	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void CDagger::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y,DAGGER_T0_CENTERX * 2, DAGGER_T0_CENTERY * 2);
	}
	CGameObject::SubHealth(th);
}

CDagger::~CDagger()
{
	SAFE_DELETE(mWeapon);
}
