#include "Grid.h"
#include"CGame.h"


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

void Grid::BuildGrid()//Save grid(chua lam)
{
	string gridPath;

}

void Grid::ReloadOutOfCameraGrid(vector<LPGAMEOBJECT> ListObj)
{
		for (int j = 0; j < GRID_CELL_MAX_COLUMN; j++)
		{
				for (int k = 0; k < cells[0][j].size(); k++)
				{
					if (cells[0][j].at(k)->GetType() != eType::BRICK)
					{
					 bool isExsting = false;
					 for (auto x : ListObj)
					 {
						if (x->GetID() == cells[0][j].at(k)->GetID())
						{
							isExsting = true;
						}
					 }
					 if (!isExsting)
					 {
						cells[0][j].at(k)->SetDefault();
					    //DebugOut(L"Co Set Default\n");
					 }
					}
				}
		}

}


CGameObject * Grid::NewObject(int type,int direction, float x, float y, float w, float h)
{
	switch (type)
	{
		case eType::Dagger:
			return new CDagger(x, y, direction);
		case eType::BombGun:
			return new CBombGun(x, y, direction);
		case eType::Blade:
			return new CBlade(x, y, direction);
		case eType::BrownBird:
			return new CBrownBird(x, y, direction);
		case eType::Footballguy:
			return new CFootballguy(x, y, direction);
		case eType::GunRage:
			return new CGunRage(x, y, direction);
		case eType::Panther:
			return new CPanther(x, y, direction);
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

	CGameObject * obj = NewObject(type,direction, x, y, w, h);
	if (obj == NULL)
	{
		return;
	}
	obj->SetID(id);
	//obj->SetDirection(direction);

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
	CCamera *camera = CCamera::GetInstance();
	int bottom = (int)((camera->GetPosition().y + camera->GetHeight() / 2 - 1) / GRID_CELL_HEIGHT);
	int top = (int)((camera->GetPosition().y - camera->GetHeight() / 2) / GRID_CELL_HEIGHT);

	int left = (int)((camera->GetPosition().x - camera->GetWidth() / 2) / GRID_CELL_WIDTH);
	int right = (int)((camera->GetPosition().x + camera->GetWidth() / 2 - 1) / GRID_CELL_WIDTH);
	



	unordered_map<int, CGameObject*> mapObject;
	vector<CGameObject* > listnow; //Update Obj Di Chuyen
	listnow = ListObj;
	ListObj.clear();
	
	for (auto x : listnow)
	{
		RECT gObj;
		float gLeft, gTop, gRight, gBottom;
		x->GetBoundingBox(gLeft, gTop, gRight, gBottom);
		gObj.left = gLeft;
		gObj.top = gTop;
		gObj.right = gRight;
		gObj.bottom = gBottom;
		if (CGame::GetInstance()->isContain(camera->GetBound(), gObj))
		{
			mapObject[x->GetID()] = x;
		}
	}

	
	

	for (int i = top; i <= bottom; i++)//Theo Hang
	{
		for (int j = left; j <= right; j++)//Theo cot
			for (int k = 0; k < cells[i][j].size(); k++)
			{
				//if (cells[i][j].at(k)->GetHealth() > -1) // kiem tra con mau hay khong
				//{
					if (mapObject.find(cells[i][j].at(k)->GetID()) == mapObject.end()) // Kiem tra da them vao mapObject hay chua
						mapObject[cells[i][j].at(k)->GetID()] = cells[i][j].at(k);
				//}
			}
	}
	
	

	for (auto& x : mapObject)
	{
		ListObj.push_back(x.second);
	}
	ReloadOutOfCameraGrid(ListObj);
}


Grid::~Grid()
{
}
