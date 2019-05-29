#include "Items.h"



Items::Items()
{
}

Items::Items(float x, float y)
{
	TimeDisplayed = 0;
	TimeDisplayMax = 0;
	isFinished = false;
}

void Items::Update(DWORD dt, vector<LPGAMEOBJECT>* listObject)
{
	if (this->Health == 0)
	{
		isFinished = true;
		return;
	}
	TimeDisplayed += dt;
	if (TimeDisplayed >= TimeDisplayMax)
	{
		isFinished = true;
		return;
	}

	vy += Item_GRAVITY * dt;
	CGameObject::Update(dt);
	vector<LPGAMEOBJECT> listObject_Brick;
	listObject_Brick.clear();
	for (UINT i = 0; i < listObject->size(); i++)
		if (listObject->at(i)->GetType() == eType::BRICK)
			listObject_Brick.push_back(listObject->at(i));

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;
	coEvents.clear();
	CalcPotentialCollisions(&listObject_Brick, coEvents); // Lấy danh sách các va chạm 
	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		y += min_ty * dy + ny * 0.4f;
		if (ny != 0)
		{
			vy = 0;
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
}

void Items::Render()
{
}

bool Items::getIsFinished()
{
	return this->isFinished;
}


Items::~Items()
{
}
