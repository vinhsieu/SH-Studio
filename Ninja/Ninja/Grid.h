#pragma once
#include "CGameObject.h"
#include"Camera.h"
#include"define.h"
#include <fstream>

#include"Dagger.h"
#include"Blade.h"
#include"BombGun.h"
#include"BrownBird.h"
#include"Footballguy.h"
#include"GunRage.h"
#include"Panther.h"
#include"Brick.h"

#define GRID_CELL_MAX_ROW 1 // số dòng tối đa=MapHeight/GridCell
#define GRID_CELL_MAX_COLUMN 13 // số cột tối đa=MapWidth/GridCell

#define GRID_CELL_HEIGHT SCREEN_HEIGHT
#define GRID_CELL_WIDTH (SCREEN_WIDTH/2.0f)


class Grid
{
	vector<CGameObject *> cells[GRID_CELL_MAX_ROW][GRID_CELL_MAX_COLUMN];
	LPCWSTR gridPath;

public:
	Grid();
	void SetGridPath(LPCWSTR filePath);
	void ReadGrid();
	void BuildGrid();
	void ReloadOutOfCameraGrid(vector<LPGAMEOBJECT> ListObj);
	CGameObject *NewObject(int type,int direction, float x, float y, float w, float h);
	void Insert(int id, int type, int direction, float x, float y, int w, int h);
	void ListObject(vector<CGameObject*>& ListObj);

	~Grid();
};

