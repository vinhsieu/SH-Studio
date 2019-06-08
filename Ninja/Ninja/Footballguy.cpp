#include "Footballguy.h"
#include"Grid.h"
#include"Brick.h"
#include"Ninja.h"
CFootballguy::CFootballguy(float x, float y, int Direction)
{
	this->isActive = false;
	this->x = this->xBackup = x;
	this->y = this->yBackup = y;
	this->nx = this->nxBackup = Direction;
	this->Health = 0;
	this->HealthBackup = this->Health;
	this->vx = 0.1f;
	this->type = eType::Footballguy;
	isJumping = false;
	LoadAni();
}

void CFootballguy::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(1000, 3, 60, 19, 92, tex);
	sprites->Add(1001, 22, 60, 40, 92, tex);

	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(1000);
	ani->Add(1001);
	animations->Add(1051, ani);
	//Nhay
	ani = new CAnimation(100);
	ani->Add(1001);
	animations->Add(1052, ani);

	
	AddAnimation(1051);
	AddAnimation(1052);
}

void CFootballguy::Render()
{
	if (this->Health == 0 || !isActive)
	{
		return;
	}
	if (isJumping)
	{
		this->animations.at(1)->Render(this->x+FOOTBALLGUY_TO_CENTERX, this->y+FOOTBALLGUY_TO_CENTERY, 0, this->nx, CCamera::GetInstance()->Tranform());
	}
	else
	{
		this->animations.at(0)->Render(this->x+FOOTBALLGUY_TO_CENTERX, this->y+FOOTBALLGUY_TO_CENTERY, 0, this->nx, CCamera::GetInstance()->Tranform());
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(FOOTBALLGUY_TO_CENTERX,FOOTBALLGUY_TO_CENTERY);
	}
}

void CFootballguy::Update(DWORD dt)
{
	if (nx*vx < 0)
	{
		vx *= -1;
	}
	float xNinja, yNinja;
	Ninja::GetInstance()->GetPosition(xNinja, yNinja);
	if (this->nx == -1)
	{
		if (!isActive)
		{
			isActive = true;
			this->Health = 1;
		}
	}
	else
	{
		if (this->x - xNinja < 0 && fabs(this->x - xNinja) > BLADE_ACTIVE_AREA)
		{
			if (!isActive)
			{
				isActive = true;
				this->Health = 1;
			}
		}
	}
	if (!isActive)
	{
		return;
	}
	if (this->Health == 0)
	{
		return;
	}
	vy += NINJA_GRAVITY * dt;
	CGameObject::Update(dt);

	CheckCollisionWithBrick();
	//DebugOut(L"dx:%f\n", this->dx);
}

void CFootballguy::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 32;
}

void CFootballguy::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y,FOOTBALLGUY_TO_CENTERX * 2, FOOTBALLGUY_TO_CENTERY * 2);
	}
	CGameObject::SubHealth(th);


}

void CFootballguy::CheckCollisionWithBrick()
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
			if ((this->x < xBrickStart&&this->nx==-1)|| (this->x + FOOTBALLGUY_TO_CENTERX * 2 > xBrickEnd&&this->nx==1))
			{
				isJumping = true;
				this->vy = -FOOTBALLGUY_JUMP_SPEED_Y;
			}
			
		}

	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}


void CFootballguy::SetDefault()
{
	this->isActive = false;
	CGameObject::SetDefault();
}

CFootballguy::~CFootballguy()
{
}
