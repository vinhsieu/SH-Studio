#include "GameMap.h"
#include"CGame.h"


GameMap::GameMap(eType idMap, LPCWSTR matrixName)
{
	this->idMap = idMap;
	LoadMap(idMap, NULL);
	LoadMatrix(matrixName);
}




void GameMap::Draw()
{	CGame * game = CGame::GetInstance();
	//DebugOut(L"[INFO] Toa Do BackGround: %f\n", mCamera->GetPosition().x);

	mCamera = CCamera::GetInstance();
	
	CSprites * sprites = CSprites::GetInstance();
	//DebugOut(L"[INFO]Toa Do Camera: %f, %f\n", mCamera->GetPosition().x, mCamera->GetPosition().y);
	if (matrix.empty())
	{
		return;
	}

	for (int i = 0; i < matrix.size(); i++)// hang
	{
		for (int j = 0; j < matrix[i].size()-1; j++)// cot
		{
			D3DXVECTOR3 position(j * tileSize /*+tileSize/2*/, i * tileSize/*+tileSize / 2*/, 0);
			if (mCamera != NULL)
			{
				RECT objRECT;
				objRECT.left = position.x/*- tileSize / 2*/;
				objRECT.top = position.y/*- tileSize / 2*/;
				objRECT.right = objRECT.left + tileSize /*/ 2*/;
				objRECT.bottom = objRECT.top + tileSize /*/ 2*/;

				//neu nam ngoai camera thi khong Draw
				if (CGame::GetInstance()->isContain(objRECT, mCamera->GetBound()) == false)
					continue;
			}
			sprites->Get(matrix[i][j] + idMap*20)->Draw(position.x + tileSize / 2, position.y + tileSize / 2, 0, mCamera->Tranform());

			//DebugOut(L"[INFO]Toa Do Back Ground: %f, %f\n", position.x, position.y);

			//DebugOut(L"[INFO]Toa Do Camera: %f, %f\n", mCamera->GetPosition().x, mCamera->GetPosition().y);
		}
	} 
	
}



void GameMap::LoadMap(eType idMap, D3DCOLOR transcolor)
{
	
	D3DXIMAGE_INFO info;
	HRESULT result;

	/*result = D3DXGetImageInfoFromFile(filename, &info);
	if (result != D3D_OK)
	{
		return;
	}*/

	
	CSprites * sprites = CSprites::GetInstance();
	CTexture * texture = CTexture::GetInstance();
	this->numtileHeight = 13;
	this->numtileWidth = 80 ;
	LPDIRECT3DTEXTURE9 texMAP = texture->Get(idMap);

	for (int i = 0; i < this->numtileHeight*this->numtileWidth; i++)
	{
		int left = (i % this->numtileWidth) * 16;
		int right = left + 16;
		int top = (i / this->numtileWidth) * 16;
		int bottom = top + 16;
		
		sprites->Add((int)idMap*20 + i, left, top, right, bottom, texMAP);
		
		
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
		
	}
	

	//DebugOut(L"[INFO]  matrix xong\n");

}

GameMap::~GameMap()
{
}

