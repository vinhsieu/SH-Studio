
#include "Sound.h"
#include <tchar.h>
Sound* Sound::__Instance = NULL;

Sound::Sound()
{
	Init();
	LoadResourceSound();
}



void Sound::LoadResourceSound()
{
	AddSound(eSound::sound_Ninja_Die, L"Resources/sound/01_Player_Die.wav");
	AddSound(eSound::sound_Jump_Climb, L"Resources/sound/02_Jump&Climb.wav");
	AddSound(eSound::sound_Get_Attach, L"Resources/sound/03_Get_Attack.wav");
	AddSound(eSound::sound_Enemy_Die, L"Resources/sound/04_Enemy_Die.wav");
	AddSound(eSound::sound_Get_Item, L"Resources/sound/05_Get_Item.wav");
	AddSound(eSound::sound_Get_Health_Item, L"Resources/sound/06_Get_Health_Item.wav");



	AddSound(eSound::sound_Blue_Shuriken, L"Resources/sound/07_Blue_Shuriken.wav");
	AddSound(eSound::sound_Red_Shuriken, L"Resources/sound/08_Red_Shuriken.wav");
	AddSound(eSound::sound_Hadoken, L"Resources/sound/09_Hadoken.wav");
	AddSound(eSound::sound_Time_tick_when_stop, L"Resources/sound/10_Time_tick_when_stop.wav");
	AddSound(eSound::sound_GunRage_Attack, L"Resources/sound/11_GunRage_Attack.wav");
	AddSound(eSound::sound_BombGun_Attack, L"Resources/sound/12_BombGun_Attack.wav");
	AddSound(eSound::sound_Freeze, L"Resources/sound/13_Freeze.wav");
	 

	AddSound(eSound::sound_Normal_Attack, L"Resources/sound/14_Normal_Attack.wav");
	AddSound(eSound::sound_Boss_Die, L"Resources/sound/15_Boss_Die.wav");
	AddSound(eSound::sound_Boss_Jump_Hit_Wall, L"Resources/sound/16_Boss_Jump_Hit_Wall.wav");


	AddSound(eSound::music_Scence_1, L"Resources/sound/51_Scence_3.1.wav");
	AddSound(eSound::music_Scence_2, L"Resources/sound/52_Scence_3.2.wav");
	AddSound(eSound::music_Boss, L"Resources/sound/53_Scence_Boss.wav");
	
}

bool Sound::isPlaying(eSound type)
{
	return _ArrSound[type]->IsSoundPlaying();
}

void Sound::StopAll()
{ 
	for (auto& x : _ArrSound)
	{   
		if (x.second->IsSoundPlaying())
			x.second->Stop(); 
	} 
}


void Sound::AddSound(eSound type, LPTSTR filename)
{
 	CSound *wave;
 	HRESULT result= dsound->Create(&wave, filename);
	if (result != DS_OK)
	{
		DebugOut(L"[SOUND] Load Sound that bai. eSound = %d \n", (int)type);
		return;
	} 
	_ArrSound[type] = wave;
}

void Sound::Play(eSound type, bool isLoop, LONG lVolume)
{
	_ArrSound[type]->Play(0, isLoop, lVolume);
	//DSBPLAY_LOOPING             0x00000001 -> int = 1

}

void Sound::Stop(eSound type)
{
	_ArrSound[type]->Stop();
}



void Sound::Init()
{
	dsound = new CSoundManager();
	dsound->Initialize(CGame::GetInstance()->hWnd, DSSCL_PRIORITY);
	dsound->SetPrimaryBufferFormat(2, 22050, 16);
}

Sound * Sound::GetInstance()
{
	if (__Instance == NULL)
		__Instance = new Sound();
	return __Instance;
} 