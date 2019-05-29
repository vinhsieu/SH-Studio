#include "CGame.h"
#include"debug.h"


CGame * CGame::_instance = NULL;


bool CGame::isContain(RECT rect1, RECT rect2)
{
	if (rect1.left > rect2.right || rect1.right < rect2.left || rect1.top > rect2.bottom || rect1.bottom < rect2.top)
	{
		return false;
	}

	return true;
}

void CGame::Init(HWND hWnd)
{
	LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);
	this->hWnd = hWnd;
	D3DPRESENT_PARAMETERS d3dpp;


	ZeroMemory(&d3dpp, sizeof(d3dpp));
		
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;

	RECT r;
	GetClientRect(hWnd, &r);	// retrieve Window width & height 

	d3dpp.BackBufferHeight = r.bottom + 1;
	d3dpp.BackBufferWidth = r.right + 1;

	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);

	if (d3ddev == NULL)
	{
		MessageBox(hWnd, L"Init d3ddev errors", L"Error", MB_OK);
		return;
	}
	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);
	back = LoadSurface("NinjaGaidenMapStage3-1BG.png", NULL);
	//Initialize sprite helper from Direct3DX helper library
	D3DXCreateSprite(d3ddev, &spriteHandler);
}

void CGame::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture ,int left, int top, int right, int bottom, int flipX, D3DXVECTOR2 transform,int alpha)
{
	D3DXMATRIX oldMatrix;
	D3DXMATRIX mMatrix;
	D3DXVECTOR2 Scale = D3DXVECTOR2(1.0, 1.0);
	D3DXVECTOR2 scalingScenter = D3DXVECTOR2(x,y);
	if (flipX == -1)// Co Flip Sang X
	{
		Scale = D3DXVECTOR2(-1.0, 1.0);
		x = -x;
	}
	
	D3DXMatrixTransformation2D(&mMatrix,NULL, 0,&Scale, NULL,
		NULL, &transform);

	spriteHandler->GetTransform(&oldMatrix);
	spriteHandler->SetTransform(&mMatrix);
	
	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;
	D3DXVECTOR3 center((right-left)/2, (bottom-top) / 2, 0);
	D3DXVECTOR3 p(x, y, 0);

	spriteHandler->Draw(texture, &r, &center, &p, D3DCOLOR_ARGB(alpha,255, 255, 255));
	
	spriteHandler->SetTransform(&oldMatrix);
}



void CGame::SweptAABB(float ml, float mt, float mr, float mb, float dx, float dy, float sl, float st, float sr, float sb, float & t, float & nx, float & ny)
{
	float dx_entry, dx_exit, tx_entry, tx_exit;
	float dy_entry, dy_exit, ty_entry, ty_exit;

	float t_entry;
	float t_exit;

	t = -1.0f;			// no collision
	nx = ny = 0.0f;

	//
	// Broad-phase test 
	//

	float bl = dx > 0.0f ? ml : ml + dx;
	float bt = dy > 0.0f ? mt : mt + dy;
	float br = dx > 0.0f ? mr + dx : mr;
	float bb = dy > 0.0f ? mb + dy : mb;

	if (br < sl || bl > sr || bb < st || bt > sb)
	{
		return;
	}
	if (dx == 0.0f && dy == 0.0f)
	{
		return;		// moving object is not moving > obvious no collision
	}
	if (dx > 0.0f)
	{
		dx_entry = sl - mr;
		dx_exit = sr - ml;
	}
	else
		if (dx < 0.0f)
		{
			dx_entry = sr - ml;
			dx_exit = sl - mr;
		}


	if (dy > 0.0f)
	{
		dy_entry = st - mb;
		dy_exit = sb - mt;
	}
	else if (dy < 0.0f)
	{
		dy_entry = sb - mt;
		dy_exit = st - mb;
	}

	if (dx == 0.0f)
	{
		tx_entry = -99999999999.0f;
		tx_exit = 99999999999.0f;
	}
	else
	{
		tx_entry = dx_entry / dx;
		tx_exit = dx_exit / dx;
	}

	if (dy == 0.0f)
	{
		ty_entry = -99999999999.0f;
		ty_exit = 99999999999.0f;
	}
	else
	{
		ty_entry = dy_entry / dy;
		ty_exit = dy_exit / dy;
	}


	if ((tx_entry < 0.0f && ty_entry < 0.0f) || tx_entry > 1.0f || ty_entry > 1.0f)
	{
		return;
	}
	t_entry = max(tx_entry, ty_entry);
	t_exit = min(tx_exit, ty_exit);

	if (t_entry > t_exit)
	{

		
		return;
	}
	
	t = t_entry;

	if (tx_entry > ty_entry)
	{
		ny = 0.0f;
		dx > 0.0f ? nx = -1.0f : nx = 1.0f;
	}
	else
	{
		nx = 0.0f;
		dy > 0.0f ? ny = -1.0f : ny = 1.0f;
	}

}

CGame * CGame::GetInstance()
{
	
	if (_instance == NULL)
	{
		_instance = new CGame();
	}
	return _instance;
}

CGame::~CGame()
{
	if (spriteHandler != NULL) spriteHandler->Release();
	if (backbuffer != NULL) backbuffer->Release();
	if (d3ddev != NULL) d3ddev->Release();
	if (d3d != NULL) d3d->Release();
	if (back != NULL) back->Release();
}

LPDIRECT3DSURFACE9 CGame:: LoadSurface(const char *filename, D3DCOLOR transcolor)
{
	LPDIRECT3DSURFACE9 image = NULL;
	D3DXIMAGE_INFO info;
	HRESULT result;

	result = D3DXGetImageInfoFromFileA(filename, &info);
	if (result != D3D_OK)
	{
		return NULL;
	}

	result = d3ddev->CreateOffscreenPlainSurface(
		info.Width,
		info.Height,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&image,
		NULL
	);
	if (result != D3D_OK)
	{
		return NULL;
	}

	result = D3DXLoadSurfaceFromFileA(
		image,
		NULL,
		NULL,
		filename,
		NULL,
		D3DX_DEFAULT,
		transcolor,
		NULL
	);
	if (result != D3D_OK)
	{
		return NULL;
	}
	return image;
}

