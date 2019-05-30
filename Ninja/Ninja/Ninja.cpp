#include "Ninja.h"
#include"debug.h"
#include"Sound.h"
#include"ItemsManager.h"
Ninja * Ninja::_instance = NULL;
bool AllowSetNewState = true;
Ninja::Ninja()
{
	CGameObject::CGameObject();
	this->Health = 100;
	isAttach = -1;//Not attach, 1 attach
	isSit = -2;// Not Sit , 2 sit
	this->type = eType::NINJA;
	this->x = 0;
	canControl = true;
	isCollisionAxisYWithBrick = true;
	DefaultWeapon= new CBasicWeapon();
	LoadAni();
}

void Ninja::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt);
	vy += NINJA_GRAVITY*dt;
	
	
	if (GetTickCount() - untouchable_start > NINJA_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = false;
		canControl = true;
		CheckCollisionWithEmemy(coObjects);
	}
	CheckCollisionWithBrick(coObjects);
	CheckCollisionWithItems();

	//Update + Render Vu Khi
	if (DefaultWeapon->GetisFinished()==false)
	{
	        DefaultWeapon->Update(dt,coObjects);
			DefaultWeapon->Render();
	}
	if (ExtraWeapon != NULL)
	{
		if (ExtraWeapon->GetisFinished() == false)
		{
			ExtraWeapon->Update(dt, coObjects);
			ExtraWeapon->Render();
		}
	}

	//Camera Chay Theo Ninja
	if (vx < 0 && x < 0) x = 0;
	CCamera * mCamera = CCamera::GetInstance();
	mCamera->SetPosition(x,104);
	
}

void Ninja::Render()
{
	int isLeft = this->nx;
	
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
			/*if (isUsingExtraWeapon)
			{
				ani = NINJA_ANI_EXTRA_WEAPON;
			}
			else
			{*/
				ani = NINJA_ANI_ATTACH;
			//}
			break;
		case 1:			//sit, not attach
			ani = NINJA_ANI_IDLE_SIT;
			break;
		case 3:			//sit, attach
			ani = NINJA_ANI_SIT_ATTACH;
			break;
		}
		
	}
	else
	{
		if (isAttach < 0)
		{
			ani = NINJA_ANI_WALKING;
		}
		else
		{
			ani = NINJA_ANI_ATTACH;
		}
		
	}
	if (isUsingExtraWeapon)
	{
		ani = NINJA_ANI_EXTRA_WEAPON;
	}
	if (isCollisionAxisYWithBrick==false/* && !untouchable*/)
	{
		if (isAttach == 1)
		{
			ani = NINJA_ANI_ATTACH_ON_JUMP;
		}
		else ani = NINJA_ANI_JUMP;
	}

	if (canControl==false)
	{
		ani = NINJA_ANI_BEING_HURT;
	}


	int isLoop=0; //Co Lap Hay Khong(Ap dung cho Attach)


	if (isAttach == 1||isUsingExtraWeapon || canControl == false)
	{
		isLoop = 1; //1 la khong lap
	}
	int alpha = 255;
	if (untouchable) alpha = 128;
	AllowSetNewState = false;// Tranh tinh trang anh hien thi khac chuc nang
	if (animations.at(ani)->Render(x+NINJA_TO_CENTERX, y+NINJA_TO_CENTERY, isLoop,isLeft,CCamera::GetInstance()->Tranform(),alpha)==-1)
	{
		canControl = true;
		isAttach = -1;
		isUsingExtraWeapon=0;
	}
	AllowSetNewState = true;
	if (ani == NINJA_ANI_ATTACH_ON_JUMP)
	{
		isAttach = -1;
		isUsingExtraWeapon = 0;
	}
	//xu li weapon
	if (DefaultWeapon->GetisFinished() == false)
	{
		DefaultWeapon->Render();
	}
	if (ExtraWeapon != NULL)
	{
		if (ExtraWeapon->GetisFinished() == false)
		{
			ExtraWeapon->Render();
		}
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(NINJA_TO_CENTERX, NINJA_TO_CENTERY);
	}
}

void Ninja::SetState(int State)
{
	if (!AllowSetNewState)
	{
		return;
	}
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
		if (isCollisionAxisYWithBrick!=false)
		{
			vy = -NINJA_JUMP_SPEED_Y;
			isCollisionAxisYWithBrick = true;
			Sound::GetInstance()->Play(eSound::sound_Jump_Climb);
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
		Attach();
		break;
	case NINJA_STATE_BEING_HURT:
		vy = -NINJA_BEING_HURT_SPEED_Y;
		vx = -0.4*NINJA_WALKING_SPEED*nx;// Giat ve phia sau huong dang di(van co loi)
		break;
	case NINJA_STATE_EXTRA_WEAPON:
		isUsingExtraWeapon = 1;
		Attach();
		break;
	}
}

