#include "Blade.h"
#include"Ninja.h"
#include"Grid.h"
CBlade::CBlade(float x, float y, int Direction)
{
	CGameObject::CGameObject();
	this->isActive = false;
	this->x =this->xBackup= x;
	this->y =this->yBackup= y;
	this->nx = Direction;
	this->nxBackup= Direction;
	this->Health = 0;
	this->HealthBackup = this->Health;
	this->type = eType::Blade;
	this->vx = BLADE_VX;
	LoadAni();
}

void CBlade::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(700, 209, 60, 241, 92, tex);
	sprites->Add(701, 240, 60, 270, 92, tex);
	sprites->Add(702, 282, 52, 300, 99, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(700);
	ani->Add(701);
	ani->Add(702);
	animations->Add(1021, ani);
	AddAnimation(1021);
}

void CBlade::Render()
{
	if (this->Health == 0||!isActive)
	{
		return;
	}
	this->animations.at(0)->Render(this->x + BLADE_TO_CENTERX, this->y + BLADE_TO_CENTERY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	

	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BLADE_TO_CENTERX, BLADE_TO_CENTERY);
	}
	//DebugOut(L"x= %f,y= %f,nx=%d\n", this->x, this->y,this->nx);
	
}

void CBlade::Update(DWORD dt)
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
	
	this->vy += 0.002*dt;
	//DebugOut(L"vx: %f,nx:%f\n", this->vx,this->nx);
	CGameObject::Update(dt);
	CheckCollisionWithBrick();
}

void CBlade::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 18;
	bottom = y + 33;
}

void CBlade::CheckCollisionWithBrick()
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
			CBrick *currentBrick= dynamic_cast<CBrick *>(e->obj);
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
			if (this->x + BLADE_TO_CENTERX * 2 > xBrickEnd)
			{
				this->nx = -1;
			}
		}

	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void CBlade::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y, BLADE_TO_CENTERX * 2, BLADE_TO_CENTERY * 2);
	}
	CGameObject::SubHealth(th);
}

void CBlade::SetDefault()
{
	this->isActive = false;
	CGameObject::SetDefault();
}

CBlade::~CBlade()
{
}
