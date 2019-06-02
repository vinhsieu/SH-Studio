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
#include"BlackBird.h"
#include"Butterfly.h"
#include"Stairs.h"

#define GRID_CELL_MAX_ROW 1 // số dòng tối đa=MapHeight/GridCell
#define GRID_CELL_MAX_COLUMN 30 // số cột tối đa=MapWidth/GridCell

#define GRID_CELL_HEIGHT SCREEN_HEIGHT
#define GRID_CELL_WIDTH (SCREEN_WIDTH/2.0f)


class Grid
{
	vector<CGameObject *> cells[GRID_CELL_MAX_ROW][GRID_CELL_MAX_COLUMN];
	LPCWSTR gridPath;
	

	static Grid * _instance;
public:
	Grid();
	static Grid * GetInstance();
	void SetGridPath(LPCWSTR filePath);
	void ReadGrid();
	void BuildGrid();
	void Clear();
	void AddObj(int idHost,CWeapon* objHost);
	void ReloadOutOfCameraGrid(vector<LPGAMEOBJECT> ListObj);
	CGameObject *NewObject(int id,int type,int direction, float x, float y, float w, float h, float xStart, float xEnd);
	void Insert(int id, int type, int direction, float x, float y, int w, int h, float xStart, float xEnd);
	void ListObject(vector<CGameObject*>& ListObj);

	~Grid();
};

