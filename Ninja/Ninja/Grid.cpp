#include "Grid.h"



Grid::Grid()
{
}

void Grid::SetFile(LPCWSTR filePath)
{
	this->filePath = filePath;
}

void Grid::ReloadGrid()
{
	for (int i = 0; i < GRID_CELL_MAX_ROW; i++)
		for (int j = 0; j < GRID_CELL_MAX_COLUMN; j++)
		{
			cells[i][j].clear();
		}


	int id, type, direction, w, h, model, n;
	float x, y;

	ifstream inp(filePath, ios::in);
	inp >> n;
	for (int i = 0; i < n; i++)
	{
		inp >> id >> type >> direction >> x >> y >> w >> h /*>> model*/;
		Insert(id, type, direction, x, y, w, h, NULL);
	}
	inp.close();
}




CGameObject * Grid::GetNewObject(int type, float x, float y, float w, float h, int model)
{
	switch (type)
	{
		case eType::Dagger:
			return new CDagger(x, y, 1);
		case eType::BombGun:
			return new CBombGun(x, y, 1);
	}
}

void Grid::Insert(int id, int type, int direction, float x, float y, int w, int h, int Model)
{
	int top = (int)(y / GRID_CELL_HEIGHT);
	int bottom = (int)((y + h) / GRID_CELL_HEIGHT);
	int left = (int)(x / GRID_CELL_WIDTH);
	int right = (int)((x + w) / GRID_CELL_WIDTH);

	CGameObject * obj = GetNewObject(type, x, y, w, h, Model);
	if (obj == NULL)
		return;

	obj->SetID(id);
	obj->SetDirection(direction);

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			cells[i][j].push_back(obj);
}

void Grid::GetListObject(vector<CGameObject*>& ListObj)
{
	ListObj.clear();

	unordered_map<int, CGameObject*> mapObject;
	CCamera *camera = CCamera::GetInstance();
	int bottom = (int)((camera->GetPosition().y + camera->GetHeight()/2 - 1) / GRID_CELL_HEIGHT);
	int top = (int)((camera->GetPosition().y - camera->GetHeight() / 2 + 1) / GRID_CELL_HEIGHT);

	int left = (int)((camera->GetPosition().x- camera->GetWidth()/2 + 1) / GRID_CELL_WIDTH);
	int right = (int)((camera->GetPosition().x + camera->GetWidth()/2 - 1) / GRID_CELL_WIDTH);

	for (int i = top; i <= bottom; i++)//Theo Cột
	{
		for (int j = left; j <= right; j++)//Theo Hàng
			for (int k = 0; k < cells[i][j].size(); k++)
			{
				if (cells[i][j].at(k)->GetHealth() > 0) // còn tồn tại
				{
					if (mapObject.find(cells[i][j].at(k)->GetID()) == mapObject.end()) // ko tìm thấy
						mapObject[cells[i][j].at(k)->GetID()] = cells[i][j].at(k);
				}
				else
				{
					//	cells[i][j].erase(cells[i][j].begin() + k); // xóa luôn
				}
			}
	}
	for (auto& x : mapObject)
	{
		ListObj.push_back(x.second);
	}
}


Grid::~Grid()
{
}
