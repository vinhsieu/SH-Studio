#pragma once
#include<Windows.h>
#include<d3dx9.h>
#include<unordered_map>
#include"CGame.h"
using namespace std;

class CSprite
{
	int id; //Sprite id in the sprite database/sheet


	//rect the location
	int left;
	int top;
	int right;
	int bottom;

	LPDIRECT3DTEXTURE9 texture;
	

public:
	CSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	void Draw(float x, float y, int FlipX, D3DXVECTOR2 transform) ;

};

typedef CSprite * LPSPRITE;

class CSprites
{
	static CSprites * _instance;

	unordered_map <int, LPSPRITE> sprites;

public:
	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	LPSPRITE Get(int id);

	static CSprites * GetInstance();
};


class CAnimationFrame
{
	LPSPRITE sprite;
	DWORD time;

public:
	CAnimationFrame(LPSPRITE sprite, DWORD time) { this->sprite = sprite; this->time = time; };
	DWORD GetTime() { return time; };
	LPSPRITE GetSprite() { return sprite; };
};

typedef CAnimationFrame *LPCANIMATION_FRAME;

class CAnimation
{
	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;
	vector<LPCANIMATION_FRAME> frames;

public:
	CAnimation(int defaultTime);
	void Add(int spriteId, DWORD Time = 0);
	int Render(float x, float y, int isAttach, int FlipX, D3DXVECTOR2 trans);

};

typedef CAnimation *LPANIMATION;

class CAnimations
{
	static CAnimations * _instance;
	unordered_map<int, LPANIMATION> animations;
public:
	void Add(int id, LPANIMATION ani);
	LPANIMATION Get(int id);

	static CAnimations * GetInstance();
};

