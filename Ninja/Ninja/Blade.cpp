#include "Blade.h"



CBlade::CBlade(float x, float y, int Direction)
{
	CGameObject::CGameObject();
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
	if (this->Health == 0)
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
	if (this->Health == 0)
	{
		return;
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
	right = x + 22;
	bottom = y + 33;
}




CBlade::~CBlade()
{
}
