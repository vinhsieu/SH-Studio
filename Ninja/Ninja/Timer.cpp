#include "Timer.h"

#include"Scene_End.h"

Timer * Timer::_instance = NULL;
Timer::Timer()
{
	isPlusPoint = false;
	this->_accumulationTime = 0;
	this->_accumulationTimeBoss = 0;
	SetTime(0);
}


Timer::~Timer()
{
}

void Timer::Update(DWORD dt)
{
	if (!isPlusPoint)
	{
		if (_accumulationTime + dt < 1000)
		{
			_accumulationTime += dt;
		}
		else
		{
			_accumulationTime = (_accumulationTime + dt) % 1000;
			_time++;
		}
		if (_time > GAME_MAX_TIME)
		{
			SceneManager::GetInstance()->SetStateSituation(Ninja_Die);
		}
	}
	else
	{
		if(GAME_MAX_TIME - _time > 0)
		{
			if (_accumulationTimeBoss + dt < 70)
			{
				_accumulationTimeBoss += dt;
			}
			else
			{
				_accumulationTimeBoss = (_accumulationTimeBoss + dt) % 70;
				_time++;
				Ninja::GetInstance()->plusPoint(100);
				Sound::GetInstance()->Play(eSound::sound_Timer_Boss_Die);
			}
			
		}
		else
		{
			this->isPlusPoint = false;
	     	SceneManager::GetInstance()->SetScene(new Scene_End());
		}
	}
}

void Timer::SetTime(int t)
{
	this->_time = t;
}

void Timer::plusPoint()
{
	this->isPlusPoint = true;
}

int Timer::GetTime()
{
	return this->_time;
}

Timer * Timer::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Timer();
	}
	return _instance;
}
