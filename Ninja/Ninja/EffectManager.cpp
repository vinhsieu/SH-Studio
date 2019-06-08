#include "EffectManager.h"

EffectManager * EffectManager::_instance = NULL;

EffectManager::EffectManager()
{
}

void EffectManager::Update(DWORD dt)
{
	for (auto x : listEffect)
	{
		if (!x->GetIsFinish())
		{
			x->Update(dt);
		}
		
	}
}

void EffectManager::Render()
{
	for (auto x : listEffect)
	{
		if (!x->GetIsFinish())
		{
			x->Render();
		}
	}
}

void EffectManager::AddEffect(float xHost, float yHost, int WidthHost, int HightHost,int TypeEnemy)
{
	listEffect.push_back(new CEnemyDie(xHost, yHost, WidthHost, HightHost,TypeEnemy));
}

void EffectManager::ClearEffect()
{
	listEffect.clear();
}

EffectManager * EffectManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new EffectManager();
	}
	return _instance;
}


EffectManager::~EffectManager()
{
}
