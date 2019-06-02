#include "CBoard.h"

CBoard * CBoard::_instance = NULL;

CBoard::CBoard()
{
	this->y = 15;
	board = CGame::GetInstance()->LoadSurface("Resources\\Board\\Board.png",NULL);
	LoadAni();
}

void CBoard::Render()
{
	RECT p,des2;
	p.top = p.left = 0;
	p.right = 333;
	p.bottom = 33;
	des2.top = des2.left = 0;
	des2.right = 150;
	des2.bottom = 50;
	LPDIRECT3DDEVICE9 d3ddv = CGame::GetInstance()->GetDirect3dDevice();
	LPDIRECT3DSURFACE9 bb = CGame::GetInstance()->Getbackbuffer();
	d3ddv->StretchRect(board, &p, bb, &des2, D3DTEXF_NONE);
	//CSprites::GetInstance()->Get(300)->Draw(this->x, this->y, 0, CCamera::GetInstance()->Tranform());
}

void CBoard::Update()
{
	this->x = (int)CCamera::GetInstance()->GetPosition().x+20;
}

void CBoard::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Board);

	sprites->Add(300, 0, 0, 333,33,tex);
}

CBoard * CBoard::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new CBoard();
	}
	return _instance;
}


CBoard::~CBoard()
{
}
