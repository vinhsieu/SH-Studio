#include "CGameObject.h"
#include "debug.h"
#include "Texture.h"
#include "CGame.h"
#include "CGameObject.h"
#include "Sprite.h"
vector<LPANIMATION> CGameObject::animations;

void CGameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}

void CGameObject::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	LPDIRECT3DTEXTURE9 bbox = CTexture::GetInstance()->Get(ID_TEX_BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	CGame::GetInstance()->Draw(x, y, bbox, rect.left, rect.top, rect.right, rect.bottom, 1,32);
}

LPCOLLISIONEVENT CGameObject::SweptAABBEx(LPGAMEOBJECT coO)
{
	return LPCOLLISIONEVENT();
}

CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;
	//isAttach = -1;
}

void CGameObject::Update(DWORD dt, vector<LPGAMEOBJECT> *coObject )
{
	this->dt = dt;
	dx = vx * dt;
	dy = vy * dt;

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
