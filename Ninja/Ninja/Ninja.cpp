#include "Ninja.h"

bool checker = false;
bool checker2 = false;

Ninja::Ninja()
{
	//CGameObject::CGameObject();
	isAttach = -1;//Not attach, 1 attach
	isSit = -2;// Not Sit , 2 sit
	isLeft = 0;//1 on the left, 0 on the right
}

void Ninja::Update(DWORD dt)
{
	CGameObject::Update(dt);
	vy += NINJA_GRAVITY*dt;
	if (y > 150)
	{
		vy = 0; y = 150.0f;
	}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}

void Ninja::Render()
{
	int ani;
	int complex=isAttach+isSit;
	if (vx == 0)// Idle
	{
		switch (complex)
		{
		case -3:		//not sit, not attach
			ani = NINJA_ANI_IDLE;
			break;
		case -1:		//not sit, attach
			ani = NINJA_ANI_ATTACH;
			break;
		case 1:			//sit, not attach
			ani = NINJA_ANI_IDLE_SIT;
			break;
		case 3:			//sit, attach
			ani = NINJA_ANI_SIT_ATTACH;
			break;
		}
		if (nx > 0)// On the right side
		{
			isLeft = 0;
		}
		else  //On the left side
		{
			isLeft = 1;
		}
	}
	else
	{
		if (isAttach < 0) ani = NINJA_ANI_WALKING;
		else
		{
			ani = NINJA_ANI_ATTACH;
		}
		if (vx > 0)
		{
			isLeft = 0;
		}
		else
		{
			isLeft = 1;
		}
	}
	if (y<150)
	{
		if (isAttach == 1)
		{
			ani = NINJA_ANI_ATTACH_ON_JUMP;
			if (nx > 0) isLeft=0;
			else isLeft=1;

		}
		else ani = NINJA_ANI_JUMP;
	}
	if (animations[ani]->Render(x, y, isAttach,isLeft) == -1)
	{
		isAttach = -1;
	}
	
}

void Ninja::SetState(int State)
{
	CGameObject::SetState(State);
	switch (State)
	{
	case NINJA_STATE_WALKING_RIGHT:
		if (isAttach == 1)
		{
			vx = 0;
			break;
		}
		vx = NINJA_WALKING_SPEED;
		nx = 1;
		break;
	case NINJA_STATE_WALKING_LEFT:
		if (isAttach == 1)
		{
			vx = 0;
			break;
		}
		vx = -NINJA_WALKING_SPEED;
		nx = -1;
		break;
	case NINJA_STATE_JUMP:
		if (y ==150)
		{
			vy = -NINJA_JUMP_SPEED_Y;
		}
	case NINJA_STATE_IDLE:
		vx = 0;
		isSit = -2;
		break;
	case NINJA_STATE_SIT:
		vx = 0;
		isSit = 2;
		break;
	case NINJA_STATE_ATTACH:
		
		isAttach = 1;
		break;

	}
}
