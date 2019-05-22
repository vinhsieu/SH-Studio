#include "BombGun.h"



CBombGun::CBombGun(float x, float y, int Direction)
{
	this->x =this->xBackup= x;
	this->y =this->yBackup= y;
	this->nx =this->nxBackup= Direction;
	this->vx = 0.0f;
	this->type = eType::BombGun;
	LoadAni();
}

void CBombGun::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(900, 383, 68, 415, 93, tex);
	sprites->Add(901, 414, 68, 444, 93, tex);
	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(200);
	ani->Add(900);
	ani->Add(901);
	animations->Add(1041, ani);
	AddAnimation(1041);
}

void CBombGun::Render()
{
	
	
		this->animations.at(0)->Render(this->x+BOMGUN_TO_CENTERX, this->y+BOMGUN_TO_CENTERY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
		if (IS_BBOX_DEBUGGING)
		{
			RenderBoundingBox(BOMGUN_TO_CENTERX,BOMGUN_TO_CENTERY);
		}
}

void CBombGun::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

void CBombGun::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 26;
	bottom = y + 26;
}




CBombGun::~CBombGun()
{
}
