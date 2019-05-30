#pragma once
#include"Camera.h"
#include <iostream>
#include <fstream>
#include <string>
#include"CGame.h"
#include"Texture.h"
#include"Sprite.h"

#define ID_TEX_MAP 2000

using namespace std;
class GameMap
{
public:
	GameMap(eType idMap,  LPCWSTR matrixName);
	eType idMap;
	int GetWidth();
	int GetHeight();
	int GetTileWidth();
	int GetTileHeight();
	vector<vector<int>> matrix;
	//void SetCamera(Camera *camera);
	void Draw();
	int numtileWidth,numtileHeight;
	int tileSize = 16;
	

private:
	void LoadMap(eType idMap, D3DCOLOR transcolor);
	void LoadMatrix(LPCWSTR filePath);
	LPDIRECT3DSURFACE9 mMap;
	CCamera * mCamera;
	~GameMap();
};

