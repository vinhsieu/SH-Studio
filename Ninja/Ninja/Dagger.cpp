#include "Dagger.h"






CDagger::CDagger(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	this->vx = DAGGER_SPEED_X;
	this->type = eType::Dagger;
	LoadAni();
}

void CDagger::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);
	
	sprites->Add(500, 409, 14, 437, 46,tex);
	sprites->Add(501, 444, 14, 473, 46,tex);
	sprites->Add(502, 491, 3, 515, 57, tex);

	LPANIMATION ani;
	//Di Binh Thuong
	ani = new CAnimation(100);
	ani->Add(500);
	ani->Add(501);
	animations->Add(1000, ani);
	//Danh
	ani = new CAnimation(100);
	ani->Add(501);
	ani->Add(502);
	animations->Add(1001, ani);
	AddAnimation(1000);
	AddAnimation(1001);
	

}

void CDagger::Render()
{
	
	if (isAttach = -1)
	{
		this->animations.at(0)->Render(this->x, this->y, isAttach, this->nx,CCamera::GetInstance()->Tranform());
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

void CDagger::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

void CDagger::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + 32;
	bottom = y + 32;
}

CDagger::~CDagger()
{
}
