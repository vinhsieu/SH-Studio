#pragma once
#include <algorithm>


#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 208
#define MAX_FRAME_RATE 30
#define WINDOW_CLASS_NAME L"Ninja"
#define MAIN_WINDOW_TITLE L"Ninja"
#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define ID_TEX_NINJA 0
#define ID_TEX_BACKGROUND 1
#define IS_BBOX_DEBUGGING 0
#define Freeze_Item_Last 7000
#define GAME_MAX_TIME 150
extern int TRAN_SCENE_COLOR;
extern int TRAN_SCENE_COLOR_2;
extern int TRAN_SCENE_COLOR_3;
extern int Freeze;
#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) \
if(ptr) \
{\
	delete (ptr); \
	ptr = nullptr; \
} \

#endif
enum eType
{
	eNULL = 0,
	NINJA = 01,
	NINJA_TRANS = 02,
	NINJA_DEADTH = 03,

	// object nền(Bat Dau 20)
	BRICK = 20,
	GATE = 21,

	// object(Bat Dau 40)
	STAIR = 40,


	// weapon(Bat Dau 60)
	BASICWEAPON = 60,
	BlueShuriken = 61,
	RedShuriken = 62,
	Hadoken = 63,
	// item(Bat Dau 80)
	Black_Bird = 80,
	ButterFly = 81,
	Item_BlueShuriken = 82,
	Item_RedShuriken = 83,
	Item_Freeze_Time = 84,
	Item_BlueStack = 85,
	Item_RedStack = 86,
	Item_Hadoken = 87,
	Item_Heath = 88,
	Item_Blue_Point = 89,
	Item_Red_Point = 90,

	// other (Bat Dau 100)
	Map1 = 100,
	Map2 = 101,
	Map3 = 102,
	BBOX = 103,
	Board = 104,
	font = 105,
	HP = 106,
	NOHP = 107,
	Spirit = 108,
	MainMenu = 109,

	// Enemy(Bat Dau 120)
	Dagger = 120,
	BrownBird = 121,
	Blade = 122,
	Panther = 123,
	BombGun = 124,
	Footballguy = 125,
	GunRage = 126,
	Ememy_Texture = 127,

	//BOSS(Bat Dau 140)
	BOSS = 140

	// Intro(Bat Dau 160)
	// Effect(Bat Dau 180)
};

