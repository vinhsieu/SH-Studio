#include "Camera.h"



CCamera * CCamera::_instance = NULL;

CCamera::~CCamera()
{
	
}



CCamera::CCamera(int width, int height)
{
	this->mWidth = width;
	this->mHeight = height;
	mPosition = D3DXVECTOR3(150, 130, 0);
}



void CCamera::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR3(x, y, 0));
}

void CCamera::SetPosition(D3DXVECTOR3 pos)
{
	if (pos.x < 160)
	{
		pos.x = 160;
	}
	pos.x = (int)pos.x;
	pos.y = (int)pos.y;
	mPosition = pos;
}

CCamera * CCamera::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new CCamera(SCREEN_WIDTH,SCREEN_HEIGHT);
	}
	return _instance;
}

D3DXVECTOR2 CCamera::Tranform()
{
	return D3DXVECTOR2(320 / 2 - mPosition.x,
		208 / 2 - mPosition.y);
}


int CCamera::GetWidth()
{
	return mWidth;
}

int CCamera::GetHeight()
{
	return mHeight;
}


D3DXVECTOR3 CCamera::GetPosition()
{
	return mPosition;
}

RECT CCamera::GetBound()
{
	RECT bound;

	bound.left = mPosition.x - mWidth / 2;
	bound.right = bound.left + mWidth;;
	bound.top = mPosition.y - mHeight / 2;
	bound.bottom = bound.top + mHeight;

	return bound;
}
