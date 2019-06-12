#include "CBoard.h"

CBoard * CBoard::_instance = NULL;

string CBoard::FillNumber(string s, UINT MaxNumber)
{
	while (s.size() < MaxNumber)
		s = "0" + s;
	return s;
}

CBoard::CBoard()
{
	CSprites::GetInstance()->Add(403, 0, 0, 12, 10, CTexture::GetInstance()->Get(eType::Spirit));
	mFont = Font::GetInstance();
	mCBoardHealth = CBoardHealth::GetInstance();
	
	LoadAni();
}

void CBoard::Render()
{
	if (SceneManager::GetInstance()->getState() != 3)
	{
		mCBoardHealth->Draw(this->nNinjaHealth, 16);
	}
	else
	{
		mCBoardHealth->Draw(this->nNinjaHealth, BossHealth);
	}
	mFont->Draw(10, 2, "SCORE-");
	mFont->Draw(58, 2, FillNumber(std::to_string(this->Score), 6));
	mFont->Draw(10, 11, "TIMER-");
	mFont->Draw(58, 11, FillNumber(std::to_string(this->remainingTime), 3));
	mFont->Draw(10, 20, "P-");
	mFont->Draw(28, 20, FillNumber(std::to_string(this->nNinjaLife), 2));
	CSprites::GetInstance()->Get(403)->Draw(45 + ItemRedShuriken_To_Center_X, 15 + ItemRedShuriken_To_Center_Y, 0, D3DXVECTOR2(0, 0));
	mFont->Draw(60, 20, "-" + FillNumber(std::to_string(this->Spirit), 2));
	mFont->Draw(110, 2, "STAGE-3-"+ std::to_string(SceneManager::GetInstance()->getState()));
	mFont->Draw(110, 11, "NINJA-");
	mFont->Draw(110, 20, "ENEMY-");
	switch (NinjaExtraWeaponType)
	{
	case eType::RedShuriken:
		CSprites::GetInstance()->Get(236)->Draw(92 + ItemRedShuriken_To_Center_X, 11 + ItemRedShuriken_To_Center_Y, 0, D3DXVECTOR2(0, 0));
		break;
	case eType::BlueShuriken:
		CSprites::GetInstance()->Get(230)->Draw(92 + ItemBlueShuriken_To_Center_X, 11 + ItemBlueShuriken_To_Center_Y, 0, D3DXVECTOR2(0, 0));
		break;
	case eType::Hadoken:
		CSprites::GetInstance()->Get(256)->Draw(92 + ItemBlueShuriken_To_Center_X, 11 + ItemBlueShuriken_To_Center_Y, 0, D3DXVECTOR2(0, 0));
		break;
	default:
		break;
	}

}

void CBoard::Update()
{
	this->remainingTime = GAME_MAX_TIME - Timer::GetInstance()->GetTime();
	this->Score = Ninja::GetInstance()->GetScore();
	this->nNinjaHealth = Ninja::GetInstance()->GetHealth();
	this->NinjaExtraWeaponType = Ninja::GetInstance()->GetExTraWeaponType();
	this->nNinjaLife = Ninja::GetInstance()->getLife();
	this->Spirit = Ninja::GetInstance()->getSpirit();
}

void CBoard::LoadAni()
{
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();

	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::Board);

	sprites->Add(300, 0, 0, 333,33,tex);
}

void CBoard::SetBossHealth(int health)
{
	this->BossHealth = health;
}

CBoard * CBoard::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new CBoard();
	}
	return _instance;
}


CBoard::~CBoard()
{
}
