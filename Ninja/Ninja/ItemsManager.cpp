#include "ItemsManager.h"

ItemsManager * ItemsManager::_instance = NULL;

ItemsManager::ItemsManager()
{
}

void ItemsManager::Update(DWORD dt, vector<LPGAMEOBJECT> *listObj)
{
	for (auto x : listItem)
	{
		if (!x->getIsFinished())
		{
			x->Update(dt,listObj);
		}
	}
}

void ItemsManager::Render()
{
	for (auto x : listItem)
	{
		if (!x->getIsFinished())
		{
			x->Render();
		}
	}
}

void ItemsManager::GetListItem(vector<LPGAMEOBJECT>& listItem)
{
	listItem.clear();
	for (auto x : this->listItem)
	{
		if (!x->getIsFinished())
		{
			listItem.push_back(x);
		}
	}
}

Items * ItemsManager::itemGenerator(float xHost, float yHost, int TypeItem)
{
	switch (TypeItem)
	{
	case eType::Item_BlueShuriken:
		return new ItemBlueShuriken(xHost, yHost);
	case eType::Item_RedShuriken:
		return new ItemRedShuriken(xHost, yHost);
	case eType::Item_BlueStack:
		return new ItemBlueStack(xHost, yHost);
	case eType::Item_RedStack:
		return new ItemRedStack(xHost, yHost);
	case eType::Item_Red_Point:
		return new ItemRedPoint(xHost, yHost);
	case eType::Item_Blue_Point:
		return new ItemBluePoint(xHost, yHost);
	case eType::Item_Freeze_Time:
		return new ItemFreezeTime(xHost, yHost);
	case eType::Item_Hadoken:
		return new ItemHadoken(xHost, yHost);
	case eType::Item_Heath:
		return new ItemHealth(xHost, yHost);
	}
}

void ItemsManager::AddItem(float xHost, float yHost, int TypeItem)
{
	
	
}

void ItemsManager::AddItem(Items * Item)
{
	listItem.push_back(Item);
}

void ItemsManager::Clear()
{
	listItem.clear();
	/*for (auto x : listItem)
	{
		SAFE_DELETE(x);
	}*/
}

ItemsManager * ItemsManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new ItemsManager();
	}
	return _instance;
}


ItemsManager::~ItemsManager()
{
}
