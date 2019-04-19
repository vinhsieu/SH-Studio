#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>

#define DIRECTINPUT_VERSION 0x0800
#include<dinput.h>

#define KEYBOARD_BUFFER_SIZE 1024




class CGame
{
	static CGame * _instance;
	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	LPDIRECT3DSURFACE9 backbuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;
	LPDIRECT3DSURFACE9 back = NULL;


	

	//
	
	
	



public:

	HWND hWnd;
	void Init(HWND hWnd);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom,int flipX);
	LPDIRECT3DDEVICE9 GetDirect3dDevice() { return this->d3ddev; };
	LPDIRECT3DSURFACE9 Getbackbuffer() { return this->backbuffer; };
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; };
	LPDIRECT3DSURFACE9 Getbackground() { return this->back; }
	/*static void SweptAABB(
		float ml,
		float mt,
		float mr,
		float mb,
		float dx,
		float dy,
		float sl,
		float st,
		float sr,
		float sb,
		float &t,
		float &nx,
		float &ny

	);*/


	
	static CGame * GetInstance();

	~CGame();
	LPDIRECT3DSURFACE9 LoadSurface(const char * filename, D3DCOLOR transcolor);



	
};


