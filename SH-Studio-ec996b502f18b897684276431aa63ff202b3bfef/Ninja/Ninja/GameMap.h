#pragma once
#include"Camera.h"
#include"CGame.h"
class GameMap
{
public:
	GameMap(LPCWSTR filename);

	int GetWidth();
	int GetHeight();
	int GetTileWidth();
	int GetTileHeight();

	void SetCamera(Camera *camera);
	void Draw();
private:
	void LoadMap(LPCWSTR filePath, D3DCOLOR transcolor);
	LPDIRECT3DTEXTURE9 mMap;
	Camera *mCamera;
	~GameMap();
};

