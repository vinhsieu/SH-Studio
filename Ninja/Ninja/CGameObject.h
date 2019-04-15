#pragma once
#include<d3dx9.h>
#include<d3d9.h>
#include"CGame.h"
#include"Sprite.h"
#include<vector>
using namespace std;
#define ID_TEX_BBOX -100

class CGameObject;
typedef CGameObject * LPGAMEOBJECT;

struct CCollisionEvent;
typedef CCollisionEvent *LPCOLLISIONEVENT;

struct CCollisionEvent
{
	LPGAMEOBJECT obj;
	float t, nx, ny;
	CCollisionEvent(float t, float nx, float ny, LPGAMEOBJECT obj = NULL) { this->t = t; this->nx = nx; this->ny = ny; this->obj = obj; }

	static bool compare(const LPCOLLISIONEVENT &a, LPCOLLISIONEVENT &b)
	{
		return a->t < b->t;
	}
};

class CGameObject
{
protected:
	float x;
	float y;

	float dx;
	float dy;

	float vx;
	float vy;

	int isLeft;

	int nx;

	int currentState;

	DWORD dt;

	static vector<LPANIMATION> animations;
	
public:
	void SetState(int state) { this->currentState = state; }
	static void AddAnimation(int aniId);

	void SetPosition(float x, float y);
	void SetSpeed(float vx, float vy);
	void GetPosition(float &x, float &y) { x = this->x; y = this->y; }
	void RenderBoundingBox();

	LPCOLLISIONEVENT SweptAABBEx(LPGAMEOBJECT coO);
	void CalcPotentialCollisions(vector<LPGAMEOBJECT> *coObjects, vector<LPCOLLISIONEVENT> &coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT> &coEvents,
		vector<LPCOLLISIONEVENT> &coEventsResult,
		float &min_tx,
		float &min_ty,
		float &nx,
		float &ny
	);



	CGameObject();
	virtual void Update(DWORD, vector<LPGAMEOBJECT> *coObject=NULL);
	virtual void Render();
	virtual int GetState() { return currentState; };
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) = 0;
	~CGameObject();
};

