#include "Texture.h"
#include<d3d9.h>
#include"CGame.h"
#include<Windows.h>


CTexture::CTexture()
{
}

void CTexture::Add(int id, LPCWSTR texturePath, D3DCOLOR transparentColor)
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
		transparentColor,
		&info,
		NULL,
		&texture
	);
	if (result != D3D_OK)
	{
		return;
	}
	this->texture[id] = texture;



}

LPDIRECT3DTEXTURE9 CTexture::Get(unsigned int id)
{
	return this->texture[id];
}
CTexture * CTexture::_instance = NULL;
CTexture * CTexture::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new CTexture();
	}
	return _instance;
}


CTexture::~CTexture()
{
}
