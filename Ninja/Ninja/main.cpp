#include<Windows.h>
#include"CGame.h"
#include"CGameObject.h"
#include<d3d9.h>
#include<d3dx9.h>
#include"Texture.h"
#include"Sprite.h"
#include"Ninja.h"
#include"debug.h"
#include"Camera.h"


#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define MAX_FRAME_RATE 30
#define WINDOW_CLASS_NAME L"BT1"
#define MAIN_WINDOW_TITLE L"BT1"
#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 100)
#define ID_TEX_NINJA 0
#define ID_TEX_BACKGROUND 1


CGame * game;
Ninja * ninja;
Ninja *background;
Camera *camera;

class CKeyHandler : public CKeyEventHandler
{
	virtual void KeyState(BYTE *state);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);

};
CKeyHandler * keyHandler;
void CKeyHandler::KeyState(BYTE * state)
{
	if (game->isKeyDown(DIK_RIGHT))
	{
		ninja->SetState(NINJA_STATE_WALKING_RIGHT);
	}
	else if (game->isKeyDown(DIK_LEFT))
	 {
		ninja->SetState(NINJA_STATE_WALKING_LEFT);
	 }
	else if (game->isKeyDown(DIK_DOWN))
	{
		ninja->SetState(NINJA_STATE_SIT);
	}
	else {
		ninja->SetState(NINJA_STATE_IDLE); }
		
}
void CKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
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
	}
}
void CKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
}
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}
void LoadResources()
{
	CTexture * texture = CTexture::GetInstance();
	texture->Add(ID_TEX_NINJA, L"Ninja.png", D3DCOLOR_XRGB(255, 163, 177));
	texture->Add(ID_TEX_BACKGROUND, L"NinjaGaidenMapStage3-1BG.png", D3DCOLOR_XRGB(255, 163, 177));
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texNinja = texture->Get(ID_TEX_NINJA);
	LPDIRECT3DTEXTURE9 texBackground = texture->Get(ID_TEX_BACKGROUND);
	//Back ground
	sprites->Add(20000, 0, 0, 2560, 208, texBackground);
	//Run Right
	sprites->Add(10000, 0, 5, 22, 37, texNinja);
	sprites->Add(10001, 338, 5, 360, 37, texNinja);
	sprites->Add(10002, 368, 5, 390, 37, texNinja);
	sprites->Add(10003, 399, 5, 421, 37, texNinja);


	//ATTACH RIGHT
	sprites->Add(10033, 4, 5, 26, 37, texNinja);
	sprites->Add(10034,25, 160, 47, 192, texNinja);
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
	//
	ani = new CAnimation(100);
	ani->Add(20000);
	animations->Add(300, ani);
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
	animations->Add(702,ani);
	ninja = new Ninja();
	
	//Attach on Jump right
	ani = new CAnimation(200);
	ani->Add(10035);
	animations->Add(704, ani);
	
	Ninja::AddAnimation(400);		// idle right 0
	Ninja::AddAnimation(500);		// walk right 2
	Ninja::AddAnimation(600);       //Jump Ani 4
	Ninja::AddAnimation(701);       //Attach left 6
	Ninja::AddAnimation(801);       //Sit idle right 8
	Ninja::AddAnimation(702);		//Sit Attach right 9
	Ninja::AddAnimation(704);		//Attach on Jump Right 11
	background = new Ninja();
	background->AddAnimation(300);
	ninja->SetPosition(0.0f, 150.0f);

	camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT, 0, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
}
HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW,  //WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}
void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3dDevice();
	LPDIRECT3DSURFACE9 bb = game->Getbackbuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();
	LPDIRECT3DSURFACE9 back = game->Getbackground();
	RECT p;
	p.left = 0;
	p.top = 33;
	p.right = 320;
	p.bottom = 208;
	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		//d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
		//d3ddv->StretchRect(back, &p, bb, NULL, D3DTEXF_NONE);
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		ninja->Render();
		background->Render();
		if (camera)
		{
			camera->SetTransform(&d3ddv);
		}


		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}
void Update(DWORD dt)
{
	if (camera)
	{
		if (GetAsyncKeyState(70)) //70 is the vKey value for F
		{
			if (!camera->isFollowing())
			{
				camera->Follow(ninja);
			}
		}

		if (GetAsyncKeyState(85)) //85 is the vKey value for U
		{
			if (camera->isFollowing())
			{
				camera->Unfollow();
			}
		}

		camera->Update();
	}
	ninja->Update(dt);
}

int Run()
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
			game->ProcessKeyBoard();
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}

	return 1;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	game = CGame::GetInstance();
	game->Init(hWnd);
	keyHandler = new CKeyHandler();
	game->InitKeyBoard(keyHandler);

	LoadResources();
	Run();

	return 0;
}


