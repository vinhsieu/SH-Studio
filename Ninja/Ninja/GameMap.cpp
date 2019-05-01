#include "GameMap.h"



GameMap::GameMap(LPCWSTR filename, LPCWSTR matrixName)
{
	LoadMap(filename, NULL);
	LoadMatrix(matrixName);
}


void GameMap::SetCamera(Camera * camera)
{
	this->mCamera = camera;
}

void GameMap::Draw()
{	CGame * game = CGame::GetInstance();
	DebugOut(L"[INFO] Toa Do BackGround: %f\n", mCamera->GetPosition().x);

	CSprites * sprites = CSprites::GetInstance();
	if (matrix.empty())
	{
		return;
	}

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			int x=j*16+8;
			int y=i*16+8;
			sprites->Get(matrix[i][j] + ID_TEX_MAP)->Draw(x, y, 0);
		}
	}
}

void GameMap::LoadMap(LPCWSTR filename, D3DCOLOR transcolor)
{
	
	D3DXIMAGE_INFO info;
	HRESULT result;

	result = D3DXGetImageInfoFromFile(filename, &info);
	if (result != D3D_OK)
	{
		return;
	}


	this->tileHeight = info.Height / 16;
	this->tileWidth = info.Width / 16;

	CTexture * texture = CTexture::GetInstance();
	texture->Add(ID_TEX_MAP, filename,NULL);
	CSprites * sprites = CSprites::GetInstance();

	LPDIRECT3DTEXTURE9 texMAP = texture->Get(ID_TEX_MAP);

	for (int i = 0; i < this->tileHeight*this->tileWidth; i++)
	{
		int left = (i % this->tileWidth) * 16;
		int right = left + 16;
		int top = (i / this->tileWidth) * 16;
		int bottom = top + 16;
		
		sprites->Add(ID_TEX_MAP+i, left, top, right, bottom, texMAP);
		
	}

}

void GameMap::LoadMatrix(LPCWSTR filePath)
{
	
	
	ifstream file;
	file.open(filePath);
	if (file.fail()) 
	{
		return;
	}

	int n = 0;
	while (n < 13) {
		n++;
		vector<int>a;

		int aa = 0;
		while (aa != -1) {
			file >> aa;
			if (aa != -1)
				a.push_back(aa);
		}
		matrix.push_back(a);
		DebugOut(L"[INFO]  matrix xong\n");
	}
	
}

GameMap::~GameMap()
{
}

