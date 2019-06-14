#include "Scene_End.h"
#include"Scene_Intro.h"


Scene_End::Scene_End()
{
	this->State = 5;//ID cua GameOverScene
	LoadResources();
}


Scene_End::~Scene_End()
{
}

void Scene_End::KeyState(BYTE * state)
{
}

void Scene_End::OnKeyDown(int KeyCode)
{
	if (KeyCode == DIK_ESCAPE)
		DestroyWindow(CGame::GetInstance()->hWnd); // thoát
	else
	{
		this->isPressedKey = true;
	}
}

void Scene_End::OnKeyUp(int KeyCode)
{
}

void Scene_End::LoadResources()
{
	this->TimeBling = 0;
	this->TimeBetweenBling = 0;
	this->isDrawStartFont = true;
}

void Scene_End::Update(DWORD dt)
{
	if (isPressedKey)
	{
		TimeBling += dt;
		if (TimeBling > 3000)
		{
			Sound::GetInstance()->StopAll();
			SceneManager::GetInstance()->SetScene(new Scene_Intro());
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

void Scene_End::Render()
{
	mFont->Draw(86, 60, "THE END");
	if (isDrawStartFont)
	{
		mFont->Draw(30, 120, "PUSH RE-START,ESC TO EXIT");
	}
}
