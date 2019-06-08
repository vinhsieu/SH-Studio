#pragma once
#include"Texture.h"
#include"CGame.h"
#include"debug.h"
class Font
{
	static Font * _instance;
public:
	Font();
	~Font();
	static Font * GetInstance();
	void Draw(float x, float y, const string & s);
};

