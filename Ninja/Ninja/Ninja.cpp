#include "Ninja.h"
#include"debug.h"

Ninja * Ninja::_instance = NULL;

Ninja::Ninja()
{
	CGameObject::CGameObject();
	isAttach = -1;//Not attach, 1 attach
	isSit = -2;// Not Sit , 2 sit
	
	
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
	//if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
	CCamera * mCamera = CCamera::GetInstance();
	mCamera->SetPosition(x,104);
	DebugOut(L"[INFO]Toa Do Ninja: %f, %f\n", x, y);
}

void Ninja::Render()
{
	int isLeft = this->nx;
	CCamera * mCamera = CCamera::GetInstance();
	D3DXVECTOR2 trans = D3DXVECTOR2(320 / 2 -mCamera->GetPosition().x,
		208 / 2 - mCamera->GetPosition().y);
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
		//if (nx > 0)// On the right side
		//{
		//	isLeft = 1;
		//}
		//else  //On the left side
		//{
		//	isLeft = -1;
		//}
	}
	else
	{
		if (isAttach < 0) ani = NINJA_ANI_WALKING;
		else
		{
			ani = NINJA_ANI_ATTACH;
		}
		
	}
	if (y<150)
	{
		if (isAttach == 1)
		{
			ani = NINJA_ANI_ATTACH_ON_JUMP;
			/*if (nx > 0) isLeft=0;
			else isLeft=1;*/

		}
		else ani = NINJA_ANI_JUMP;
	}
	if (animations.at(ani)->Render(x, y, isAttach,isLeft,trans) == -1)
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

void Ninja::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texNinja = texture->Get(eType::NINJA);

	//Run Right
	sprites->Add(10000, 0, 5, 22, 37, texNinja);
	sprites->Add(10001, 338, 5, 360, 37, texNinja);
	sprites->Add(10002, 368, 5, 390, 37, texNinja);
	sprites->Add(10003, 399, 5, 421, 37, texNinja);


	//ATTACH RIGHT
	sprites->Add(10033, 4, 5, 26, 37, texNinja);
	sprites->Add(10034, 25, 160, 47, 192, texNinja);
	sprites->Add(10035, 48, 5, 106, 37, texNinja);
	sprites->Add(10036, 106, 5, 140, 37, texNinja);

	//SIT ATTACH RIGHT
	sprites->Add(10037, 35, 44, 53, 76, texNinja);
	sprites->Add(10038, 75, 156, 132, 188, texNinja);
	sprites->Add(10039, 93, 44, 129, 76, texNinja);

	//JUMP
	sprites->Add(10021, 139, 49, 161, 81, texNinja);
	sprites->Add(10022, 166, 49, 188, 81, texNinja);
	sprites->Add(10023, 190, 49, 212, 81, texNinja);
	sprites->Add(10024, 217, 49, 239, 81, texNinja);
	//Sit right
	sprites->Add(10050, 1, 44, 23, 76, texNinja);
	//Sit left
	sprites->Add(10051, 108, 192, 130, 224, texNinja);

	LPANIMATION ani;
	//idle right
	ani = new CAnimation(100);
	ani->Add(10000);
	animations->Add(400, ani);

	//Walk right
	ani = new CAnimation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(500, ani);
	//JUMP
	ani = new CAnimation(20);
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	animations->Add(600, ani);

	//ATTACH RIGHT
	ani = new CAnimation(100);
	ani->Add(10033);
	ani->Add(10034);
	ani->Add(10035);
	ani->Add(10036);
	animations->Add(701, ani);
	//Sit right
	ani = new CAnimation(100);
	ani->Add(10050);
	animations->Add(801, ani);

	//Sit Attach Right
	ani = new CAnimation(100);
	ani->Add(10037);
	ani->Add(10038);
	ani->Add(10039);
	animations->Add(702, ani);
	//Attach on Jump right
	ani = new CAnimation(200);
	ani->Add(10035);
	animations->Add(704, ani);

	_instance->AddAnimation(400);		// idle right 0
	_instance->AddAnimation(500);		// walk right 2
	_instance->AddAnimation(600);       //Jump Ani 4
	_instance->AddAnimation(701);       //Attach left 6
	_instance->AddAnimation(801);       //Sit idle right 8
	_instance->AddAnimation(702);		//Sit Attach right 9
	_instance->AddAnimation(704);		//Attach on Jump Right 11
	_instance->SetPosition(0.0f, 150.0f);
}

Ninja * Ninja::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Ninja();
	}
	return _instance;
}


