#pragma once
#include <algorithm>


#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 208
#define MAX_FRAME_RATE 30
#define WINDOW_CLASS_NAME L"BT1"
#define MAIN_WINDOW_TITLE L"BT1"
#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 100)
#define ID_TEX_NINJA 0
#define ID_TEX_BACKGROUND 1
#define IS_BBOX_DEBUGGING 1

extern int TRAN_SCENE_COLOR;
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

