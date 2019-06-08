#include "Camera.h"



CCamera * CCamera::_instance = NULL;

CCamera::~CCamera()
{
	
}



CCamera::CCamera(int width, int height)
{
	this->mWidth = width;
	this->mHeight = height;
	mPosition = D3DXVECTOR3(150, 104, 0);
}



void CCamera::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR3(x, y, 0));
}

void CCamera::SetPosition(D3DXVECTOR3 pos)
{
	if (pos.x < 128)
	{
		pos.x = 128;
	}
	if (pos.x > xEnd)
	{
		pos.x = xEnd;
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
	return D3DXVECTOR2(SCREEN_WIDTH / 2 - mPosition.x,
		SCREEN_HEIGHT / 2 - mPosition.y);
}

void CCamera::SetBounding(eType Map)
{
	switch (Map)
	{
	case eType::Map1:
		this->xEnd = 1905;
		break;
	case eType::Map2:
		this->xEnd = 2930;
		break;
	case eType::Map3:
		this->xEnd = 128;
		break;
	default:
		break;
	}
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
