#include "GameMap.h"



GameMap::GameMap(LPCWSTR filename)
{
	LoadMap(filename, NULL);
}


void GameMap::SetCamera(Camera * camera)
{
	this->mCamera = camera;
}

void GameMap::Draw()
{
	D3DXVECTOR2 trans = D3DXVECTOR2(320 / 2 - mCamera->GetPosition().x,
		240 / 2 - mCamera->GetPosition().y);
	CGame * game = CGame::GetInstance();
	game->Draw(mCamera->GetPosition().x, mCamera->GetPosition().y, mMap, mCamera->GetPosition().x - 160, 33, mCamera->GetPosition().x + 160, 208, NULL);
}

void GameMap::LoadMap(LPCWSTR texturePath, D3DCOLOR transcolor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &info);
	if (result != D3D_OK)
	{
		return;
	}
	LPDIRECT3DDEVICE9 d3ddv = CGame::GetInstance()->GetDirect3dDevice();
	LPDIRECT3DTEXTURE9 texture;
	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		texturePath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transcolor,
		&info,
		NULL,
		&texture
	);
	if (result != D3D_OK)
	{
		return;
	}
	this->mMap = texture;
}

GameMap::~GameMap()
{
}

