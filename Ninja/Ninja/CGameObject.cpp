#include "CGameObject.h"

vector<LPANIMATION> CGameObject::animations;

void CGameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}

CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;
	//isAttach = -1;
}

void CGameObject::Update(DWORD dt)
{

	x += vx * dt;
	y += vy * dt;

}

void CGameObject::Render()
{
	
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


CGameObject::~CGameObject()
{
	
}
