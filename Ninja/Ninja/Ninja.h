#pragma once
#include"CGameObject.h"
#include"Texture.h"
#include"define.h"

#define NINJA_WALKING_SPEED		0.1f
#define NINJA_JUMP_SPEED_Y		0.5f
#define NINJA_GRAVITY			0.002f

#define NINJA_STATE_IDLE			0
#define NINJA_STATE_WALKING_RIGHT	100
#define NINJA_STATE_WALKING_LEFT	200
#define NINJA_STATE_JUMP			300
#define NINJA_STATE_ATTACH          400
#define NINJA_STATE_SIT             500
//



#define NINJA_ANI_IDLE				0
#define NINJA_ANI_WALKING			1
#define NINJA_ANI_JUMP              2
#define NINJA_ANI_ATTACH		    3
#define NINJA_ANI_IDLE_SIT			  4
#define NINJA_ANI_SIT_ATTACH		 5
#define NINJA_ANI_ATTACH_ON_JUMP	 6

class Ninja:public CGameObject
{
private:
	static Ninja * _instance;
	
	int isSit;
public:
	Ninja();
	void Update(DWORD dt);
	void Render();
	void SetState(int State);
	void LoadAni();
	static Ninja * GetInstance();
};

