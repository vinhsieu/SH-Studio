#pragma once
#include<unordered_map>
#include<d3dx9.h>
#include"define.h"
using namespace std;

#define DEFAULT_TRANS_COLOR D3DCOLOR_XRGB(255, 163, 177)
class CTexture
{
	static CTexture * _instance;
	unordered_map <eType, LPDIRECT3DTEXTURE9> texture;

public:
	CTexture();
	void Add(eType id, LPCWSTR texturePath, D3DCOLOR transparentColor= DEFAULT_TRANS_COLOR );
	void LoadTexTure();
	LPDIRECT3DTEXTURE9 Get(eType id);
	static CTexture* GetInstance();

	~CTexture();
};

