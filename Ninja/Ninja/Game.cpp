#include "Game.h"



Game::Game()
{
}

void Game::GameInit(HWND hWnd)
{
	Cgame = CGame::GetInstance();
	Cgame->Init(hWnd);
	keyboard = new CKeyHandler();
	keyboard->InitKeyBoard(keyboard);
	ninja = Ninja::GetInstance();
	mGrid = new Grid();
	mGrid->SetGridPath(L"Resources/Map/Map1_Object.txt");
	listEffect = EffectManager::GetInstance();
	listItem = ItemsManager::GetInstance();
	LoadResources();
}

void Game::LoadResources()
{
	gamemap = new GameMap(L"NinjaGaidenMapStage3-1BG_1.png", L"Resources/Map/Map1_Matrix.txt");
	Sound::GetInstance()->Play(eSound::music_Scence_1, true);
}

void Game::Render()
	{
		LPDIRECT3DDEVICE9 d3ddv = Cgame->GetDirect3dDevice();
		LPDIRECT3DSURFACE9 bb = Cgame->Getbackbuffer();
		LPD3DXSPRITE spriteHandler = Cgame->GetSpriteHandler();
		LPDIRECT3DSURFACE9 back = Cgame->Getbackground();
		RECT p;
		p.left = 0;
		p.top = 0;
		p.right = 2;
		p.bottom = 2;
		RECT des;
		des.left = 150;
		des.top = 150;
		des.right = 152;
		des.bottom = 152;
		if (d3ddv->BeginScene())
		{
			// Clear back buffer with a color
			d3ddv->Clear(0,NULL,D3DCLEAR_TARGET, D3DCOLOR_XRGB(255,255,255),0.0f,0);
			//d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
			

			//d3ddv->StretchRect(back, &p, bb, &des2, D3DTEXF_NONE);
	//		d3ddv->SetTransform(v)
			spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
			
			gamemap->Draw();
			//mBrick->Render();
			//dagger->Render();
			for (auto x : obj)
			{
				x->Render();
			}
			listItem->Render();
			listEffect->Render();
			ninja->Render();
			//d3ddv->StretchRect(back, &p, bb, &des, D3DTEXF_NONE);
			spriteHandler->End();
			d3ddv->EndScene();
		}

		// Display back buffer content to the screen
		d3ddv->Present(NULL, NULL, NULL, NULL);
	}

void Game::Update(DWORD dt)
{
	mGrid->ListObject(obj);
	listItem->Update(dt, &obj);
	objDynamic.clear();
	objStatic.clear();
	for (auto x : obj)
	{

		x->Update(dt);
	}
	listEffect->Update(dt);
	ninja->Update(dt,&obj);
	
}

int Game::Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 50 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			keyboard->ProcessKeyBoard();
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}

	return 1;
}

Game::~Game()
{
}
