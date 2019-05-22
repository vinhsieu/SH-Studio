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
#define IS_BBOX_DEBUGGING 0
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


	// other (Bat Dau 100)
	Map1 = 100,
	Map2 = 101,
	Map3 = 102,
	BBOX=103,
	


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