#include "Panther.h"
#include"Ninja.h"
#include"Brick.h"
#include"Grid.h"

CPanther::CPanther(float x, float y, int Direction)
{
	CGameObject::CGameObject();
	this->x = this->xBackup = x;
	this->y = this->yBackup = y;
	this->nx = this->nxBackup = Direction;
	this->Health = 0;
	this->HealthBackup = Health;
	this->isActive = false;
	this->vx = PANTHER_VX;
	this->type = eType::Panther;
	this->isJumping = false;
	LoadAni();
}

void CPanther::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(800, 314, 79, 346, 93, tex);
	sprites->Add(801, 355, 77, 381, 93, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(800);
	ani->Add(801);
	animations->Add(1031, ani);
	//Nhay
	ani = new CAnimation(100);
	ani->Add(800);
	animations->Add(1032,ani);
	AddAnimation(1031);
	AddAnimation(1032);
}

void CPanther::Render()
{
	if (this->Health == 0 || !isActive)
	{
		return;
	}
	if (isJumping)
	{
		this->animations.at(1)->Render(this->x + PANTHER_TO_CENTEX, this->y + PANTHER_TO_CENTEY, 0, this->nx, CCamera::GetInstance()->Tranform());
	}
	else
	{
		this->animations.at(0)->Render(this->x + PANTHER_TO_CENTEX, this->y + PANTHER_TO_CENTEY, 0, this->nx, CCamera::GetInstance()->Tranform());
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(PANTHER_TO_CENTEX,PANTHER_TO_CENTEY);
	}
}

void CPanther::Update(DWORD dt)
{
	
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	float xNinja, yNinja;
	Ninja::GetInstance()->GetPosition(xNinja, yNinja);
	if (this->nx == -1)
	{
		if (!isActive)// Tranh tinh trang danh ko chet
		{
			isActive = true;
			this->Health = 1;
		}
	}
	else if (this->x - xNinja < 0 && fabs(this->x - xNinja) > PANTHER_ACTIVE_AREA)
	{
		if (!isActive)
		{
			isActive = true;
			this->Health = 1;
		}
	}
	
	if (this->Health == 0)
	{
		return;
	}
	if (isActive)
	{
		this->vy += 0.002*dt;//Gravity
		CGameObject::Update(dt);
		if (this->y < 145)
		{
			CheckCollisionWithBrick();
		}
		else
		{
			this->isJumping = false;
			this->x += dx;
		}
	}
	
}

void CPanther::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 26;
	bottom = y + 17;
}

void CPanther::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y, PANTHER_TO_CENTEX * 2, PANTHER_TO_CENTEY * 2);
	}
	CGameObject::SubHealth(th);
}

void CPanther::CheckCollisionWithBrick()
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
			isJumping = false;
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
			if ((this->x < xBrickStart&&this->nx == -1) || (this->x + FOOTBALLGUY_TO_CENTERX * 2 > xBrickEnd&&this->nx == 1))
			{
				isJumping = true;
				this->vy = -FOOTBALLGUY_JUMP_SPEED_Y;
			}

		}

	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void CPanther::SetDefault()
{
	CGameObject::SetDefault();
	this->isActive = false;
}


CPanther::~CPanther()
{
}
