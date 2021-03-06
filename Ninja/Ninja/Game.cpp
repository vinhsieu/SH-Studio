


#include "Game.h"




Game::Game()
{
}

void Game::GameInit(HWND hWnd)
{
	CGame::GetInstance()->Init(hWnd);
	keyboard = CKeyHandler::GetInstance();
	mSceneManager = SceneManager::GetInstance();
	mSceneManager->SetScene(new Scene_Intro());
}

void Game::LoadResources()
{

	
}

void Game::Render()
	{
		LPDIRECT3DDEVICE9 d3ddv = CGame::GetInstance()->GetDirect3dDevice();
		LPDIRECT3DSURFACE9 bb = CGame::GetInstance()->Getbackbuffer();
		LPD3DXSPRITE spriteHandler = CGame::GetInstance()->GetSpriteHandler();
		LPDIRECT3DSURFACE9 back = CGame::GetInstance()->Getbackground();
		
		if (d3ddv->BeginScene())
		{
			// Clear back buffer with a color
			d3ddv->Clear(0,NULL,D3DCLEAR_TARGET, D3DCOLOR_XRGB(255,255,255),0.0f,0);
			d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
			

			//d3ddv->StretchRect(back, &p, bb, &des2, D3DTEXF_NONE);
	//		d3ddv->SetTransform(v)
			spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
			

			mSceneManager->Render();
			
			//d3ddv->StretchRect(back, &p, bb, &des, D3DTEXF_NONE);
			spriteHandler->End();
			d3ddv->EndScene();
		}

		// Display back buffer content to the screen
		d3ddv->Present(NULL, NULL, NULL, NULL);
	}

void Game::Update(DWORD dt)
{
	mSceneManager->Update(dt);
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
