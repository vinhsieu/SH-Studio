#pragma once
#include"Camera.h"
#include <iostream>
#include <fstream>
#include <string>
#include"CGame.h"
#include"Texture.h"

#define ID_TEX_MAP 2000

using namespace std;
class GameMap
{
public:
	GameMap(LPCWSTR filename,  LPCWSTR matrixName);

	int GetWidth();
	int GetHeight();
	int GetTileWidth();
	int GetTileHeight();
	vector<vector<int>> matrix;
	void SetCamera(Camera *camera);
	void Draw();
	int tileWidth, tileHeight;

private:
	void LoadMap(LPCWSTR filePath, D3DCOLOR transcolor);
	void LoadMatrix(LPCWSTR filePath);
	LPDIRECT3DSURFACE9 mMap;
	Camera *mCamera;
	~GameMap();
};

