#pragma once
#include "CEnemyDie.h"
#include"debug.h"
class EffectManager
{
	static EffectManager * _instance;
	vector<CEnemyDie *> listEffect;
public:
	EffectManager();
	void Update(DWORD dt);
	void Render();
	void AddEffect(float xHost, float yHost, int WidthHost, int HightHost);
	void ClearEffect();
	static EffectManager * GetInstance();
	~EffectManager();
};

