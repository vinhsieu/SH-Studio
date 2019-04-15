#pragma once
#include <DirectXMath.h>
#include"Sprite.h"
#include"CGameObject.h"
class Camera
{
public:
	Camera(int width, int height, float angle,DirectX::XMFLOAT3 scaleFactors);
	~Camera();
	

	//Funtions
	void Update();
	void Follow(CGameObject * following);
	void Unfollow();
	bool isFollowing() const;
	void SetTransform(LPDIRECT3DDEVICE9 *gDevice) const;

private:
	float angle;
	DirectX::XMFLOAT3 scaleFactors;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;

	CGameObject* following;

	int width;
	int height;

};

