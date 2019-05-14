#include "GunRage.h"



CGunRage::CGunRage(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::GunRage;
	LoadAni();
}

void CGunRage::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);

	sprites->Add(1100, 58, 60, 74, 92, tex);
	sprites->Add(1101, 83, 60, 101, 92, tex);
	sprites->Add(1102, 127, 60, 157, 92, tex);
	sprites->Add(1103, 159, 60, 187, 92, tex);

	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(1100);
	ani->Add(1101);
	animations->Add(1061, ani);
	AddAnimation(1061);
}

void CGunRage::Render()
{
	
	if (isAttach = -1)
	{
		this->animations.at(0)->Render(this->x, this->y, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	}
	else
	{
		this->animations.at(1)->Render(this->x, this->y, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	}
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox();
	}
}

void CGunRage::Update(DWORD dt)
{
	CGameObject::Update(dt);
}


CGunRage::~CGunRage()
{
}
