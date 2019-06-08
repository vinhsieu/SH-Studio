
#include "Scene_Game.h"
#include"KeyBoard.h"

Scene_Game::Scene_Game(int State)
{
	this->State = State;
	this->xTrans = 0;
	this->TimeEarnFeeze = 0;
	this->StateSituation = NORMAL;

	mBoard = CBoard::GetInstance();
	ninja = Ninja::GetInstance();
	mGrid = Grid::GetInstance();
	mGrid->Clear();

	listEffect = EffectManager::GetInstance();
	listEffect->ClearEffect();

	listItem = ItemsManager::GetInstance();
	listItem->Clear();

	mTimer = Timer::GetInstance();
	mTimer->SetTime(0);
	isTransitionScene = false;
	StartTranTime = 0;
	LoadResources();
	
}


Scene_Game::~Scene_Game()
{
}

void Scene_Game::LoadResources()
{
	
	switch (this->State)
	{
	case 1:

		Sound::GetInstance()->Play(eSound::music_Scence_1, true);
		mGrid->SetGridPath(L"Resources/Map/Map1_Object.txt");
		gamemap = new GameMap(eType::Map1, L"Resources/Map/Map1_Matrix.txt");
		CCamera::GetInstance()->SetBounding(eType::Map1);
		ninja->SetPosition(0, 0);
		xTrans = 2020;
		break;
	case 2:

		CCamera::GetInstance()->SetBounding(eType::Map2);
		mGrid->SetGridPath(L"Resources/Map/Map2_Object.txt");
		gamemap = new GameMap(eType::Map2, L"Resources/Map/Map2_Matrix.txt");
		Sound::GetInstance()->Play(eSound::music_Scence_2, true);
		xTrans = 3072;
		ninja->SetPosition(0, 0);
		break;
	case 3:

		CCamera::GetInstance()->SetBounding(eType::Map3);
		mGrid->SetGridPath(L"Resources/Map/Map3_Object.txt");
		gamemap = new GameMap(eType::Map3, L"Resources/Map/Map3_Matrix.txt");
		Sound::GetInstance()->Play(eSound::music_Boss, true);
		xTrans = 3000;
		ninja->SetPosition(48, 0);
		break;
	}
	

}

void Scene_Game::SetStateSituation(int statesituation)
{
	this->StateSituation= statesituation;
}

void Scene_Game::Render()
{
	gamemap->Draw();
	mBoard->Render();
	
	for (auto x : obj)
	{
		x->Render();
	}
	listItem->Render();
	listEffect->Render();

	ninja->Render();

}

void Scene_Game::Update(DWORD dt)
{
	if (Freeze)
	{
		//Sound::GetInstance()->Stop(eSound::sound_Time_tick_when_stop);
		Sound::GetInstance()->Play(eSound::sound_Time_tick_when_stop);
		TimeEarnFeeze += dt;
		if (TimeEarnFeeze > Freeze_Item_Last)
		{
			Freeze = 0;
			TimeEarnFeeze = 0;
		}
	}
	switch (this->StateSituation)
	{
	case NORMAL:
		if (!isTransitionScene)
		{
			mGrid->ListObject(obj);
			listItem->Update(dt, &obj);
			objDynamic.clear();
			objStatic.clear();
			if (!Freeze)
			{
				for (auto x : obj)
				{
					x->Update(dt);
				}
			}
			mBoard->Update();
			listEffect->Update(dt);
			ninja->Update(dt, &obj);
			float x; float y;
			ninja->GetPosition(x, y);
			if (x > xTrans)
			{
				isTransitionScene = true;
				TRAN_SCENE_COLOR = 255;
			}
			mTimer->Update(dt);
		}
		else
		{
			Sound::GetInstance()->StopAll();
			StartTranTime += dt;
			if (StartTranTime > 4000)
			{
				if (this->State < 3)
				{
					SceneManager::GetInstance()->SetScene(new Scene_Game(this->State + 1));
					TRAN_SCENE_COLOR = 255;
				}
			}
			else
			{
				if (TRAN_SCENE_COLOR - 2 > 0)
				{
					TRAN_SCENE_COLOR -= 2;
				}
				else
				{
					TRAN_SCENE_COLOR = 0;
				}
			}
		}
		break;
	case Ninja_Die:
		Sound::GetInstance()->StopAll();
		StartTranTime += dt;
		if (StartTranTime > 4000)
		{
			SceneManager::GetInstance()->SetScene(new Scene_Game(this->State));
			TRAN_SCENE_COLOR = 255;
		}
		else
		{
			if (TRAN_SCENE_COLOR - 2 > 0)
			{
				TRAN_SCENE_COLOR -= 2;
			}
			else
			{
				TRAN_SCENE_COLOR = 0;
			}
		}
		break;
	case Ninja_Out_Of_Life:
		Sound::GetInstance()->StopAll();
		StartTranTime += dt;
		if (StartTranTime > 4000)
		{
			SceneManager::GetInstance()->SetScene(new Game_Over(this->State));
			TRAN_SCENE_COLOR = 255;
		}
		else
		{
			if (TRAN_SCENE_COLOR - 2 > 0)
			{
				TRAN_SCENE_COLOR -= 2;
			}
			else
			{
				TRAN_SCENE_COLOR = 0;
			}
		}
		break;
	}
}

void Scene_Game::KeyState(BYTE * state)
{
	if (!ninja->canControl)
	{
		return;
	}
	if (CKeyHandler::GetInstance()->isKeyDown(DIK_RIGHT))
	{
		ninja->SetState(NINJA_STATE_WALKING_RIGHT);
	}
	else if (CKeyHandler::GetInstance()->isKeyDown(DIK_LEFT))
	{
		ninja->SetState(NINJA_STATE_WALKING_LEFT);
	}
	else if (CKeyHandler::GetInstance()->isKeyDown(DIK_DOWN))
	{
		ninja->SetState(NINJA_STATE_SIT);
	}
	else if (CKeyHandler::GetInstance()->isKeyDown(DIK_UP))
	{
		ninja->SetState(NINJA_STATE_CLIMBING);
	}
	else {
		ninja->SetState(NINJA_STATE_IDLE);
	}
}

void Scene_Game::OnKeyDown(int KeyCode)
{
	if (!ninja->canControl)
	{
		return;
	}
	//DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
		ninja->SetState(NINJA_STATE_JUMP);
		break;
	case DIK_A:
		ninja->SetState(NINJA_STATE_ATTACH);
		break;
	case DIK_BACK:
		ninja->SetState(NINJA_STATE_ATTACH);
		break;
	case DIK_F:
		ninja->SetPosition(0.0f, 10.0f);
		break;
	case DIK_S:
		ninja->SetState(NINJA_STATE_EXTRA_WEAPON);
		break;
	}
}

void Scene_Game::OnKeyUp(int KeyCode)
{
}
