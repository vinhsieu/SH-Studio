#include "Grid.h"



Grid::Grid()
{
}

void Grid::SetGridPath(LPCWSTR filePath)
{
	this->gridPath = filePath;
	ReadGrid();
}

void Grid::ReadGrid()
{
	for (int i = 0; i < GRID_CELL_MAX_ROW; i++)
	{
		for (int j = 0; j < GRID_CELL_MAX_COLUMN; j++)
		{
			cells[i][j].clear();
		}
	}

	int id, type, direction, w, h, n;
	float x, y;

	ifstream inp(gridPath, ios::in);
	inp >> n;
	for (int i = 0; i < n; i++)
	{
		inp >> id >> type >> direction >> x >> y >> w >> h;
		Insert(id, type, direction, x, y, w, h);
	}
	inp.close();
}




CGameObject * Grid::NewObject(int type, float x, float y, float w, float h)
{
	switch (type)
	{
		case eType::Dagger:
			return new CDagger(x, y, 1);
		case eType::BombGun:
			return new CBombGun(x, y, 1);
		case eType::Blade:
			return new CBlade(x, y, 1);
		case eType::BrownBird:
			return new CBrownBird(x, y, 1);
		case eType::Footballguy:
			return new CFootballguy(x, y, 1);
		case eType::GunRage:
			return new CGunRage(x, y, 1);
		case eType::Panther:
			return new CPanther(x, y, 1);
		case eType::BRICK:
			return new CBrick(x, y, w, h);
	}
}

void Grid::Insert(int id, int type, int direction, float x, float y, int w, int h)
{
	int top = (int)(y / GRID_CELL_HEIGHT);
	int bottom = (int)((y + h) / GRID_CELL_HEIGHT);
	int left = (int)(x / GRID_CELL_WIDTH);
	int right = (int)((x + w) / GRID_CELL_WIDTH);

	CGameObject * obj = NewObject(type, x, y, w, h);
	if (obj == NULL)
	{
		return;
	}
	obj->SetID(id);
	obj->SetDirection(direction);

	for (int i = top; i <= bottom; i++)
	{
		for (int j = left; j <= right; j++)
		{
			cells[i][j].push_back(obj);
		}
	}
}

void Grid::ListObject(vector<CGameObject*>& ListObj)
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
