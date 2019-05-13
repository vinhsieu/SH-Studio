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

void CGameObject::RenderBoundingBox()
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

	CGame::GetInstance()->Draw(x, y, bbox, rect.left, rect.top, rect.right, rect.bottom,0,CCamera::GetInstance()->Tranform(),200);
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



int CGameObject::GetHealth()
{
	return Health;
}

int CGameObject::GetID()
{
	return this->id;
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

		if (c->t <= min_tx && c->nx != 0)
		{
			min_tx = c->t;
			nx = c->nx;
			min_ix = i;
		}

		if (c->t <= min_ty && c->ny != 0)
		{
			min_ty = c->t;
			ny = c->ny;
			min_iy = i;
		}
	}

	if (min_ix >= 0)
		coEventsResult.push_back(coEvents[min_ix]);
	if (min_iy >= 0)
		coEventsResult.push_back(coEvents[min_iy]);
}

CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;
	Health = 100;
	//isAttach = -1;
}

void CGameObject::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
	/*this->dt = dt;
	dx = vx * dt;
	dy = vy * dt;*/

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
