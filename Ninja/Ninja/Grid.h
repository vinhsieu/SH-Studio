#pragma once
#include "CGameObject.h"
#include"Camera.h"
#include"define.h"

#include <fstream>
#define GRID_CELL_MAX_ROW 20 // số dòng tối đa;
#define GRID_CELL_MAX_COLUMN 100 // số cột tối đa

#define GRID_CELL_HEIGHT (SCREEN_HEIGHT/4.0f)
#define GRID_CELL_WIDTH (SCREEN_WIDTH/4.0f)


class Grid
{
	vector<CGameObject *> cells[GRID_CELL_MAX_ROW][GRID_CELL_MAX_COLUMN];
	LPCWSTR filePath;

public:
	Grid();
	void SetFile(LPCWSTR filePath);
	void ReloadGrid();

	CGameObject *GetNewObject(int type, float x, float y, float w, float h, int model);
	void Insert(int id, int type, int direction, float x, float y, int w, int h, int Model);
	void GetListObject(vector<CGameObject*>& ListObj, CCamera *Camera);

	~Grid();
};