void Ninja::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texNinja = texture->Get(eType::NINJA);

	if (animations->Get(400) != NULL)
	{
		return;
	}
	//Run
	sprites->Add(10000, 0, 5, 22, 37, texNinja);
	sprites->Add(10001, 338, 5, 360, 37, texNinja);
	sprites->Add(10002, 368, 5, 390, 37, texNinja);
	sprites->Add(10003, 399, 5, 421, 37, texNinja);


	//ATTACH
	sprites->Add(10033, 4, 5, 26, 37, texNinja);
	sprites->Add(10034, 25, 160, 47, 192, texNinja);
	sprites->Add(10035, 48, 5, 106, 37, texNinja);
	sprites->Add(10036, 106, 5, 140, 37, texNinja);

	//SIT ATTACH
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
	
	//Attach Extra Weapon

	sprites->Add(10061, 164, 6, 182, 37, texNinja);
	sprites->Add(10062, 185, 8, 215, 37, texNinja);
	sprites->Add(10063, 223, 8, 253, 37, texNinja);

	LPANIMATION ani;
	//idle right
	ani = new CAnimation(75);
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
	ani = new CAnimation(75);
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
	ani = new CAnimation(800);
	ani->Add(10035);
	//ani->Add(10036);
	animations->Add(704, ani);
	//Being hit
	ani = new CAnimation(300);
	ani->Add(10021);
	animations->Add(802, ani);
	//Attach Extra Weapon
	ani = new CAnimation(75);
	ani->Add(10061);
	ani->Add(10062);
	ani->Add(10063);
	animations->Add(803, ani);


	AddAnimation(400); // idle right 0
	AddAnimation(500);// walk right 2
	AddAnimation(600);
	AddAnimation(701);
	AddAnimation(801);
	AddAnimation(702);
	AddAnimation(704);
	AddAnimation(802);
	AddAnimation(803);
	//this->animations.push_back(animations->Get(400)); 
	//animations->Add->AddAnimation(400);		
	//this->animations.push_back(animations->Get(500));		
	//this->animations.push_back(animations->Get(600));      //Jump Ani 4
	//this->animations.push_back(animations->Get(701));       //Attach left 6
	//this->animations.push_back(animations->Get(801));      //Sit idle right 8
	//this->animations.push_back(animations->Get(702));		//Sit Attach right 9
	//this->animations.push_back(animations->Get(704));		//Attach on Jump Right 11
	//SetPosition(0.0f, 150.0f);
}

void Ninja::Attach()
{
	if (DefaultWeapon->GetisFinished() && isUsingExtraWeapon == 0)
	{
		DefaultWeapon->Attach();
	}
	if (ExtraWeapon != NULL)
	{
		if (ExtraWeapon->GetisFinished() && isUsingExtraWeapon == 1)
		{
			ExtraWeapon->Attach();
		}
	}
	
}

bool Ninja::getUntouchable()
{
	return this->untouchable;
}

void Ninja::CheckCollisionWithBrick(vector<LPGAMEOBJECT>* coObjects)
{
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
		isCollisionAxisYWithBrick = false;
		x += dx;
		y += dy;
		// đang ko va chạm trục y
	   //DebugOut(L"Khong Co Va Cham\n");
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{

			
				isCollisionAxisYWithBrick = true;
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

void Ninja::CheckCollisionWithEmemy(vector<LPGAMEOBJECT>* coObjects)// chua them sweepXAABB
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	vector<LPGAMEOBJECT> list_Enemy;
	list_Enemy.clear();
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (coObjects->at(i)->GetType() != eType::BRICK && coObjects->at(i)->GetType()!=eType::ButterFly)
			list_Enemy.push_back(coObjects->at(i));

	}
	

	for (UINT i = 0; i < list_Enemy.size(); i++)
	{

		if (AABBcollision(list_Enemy.at(i))&& list_Enemy.at(i)->GetHealth()!=0)
		{
			SubHealth(2);
			StartUntouchable();
			SetState(NINJA_STATE_BEING_HURT);
			return;
			//DebugOut(L"co va cham\n");
		}
	}

	
}

void Ninja::CheckCollisionWithItems()
{
	vector<LPGAMEOBJECT> listItem;
	ItemsManager::GetInstance()->GetListItem(listItem);

	for (auto x : listItem)
	{
		if (AABBcollision(x) && x->GetHealth() != 0)
		{
			x->SubHealth(1);
			switch (x->GetType())
			{
			case eType::Item_BlueShuriken:
				SAFE_DELETE(ExtraWeapon);
				ExtraWeapon = new CBlueShuriken();
				continue;
			case eType::Item_RedShuriken:
				SAFE_DELETE(ExtraWeapon);
				ExtraWeapon = new CRedShuriken();
				continue;
			case eType::Item_Blue_Point:
				this->Point += 500;
				continue;
			case eType::Item_Red_Point:
				this->Point += 1000;
				continue;
			case eType::Item_Heath:
				this->Health += 6;
			case eType::Item_Freeze_Time:
				continue;
			case eType::Item_BlueStack:
				this->NumberOfBullet += 5;
				continue;
			case eType::Item_RedStack:
				this->NumberOfBullet += 10;
				continue;
			}
		}
	}
}

void Ninja::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
		left = x;
		top = y;
		right = left + 16;
		bottom = top + 30;
}

Ninja * Ninja::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Ninja();
	}
	return _instance;
}


