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
	LoadResources();
}

void Game::LoadResources()

{
	CTexture * texture = CTexture::GetInstance();
	texture->Add(ID_TEX_NINJA, L"Ninja.png", D3DCOLOR_XRGB(255, 163, 177));
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texNinja = texture->Get(ID_TEX_NINJA);

	//Run Right
	sprites->Add(10000, 0, 5, 22, 37, texNinja);
	sprites->Add(10001, 338, 5, 360, 37, texNinja);
	sprites->Add(10002, 368, 5, 390, 37, texNinja);
	sprites->Add(10003, 399, 5, 421, 37, texNinja);


	//ATTACH RIGHT
	sprites->Add(10033, 4, 5, 26, 37, texNinja);
	sprites->Add(10034, 25, 160, 47, 192, texNinja);
	sprites->Add(10035, 48, 5, 106, 37, texNinja);
	sprites->Add(10036, 106, 5, 140, 37, texNinja);

	//SIT ATTACH RIGHT
	sprites->Add(10037, 35, 44, 53, 76, texNinja);
	sprites->Add(10038, 75, 156, 132, 188, texNinja);
	sprites->Add(10039, 93, 44, 129, 76, texNinja);

	//JUMP
	sprites->Add(10021, 139, 49, 161, 81, texNinja);
	sprites->Add(10022, 166, 49, 188, 81, texNinja);
	sprites->Add(10023, 190, 49, 212, 81, texNinja);
	sprites->Add(10024, 217, 49, 239, 81, texNinja);
	//Sit right
	sprites->Add(10050, 1, 44, 23, 76, texNinja);
	//Sit left
	sprites->Add(10051, 108, 192, 130, 224, texNinja);

	LPANIMATION ani;
	//idle right
	ani = new CAnimation(100);
	ani->Add(10000);
	animations->Add(400, ani);

	//Walk right
	ani = new CAnimation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(500, ani);
	//JUMP
	ani = new CAnimation(20);
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	animations->Add(600, ani);

	//ATTACH RIGHT
	ani = new CAnimation(100);
	ani->Add(10033);
	ani->Add(10034);
	ani->Add(10035);
	ani->Add(10036);
	animations->Add(701, ani);
	//Sit right
	ani = new CAnimation(100);
	ani->Add(10050);
	animations->Add(801, ani);

	//Sit Attach Right
	ani = new CAnimation(100);
	ani->Add(10037);
	ani->Add(10038);
	ani->Add(10039);
	animations->Add(702, ani);
	ninja = new Ninja();
	//Attach on Jump right
	ani = new CAnimation(200);
	ani->Add(10035);
	animations->Add(704, ani);

	ninja->AddAnimation(400);		// idle right 0
	ninja->AddAnimation(500);		// walk right 2
	ninja->AddAnimation(600);       //Jump Ani 4
	ninja->AddAnimation(701);       //Attach left 6
	ninja->AddAnimation(801);       //Sit idle right 8
	ninja->AddAnimation(702);		//Sit Attach right 9
	ninja->AddAnimation(704);		//Attach on Jump Right 11
	ninja->SetPosition(0.0f, 150.0f);

	mCamera = new Camera(320, 200, 0, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	gamemap = new GameMap(L"NinjaGaidenMapStage3-1BG_1.png",L"NinjaGaidenMapStage3-1BG_1.txt");
	gamemap->SetCamera(mCamera);
	keyboard->SetNinja(this->ninja);
}

void Game::Render()
	{
		LPDIRECT3DDEVICE9 d3ddv = Cgame->GetDirect3dDevice();
		LPDIRECT3DSURFACE9 bb = Cgame->Getbackbuffer();
		LPD3DXSPRITE spriteHandler = Cgame->GetSpriteHandler();
		LPDIRECT3DSURFACE9 back = Cgame->Getbackground();
		RECT p;

		p.left = 0/* cam_position*/;
		p.top = 33;
		p.right = /*cam_position +*/320;
		p.bottom = 208;
		RECT des;
		des.left = 70;
		des.top = 70;
		des.right = 100;
		des.bottom = 100;
		RECT des2;
		des2.left = 10;
		des2.top = 10;
		des2.right = 40;
		des2.bottom = 40;
		if (d3ddv->BeginScene())
		{
			// Clear back buffer with a color
			d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
			//d3ddv->StretchRect(back,&p, bb, &des, D3DTEXF_NONE);

			d3ddv->StretchRect(back, &p, bb, &des2, D3DTEXF_NONE);
	//		d3ddv->SetTransform(v)
			spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

			gamemap->Draw();
			ninja->Render();
			if (mCamera)
			{
				mCamera->SetTransform(Cgame);
			}

			spriteHandler->End();
			d3ddv->EndScene();
		}

		// Display back buffer content to the screen
		d3ddv->Present(NULL, NULL, NULL, NULL);
	}

void Game::Update(DWORD dt)

{


	ninja->Update(dt);
	if (mCamera)
	{
		if (GetAsyncKeyState(70)) //70 is the vKey value for F
		{
			if (!mCamera->IsFollowing())
			{
				mCamera->Following(ninja);
			}
			DebugOut(L"Following");
		}

		if (GetAsyncKeyState(85)) //85 is the vKey value for U
		{
			if (mCamera->IsFollowing())
			{
				mCamera->UnFollowing();
			}
			DebugOut(L"Unfollowing");
		}

		mCamera->Update();
	}
}

int Game::Run()

{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1 / MAX_FRAME_RATE;

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
