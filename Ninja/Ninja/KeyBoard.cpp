#include"KeyBoard.h"



void CKeyHandler::SetNinja(Ninja * ninja)
{
	this->ninja = ninja;
}

int CKeyHandler::isKeyDown(int KeyCode)
{
	return (keyState[KeyCode] & 0x80) > 0;
}

void CKeyHandler::ProcessKeyBoard()
{
	HRESULT result;

	result = didv->GetDeviceState(sizeof(keyState), keyState);

	if (FAILED(result))
	{
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			HRESULT h = didv->Acquire();
			if (h == DI_OK)
			{
				DebugOut(L"[INFO] Keyboard re-acquired!\n");
			}
			else
			{
				return;
			}
		}
		else
		{
			DebugOut(L"[ERROR] DINPUT::GetDeviceState failed. Error: %d\n", result);
			return;
		}
	}

	keyHandler->KeyState((BYTE *)&keyState);

	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	result = didv->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), KeyEvents, &dwElements, 0);
	if (FAILED(result))
	{
		DebugOut(L"[ERROR] DINPUT::GetDeviceData failed. Error: %d\n", result);
		return;
	}

	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = KeyEvents[i].dwOfs;
		int KeyState = KeyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
		{
			keyHandler->OnKeyDown(KeyCode);
		}
		else
		{
			keyHandler->OnKeyUp(KeyCode);
		}
	}


}
void CKeyHandler::InitKeyBoard(LPKEYEVENTHANDLER handler)
{
	HWND hWnd = CGame::GetInstance()->hWnd;
	HRESULT
		result = DirectInput8Create
		(
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
			DIRECTINPUT_VERSION,
			IID_IDirectInput8, (VOID**)&di, NULL
		);
	if (result != DI_OK)
	{
		return;
	}
	result = di->CreateDevice(GUID_SysKeyboard, &didv, NULL);
	if (result != DI_OK)
	{
		return;
	}

	result = didv->SetDataFormat(&c_dfDIKeyboard);
	result = didv->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE;

	result = didv->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	result = didv->Acquire();
	if (result != NULL)
	{
		return;
	}
	this->keyHandler = handler;

}
void CKeyHandler::KeyState(BYTE * state)
{
	if (this->isKeyDown(DIK_RIGHT))
	{
		ninja->SetState(NINJA_STATE_WALKING_RIGHT);
	}
	else if (this->isKeyDown(DIK_LEFT))
	{
		ninja->SetState(NINJA_STATE_WALKING_LEFT);
	}
	else if (this->isKeyDown(DIK_DOWN))
	{
		ninja->SetState(NINJA_STATE_SIT);
	}
	else {
		ninja->SetState(NINJA_STATE_IDLE);
	}

}
void CKeyHandler::OnKeyDown(int KeyCode)
{
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
	}
}
void CKeyHandler::OnKeyUp(int KeyCode)
{
	
	//DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
}