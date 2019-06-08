#pragma once
#include"CGameObject.h"
#include"define.h"
#include"Ninja.h"
#include"SceneManager.h"
class Timer
{
	static Timer * _instance;

	bool isPlusPoint;//Ninja giet dc boss
	DWORD _accumulationTime; // thời gian đã tích lũy tru bt
	DWORD _accumulationTimeBoss;// Thoi gian tich luy cong tien cho boss
	int _time; // time game 
public:
	Timer();
	~Timer();
	void Update(DWORD dt);
	void SetTime(int t);
	void plusPoint();
	int GetTime();
	static Timer * GetInstance();
};

