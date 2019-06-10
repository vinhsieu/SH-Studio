#pragma once
#include"CGameObject.h"
#include"Texture.h"
#include"define.h"
#include"CWeapon.h"
#include"BasicWeapon.h"
#include"CBlueShuriken.h"
#include"CRedShuriken.h"
#include"Stairs.h"

#define NINJA_WALKING_SPEED		0.1f
#define NINJA_JUMP_SPEED_Y		0.45f
#define NINJA_GRAVITY			0.002f
#define NINJA_BEING_HURT_SPEED_Y 0.2f
#define NINJA_BEING_HURT_SPEED_X 0.5f
#define NINJA_UNTOUCHABLE_TIME  750


#define NINJA_STATE_IDLE			0
#define NINJA_STATE_WALKING_RIGHT	100
#define NINJA_STATE_WALKING_LEFT	200
#define NINJA_STATE_JUMP			300
#define NINJA_STATE_ATTACH          400
#define NINJA_STATE_SIT             500
#define NINJA_STATE_BEING_HURT		600
#define NINJA_STATE_EXTRA_WEAPON    700
#define NINJA_STATE_CLIMBING		800
//



#define NINJA_ANI_IDLE				0
#define NINJA_ANI_WALKING			1
#define NINJA_ANI_JUMP              2
#define NINJA_ANI_ATTACH		    3
#define NINJA_ANI_IDLE_SIT			4
#define NINJA_ANI_SIT_ATTACH		5
#define NINJA_ANI_ATTACH_ON_JUMP	6
#define NINJA_ANI_BEING_HURT		7
#define NINJA_ANI_EXTRA_WEAPON      8
#define NINJA_ANI_CLIMB_IDLE		9
#define NINJA_ANI_CLIMBING			10


#define NINJA_TO_CENTERX 8
#define NINJA_TO_CENTERY 15

class Ninja:public CGameObject
{
private:
	static Ninja * _instance;
	bool isCollisionAxisYWithBrick; // dang co va cham voi Brick
	int isAllowContinueClimbing;// Tiep Tuc Leo Khi Den Ria Stairs (1 la cho ko leo xuong, -1 la ko cho leo len)
	int isClimbing; //0 la khong leo, 1 la bu(dung yen),2 la duoc leo len
	int NavClimbingCollision;// Huong va cham voi Stairs
	float nxwithStairs;


	int isSit;
	bool untouchable;
	

	int Point;
	int NumberOfBullet;//Dan(spirit)
	int Life;

	int isUsingExtraWeapon;
	CWeapon *DefaultWeapon;
	CWeapon *ExtraWeapon;
	DWORD untouchable_start;
public:

	bool canControl;// Co the dieu khien ninja khi bi hurt hay khong ?
	Ninja();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int State);
	void LoadAni();
	int getLife();
	int getSpirit();
	void SetHealthMax();
	void plusPoint(int plusPoint);
	void Attach(); // kich hoat vu khi
	void SetCanControl(bool isCanControl);
	void StartUntouchable() { untouchable = true; untouchable_start = GetTickCount(); canControl = false; }
	bool getUntouchable();
	void CheckCollisionWithBrick(vector<LPGAMEOBJECT>* coObjects);
	void CheckCollisionWithEmemy(vector<LPGAMEOBJECT>* coObjects);
	void CheckCollisionWithItems();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	eType GetExTraWeaponType();
	int GetScore();
	static Ninja * GetInstance();
};

