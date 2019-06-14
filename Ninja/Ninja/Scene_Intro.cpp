#include "Scene_Intro.h"



Scene_Intro::Scene_Intro()
{
	this->State = 0;//ID cua introScene
	LoadResources();
}


Scene_Intro::~Scene_Intro()
{
}

void Scene_Intro::KeyState(BYTE * state)
{
}

void Scene_Intro::OnKeyDown(int KeyCode)
{
	this->isPressedKey = true;
}

void Scene_Intro::OnKeyUp(int KeyCode)
{
}

void Scene_Intro::LoadResources()
{
	this->TimeBling = 0;
	this->TimeBetweenBling = 0;
	this->isDrawStartFont = true;
	//Scene * nextScene = new Scene_Game(1);
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::MainMenu);

	// di chuyen bt
	sprites->Add(404, 0, 0, 227, 210, tex);
}

void Scene_Intro::Update(DWORD dt)
{
	if (isPressedKey)
	{
		TimeBling += dt;
		if (TimeBling > 3000)
		{
			SceneManager::GetInstance()->SetScene(new Scene_Game(1));
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

void Scene_Intro::Render()
{
	CSprites * sprites = CSprites::GetInstance();
	sprites->Get(404)->Draw(0+113, 0+105, 0, D3DXVECTOR2(0, 0));
	if (isDrawStartFont)
	{
		mFont->Draw(75, 120, "PUSH START");
	}
}
