#pragma once
#include<unordered_map>
#include<d3dx9.h>

using namespace std;


class CTexture
{
	static CTexture * _instance;
	unordered_map <int, LPDIRECT3DTEXTURE9> texture;

public:
	CTexture();
	void Add(int id, LPCWSTR texturePath, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 Get(unsigned int id);
	static CTexture* GetInstance();

	~CTexture();
};

