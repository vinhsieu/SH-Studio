#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include <DirectXMath.h>
#include"debug.h"
#include"define.h"

class CCamera
{
	
	int mWidth;
	int mHeight;
	 
	float xEnd;
	static CCamera * _instance;


	D3DXVECTOR3 mPosition;
	
public:
	CCamera(int width, int height);;

	//center of camera
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR3 pos);

	static CCamera * GetInstance();
	D3DXVECTOR2 Tranform();
	void SetBounding(eType Map);
	int GetWidth();
	int GetHeight();
	//bool IsFollowing() const;
	D3DXVECTOR3 GetPosition();
	RECT GetBound();

	~CCamera();
};

