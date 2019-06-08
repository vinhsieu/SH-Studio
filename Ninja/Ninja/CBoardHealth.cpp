#include "CBoardHealth.h"

CBoardHealth * CBoardHealth::_instance = NULL;

CBoardHealth::CBoardHealth()
{
	LoadSprite();
}


CBoardHealth::~CBoardHealth()
{
}

void CBoardHealth::Draw(int HealthPlayer, int HealthEnemy)
{
	int y = 12;
	int x = 160;
	HealthPlayer = min(HealthPlayer, 16);
	HealthEnemy = min(HealthEnemy, 16);
	CSprites * sprites = CSprites::GetInstance();
	int i, j;
	for (i = 0; i < HealthPlayer; i++)
	{
		sprites->Get(301)->Draw(x + i * CELL_TO_CENTER_X * 2 + CELL_TO_CENTER_X, y + CELL_TO_CENTER_Y,0, D3DXVECTOR2(0, 0));
	}
	for (j = i; j < MAX_HEALTH; j++)
	{
		sprites->Get(302)->Draw(x + j * CELL_TO_CENTER_X * 2 + CELL_TO_CENTER_X, y + CELL_TO_CENTER_Y, 0, D3DXVECTOR2(0, 0));
	}

	
	for (i = 0; i < HealthEnemy; i++)
		sprites->Get(301)->Draw(x + i * CELL_TO_CENTER_X * 2 + CELL_TO_CENTER_X, y + 9 + CELL_TO_CENTER_Y, 0, D3DXVECTOR2(0, 0));

	for (j = i; j < MAX_HEALTH; j++)
	{
		sprites->Get(302)->Draw(x + j * CELL_TO_CENTER_X * 2 + CELL_TO_CENTER_X, y + 9 + CELL_TO_CENTER_Y, 0, D3DXVECTOR2(0, 0));
	}

}

CBoardHealth * CBoardHealth::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new CBoardHealth();
	}
	return _instance;
}

void CBoardHealth::LoadSprite()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::NOHP);
	LPDIRECT3DTEXTURE9 tex2 = texture->Get(eType::HP);
	sprites->Add(301, 0, 0, 5, 7, tex2);//Co mau

	sprites->Add(302, 0, 0, 5, 7, tex);//Khong Co Mau
}
