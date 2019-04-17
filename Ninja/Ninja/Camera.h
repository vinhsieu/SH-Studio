#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include <DirectXMath.h>
#include"Ninja.h"
#include"debug.h"
class Camera
{
	int mWidth;
	int mHeight;

	Ninja *mNinja;

	D3DXVECTOR3 mPosition;
	float angle;
	DirectX::XMFLOAT3 scaleFactors;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;
public:
	Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors);


	//center of camera
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR3 pos);



	void Following(Ninja *following);
	void UnFollowing();
	void SetTransform(CGame * game);
	void Update();

	int GetWidth();
	int GetHeight();
	bool IsFollowing() const;
	D3DXVECTOR3 GetPosition();
	RECT GetBound();

	~Camera();
};

