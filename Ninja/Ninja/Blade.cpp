#include "Blade.h"
#include"Ninja.h"

CBlade::CBlade(float x, float y, int Direction, int xStart, int xEnd)
{
	CGameObject::CGameObject();
	this->xStart = xStart;
	this->xEnd = xEnd;
	this->isActive = false;
	this->x =this->xBackup= x;
	this->y =this->yBackup= y;
	this->nx =this->nxBackup= Direction;
	this->HealthBackup = this->Health;
	this->type = eType::Blade;
	this->vx = BLADE_VX;
	LoadAni();
}

void CBlade::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(700, 209, 60, 241, 92, tex);
	sprites->Add(701, 240, 60, 270, 92, tex);
	sprites->Add(702, 282, 52, 300, 99, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(700);
	ani->Add(701);
	ani->Add(702);
	animations->Add(1021, ani);
	AddAnimation(1021);
}

void CBlade::Render()
{
	if (this->Health == 0||!isActive)
	{
		return;
	}
	this->animations.at(0)->Render(this->x + BLADE_TO_CENTERX, this->y + BLADE_TO_CENTERY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	

	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BLADE_TO_CENTERX, BLADE_TO_CENTERY);
	}
	//DebugOut(L"x= %f,y= %f,nx=%d\n", this->x, this->y,this->nx);
	
}

void CBlade::Update(DWORD dt)
{
	float xNinja, yNinja;
	Ninja::GetInstance()->GetPosition(xNinja, yNinja);
	if (((this->x - xNinja)*nx < 0 && fabs(this->x - xNinja) < BLADE_ACTIVE_AREA))
	{
		isActive = true;
	}
	if (!isActive)
	{
		return;
	}
	if (this->Health == 0)
	{
		return;
	}
	if (x - xStart < 0 || x + 18 - xEnd>0)
	{
		nx *= -1;
	}
	if (nx*vx<0 )
	{
		vx *= -1;
	}
	CGameObject::Update(dt);
	x = x + dx;
	y = y + dy;
}

void CBlade::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 18;
	bottom = y + 33;
}

void CBlade::SubHealth(int th)
{
	if (this->Health != 0)
	{
		EffectManager::GetInstance()->AddEffect(this->x, this->y, BLADE_TO_CENTERX * 2, BLADE_TO_CENTERY * 2);
	}
	CGameObject::SubHealth(th);
	

}




CBlade::~CBlade()
{
}
