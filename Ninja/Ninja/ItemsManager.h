#pragma once
#include"Items.h"
#include"ItemBlueShuriken.h"
#include"ItemRedShuriken.h"
#include"ItemBluePoint.h"
#include"ItemRedPoint.h"
#include"ItemBlueStack.h"
#include"ItemRedStack.h"
#include"ItemHadoken.h"
#include"ItemFreezeTime.h"
#include"ItemHealth.h"

class ItemsManager
{
	static ItemsManager * _instance;
	vector<Items *> listItem;
public:
	ItemsManager();
	void Update(DWORD dt,vector<LPGAMEOBJECT> *listObj);
	void Render();
	void GetListItem(vector<LPGAMEOBJECT> & listItem);
	Items * itemGenerator(float xHost, float yHost, int TypeItem);
	void AddItem(float xHost, float yHost, int TypeItem);
	void AddItem(Items * Item);
	static ItemsManager * GetInstance();
	~ItemsManager();
};

