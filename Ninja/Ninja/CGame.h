#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>

#define DIRECTINPUT_VERSION 0x0800
#include<dinput.h>

#define KEYBOARD_BUFFER_SIZE 1024
class CKeyEventHandler
{
public:
	virtual void KeyState(BYTE *state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
};

typedef CKeyEventHandler * LPKEYEVENTHANDLER;



class CGame
{
	static CGame * _instance;
	HWND hWnd;
	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	LPDIRECT3DSURFACE9 backbuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;
	LPDIRECT3DSURFACE9 back = NULL;


	LPDIRECTINPUT8 di;// The DirectInput object
	LPDIRECTINPUTDEVICE8 didv; //The keyboard device

	BYTE keyState[256];
	DIDEVICEOBJECTDATA KeyEvents[KEYBOARD_BUFFER_SIZE];

	LPKEYEVENTHANDLER keyHandler;



public:
	void Init(HWND hWnd);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom,int flipX, int alpha);
	LPDIRECT3DDEVICE9 GetDirect3dDevice() { return this->d3ddev; };
	LPDIRECT3DSURFACE9 Getbackbuffer() { return this->backbuffer; };
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; };
	LPDIRECT3DSURFACE9 Getbackground() { return this->back; }
	static void SweptAABB(
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

	);


	int isKeyDown(int KeyCode);
	void ProcessKeyBoard();
	void InitKeyBoard(LPKEYEVENTHANDLER handler);

	static CGame * GetInstance();

	~CGame();
	LPDIRECT3DSURFACE9 LoadSurface(const char * filename, D3DCOLOR transcolor);
};


