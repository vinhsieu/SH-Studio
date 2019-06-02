#include "CGameObject.h"
#include "debug.h"
#include "Texture.h"
#include "CGame.h"
#include "CGameObject.h"
#include "Sprite.h"

void CGameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	this->animations.push_back(ani);
}

void CGameObject::RenderBoundingBox(int ToCenterX, int ToCenterY)
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;
	CCamera *cam = CCamera::GetInstance();
	LPDIRECT3DTEXTURE9 bbox = CTexture::GetInstance()->Get(eType::BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	CGame::GetInstance()->Draw(x+ToCenterX, y+ToCenterY, bbox, rect.left, rect.top, rect.right, rect.bottom,0,CCamera::GetInstance()->Tranform(),200);
}

void CGameObject::SubHealth(int th)
{
	
	this->Health -= th;
	if (this->Health < 0)
	{
		this->Health = 0;
	}
}

eType CGameObject::GetType()
{
	return this->type;
}

void CGameObject::SetID(int id)
{
	this->id = id;
}

void CGameObject::SetDirection(int Direction)
{
	this->nx = Direction;
}

int CGameObject::GetDirection()
{
	return this->nx;
}





int CGameObject::GetHealth()
{
	return Health;
}

int CGameObject::GetID()
{
	return this->id;
}

void CGameObject::SetDefault()
{
	this->x = xBackup;
	this->y = yBackup;
	this->nx = nxBackup;
	this->Health = HealthBackup;
}

bool CGameObject::AABBcollision(LPGAMEOBJECT  gameobj)
{
	RECT rect1,rect2;
	float left, top, right, bottom;
	gameobj->GetBoundingBox(left, top, right, bottom);
	rect1.left = left;
	rect1.top = top;
	rect1.right = right;
	rect1.bottom = bottom;
	this->GetBoundingBox(left, top, right, bottom);
	rect2.left = left;
	rect2.top = top;
	rect2.right = right;
	rect2.bottom = bottom;
	return CGame::GetInstance()->isContain(rect1, rect2);
}

LPCOLLISIONEVENT CGameObject::SweptAABBEx(CGameObject * coO)
{
	float sl, st, sr, sb;		// static object bbox
	float ml, mt, mr, mb;		// moving object bbox
	float t, nx, ny;

	coO->GetBoundingBox(sl, st, sr, sb);

	// deal with moving object: m speed = original m speed - collide object speed
	float svx, svy;
	coO->GetSpeed(svx, svy);

	float sdx = svx * dt;
	float sdy = svy * dt;

	float dx = this->dx - sdx;
	float dy = this->dy - sdy;

	GetBoundingBox(ml, mt, mr, mb);

	CGame::SweptAABB(
		ml, mt, mr, mb,
		dx, dy,
		sl, st, sr, sb,
		t, nx, ny
	);

	CCollisionEvent * e = new CCollisionEvent(t, nx, ny, coO);
	return e;
}

void CGameObject::CalcPotentialCollisions(vector<CGameObject*>* coObjects, vector<LPCOLLISIONEVENT>& coEvents)
{
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		LPCOLLISIONEVENT e = SweptAABBEx(coObjects->at(i));

		if (e->t > 0 && e->t <= 1.0f)
			coEvents.push_back(e);
		else
			delete e;
	}

	std::sort(coEvents.begin(), coEvents.end(), CCollisionEvent::compare);
}

void CGameObject::FilterCollision(vector<LPCOLLISIONEVENT>& coEvents, vector<LPCOLLISIONEVENT>& coEventsResult, float & min_tx, float & min_ty, float & nx, float & ny)
{
	min_tx = 1.0f;
	min_ty = 1.0f;
	int min_ix = -1;
	int min_iy = -1;

	nx = 0.0f;
	ny = 0.0f;

	coEventsResult.clear();

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT c = coEvents[i];

		if (c->t < min_tx && c->nx != 0) {
			min_tx = c->t; nx = c->nx; min_ix = i;
		}

		if (c->t < min_ty  && c->ny != 0) {
			min_ty = c->t; ny = c->ny; min_iy = i;
		}
	}

	if (min_ix >= 0) coEventsResult.push_back(coEvents[min_ix]);
	if (min_iy >= 0) coEventsResult.push_back(coEvents[min_iy]);
}

void CGameObject::CheckCollisionWithBrick(vector<LPGAMEOBJECT>* coObjects)
{
	//Objects dua vao chi duoc dua vao brick
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	vector<LPGAMEOBJECT> list_Brick;
	list_Brick.clear();
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (coObjects->at(i)->GetType() == eType::BRICK)
			list_Brick.push_back(coObjects->at(i));
	}

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
			x += min_tx * dx + nx * 0.4f;
			if (ny == -1)
			{
				y += min_ty * dy + ny * 0.4f;
			}
			else
			{
				y += dy;
			}
		}

	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;
	Health = 1;

	//isAttach = -1;
}

void CGameObject::Update(DWORD dt)
{
	this->dt = dt;
	dx = vx * dt;
	dy = vy * dt;
	
	

}

void CGameObject::Render()
{
	//animations[0]->Render();
}

void CGameObject::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CGameObject::SetSpeed(float vx, float vy)
{
	this->vx = vx;
	this->vy = vy;
}


void CGameObject::LoadAni()
{
}

void CGameObject::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
}

CGameObject::~CGameObject()
{
	
}
