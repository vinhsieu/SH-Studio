#include "Game_Over.h"



Game_Over::Game_Over(int previousState)
{
	if (previousState == 3)
	{
		this->previousState = 2;
	}
	else
	{
		this->previousState = previousState;
	}
	this->State = 4;//ID cua GameOverScene
	LoadResources();
}


Game_Over::~Game_Over()
{
}

void Game_Over::KeyState(BYTE * state)
{
}

void Game_Over::OnKeyDown(int KeyCode)
{
	if (KeyCode == DIK_ESCAPE)
		DestroyWindow(CGame::GetInstance()->hWnd); // thoát
	else
	{
		this->isPressedKey = true;
	}
}

void Game_Over::OnKeyUp(int KeyCode)
{
}

void Game_Over::LoadResources()
{
	this->TimeBling = 0;
	this->TimeBetweenBling = 0;
	this->isDrawStartFont = true;
}

void Game_Over::Update(DWORD dt)
{
	if (isPressedKey)
	{
		TimeBling += dt;
		if (TimeBling > 3000)
		{
			SceneManager::GetInstance()->SetScene(new Scene_Game(previousState));
		}
		else
		{
			TimeBetweenBling += dt;
			if (TimeBetweenBling > 150)
			{
				isDrawStartFont = !isDrawStartFont;
				TimeBetweenBling = 0;
			}
		}
	}
}

void Game_Over::Render()
{
	mFont->Draw(86, 60, "GAME OVER");
	if (isDrawStartFont)
	{
		mFont->Draw(40, 120, "PUSH START, ESC TO EXIT");
	}
}
