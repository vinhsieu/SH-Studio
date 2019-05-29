#pragma once
#include<d3dx9.h>
#include<d3d9.h>
#include"CGame.h"
#include"Sprite.h"
#include<vector>
#include "Camera.h"
#include"define.h"
#include"Texture.h"
#include"EffectManager.h"

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

	int id;

	eType type;//Loai Object

	int Health; //Con Con Tai Hay Khong

	float x;
	float y;

	float xBackup;
	float yBackup;
	int nxBackup;
	int HealthBackup;


	float dx;
	float dy;

	int isAttach;
	
	// Van Toc
	float vx;
	float vy;

	int nx; // Direction

	int currentState;

	DWORD dt;

	vector<LPANIMATION> animations;
	
public:
	void SetState(int state) { this->currentState = state; }
	void AddAnimation(int aniId);

	void RenderBoundingBox(int ToCenterX,int ToCenterY);


	virtual void SubHealth(int th);

	eType GetType();
	void SetID(int id);
	void SetDirection(int Direction);
	int GetDirection();

	void SetPosition(float x, float y);
	void SetSpeed(float vx, float vy);
	void GetPosition(float &x, float &y) { x = this->x; y = this->y; }
	int GetHealth();
	void GetSpeed(float &vx, float &vy) { vx = this->vx; vy = this->vy; }
	int GetID();

	void SetDefault();

	bool AABBcollision(LPGAMEOBJECT gameobj);


	LPCOLLISIONEVENT SweptAABBEx(CGameObject * coO);
	void CalcPotentialCollisions(vector<CGameObject*> *coObjects, vector<LPCOLLISIONEVENT> &coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT> &coEvents,
		vector<LPCOLLISIONEVENT> &coEventsResult,
		float &min_tx,
		float &min_ty,
		float &nx,
		float &ny);

	virtual void CheckCollisionWithBrick(vector<LPGAMEOBJECT>* coObjects);
	CGameObject();
	virtual void Update(DWORD);
	virtual void Render();
	virtual int GetState() { return currentState; };
	virtual float GetVx() { return vx; }
	virtual void LoadAni();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	
	~CGameObject();
};

