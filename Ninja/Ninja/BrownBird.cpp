#include "BrownBird.h"






CBrownBird::CBrownBird(float x, float y, int Direction)
{
	this->x = x;
	this->y = y;
	this->nx = Direction;
	//this->vx = DAGGER_SPEED_X;
	this->type = eType::BrownBird;
	LoadAni();
}

void CBrownBird::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Ememy_Texture);
	sprites->Add(600, 478, 73, 494, 90, tex);
	sprites->Add(601, 504, 59, 523, 95, tex);
	LPANIMATION ani;
	//Bay
	ani = new CAnimation(100);
	ani->Add(600);
	ani->Add(601);
	animations->Add(1011, ani);
	AddAnimation(1011);
}

void CBrownBird::Render()
{
	
	this->animations.at(0)->Render(this->x+BROWNBIRD_TO_CENTERX, this->y+BROWNBIRD_TO_CENTERY, isAttach, this->nx, CCamera::GetInstance()->Tranform());
	if (IS_BBOX_DEBUGGING)
	{
		RenderBoundingBox(BROWNBIRD_TO_CENTERX,BROWNBIRD_TO_CENTERY);
	}
}

void CBrownBird::Update(DWORD dt)
{
	CGameObject::Update(dt);
}

void CBrownBird::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x +18;
	bottom = y + 15;
}

CBrownBird::~CBrownBird()
{
}
