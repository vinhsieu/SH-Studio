#include "Camera.h"





Camera::~Camera()
{
}



Camera::Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors)
{
	this->mWidth = width;
	this->mHeight = height;
	this->angle = angle;
	this->scaleFactors = scaleFactors;

	D3DXMatrixOrthoLH(&orthographicMatrix, width, -height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);
}

void Camera::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR3(x, y, 0));
}

void Camera::SetPosition(D3DXVECTOR3 pos)
{
	mPosition = pos;
}

void Camera::Following(Ninja * following)
{
	this->mNinja = following;
}

void Camera::UnFollowing()
{
	this->mNinja = nullptr;
}

void Camera::SetTransform(CGame * game)
{
	/*if (mNinja == nullptr)
	{
		return;
	}*/
	game->GetDirect3dDevice()->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	//game->GetDirect3dDevice()->SetTransform(D3DTS_WORLD, &identityMatrix);
	game->GetDirect3dDevice()->SetTransform(D3DTS_VIEW, &viewMatrix);
}

void Camera::Update()
{
	if (mNinja == nullptr)
	{
		return;
	}
	float cameraX = this->mWidth / 2, cameraY = this->mHeight / 2;
	if (this->mNinja)
	{
		this->mNinja->GetPosition(cameraX, cameraY);
		//cameraX += 50;
		cameraY =100;
		
	}
	
	if (cameraX < 160)
	{
		cameraX = 160;
	}
	this->mPosition.x = cameraX;
	this->mPosition.y = 100;
	DebugOut(L"[INFO] Toa Do Camera: %f, %f\n", cameraX, cameraY);
	this->viewMatrix = D3DXMATRIX(
		scaleFactors.x * cos(angle), scaleFactors.x * sin(angle), 0, 0,
		-scaleFactors.y * sin(angle), scaleFactors.y * cos(angle), 0, 0,
		0, 0, scaleFactors.z, 0,
		-cameraX * scaleFactors.x * cos(angle) + cameraY * scaleFactors.y * sin(angle), -cameraX * scaleFactors.y * sin(angle) - cameraY * scaleFactors.y * cos(angle), 0, 1
	);
}

int Camera::GetWidth()
{
	return mWidth;
}

int Camera::GetHeight()
{
	return mHeight;
}

bool Camera::IsFollowing() const
{
	return this->mNinja != nullptr;
}

D3DXVECTOR3 Camera::GetPosition()
{
	return mPosition;
}

RECT Camera::GetBound()
{
	RECT bound;

	bound.left = mPosition.x - mWidth / 2;
	bound.right = bound.left + mWidth;;
	bound.top = mPosition.y - mHeight / 2;
	bound.bottom = bound.top + mHeight;

	return bound;
}
