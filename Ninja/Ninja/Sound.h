#ifndef __SOUND_H__
#define __SOUND_H__

#include "Game.h"
#include "dsutil.h"
#include <unordered_map>



enum eSound
{
	sound_Ninja_Die = 1,
	sound_Jump_Climb = 2,
	sound_Get_Attach = 3,
	sound_Enemy_Die = 4,
	sound_Get_Item = 5,
	sound_Get_Health_Item = 6,
	sound_Blue_Shuriken = 7,
	sound_Red_Shuriken = 8,
	sound_Hadoken = 9,
	sound_Time_tick_when_stop = 10,
	sound_GunRage_Attack = 11,
	sound_BombGun_Attack = 12,
	sound_Freeze = 13,
	sound_Normal_Attack = 14,
	sound_Boss_Die = 15,
	sound_Boss_Jump_Hit_Wall = 16,
	sound_Timer_Boss_Die = 17,

	music_Scence_1 = 51,
	music_Scence_2 = 52,
	music_Boss = 53,
};


class Sound
{
private:
	unordered_map<eSound, CSound* > _ArrSound;

public:
	static Sound * __Instance;
	static Sound * GetInstance();


	CSoundManager *dsound;

	void Init();
	Sound();

	void AddSound(eSound type, LPTSTR filename);
	void Play(eSound type, bool isLoop = false, LONG lVolume = 0L);
	void Stop(eSound type);
	void LoadResourceSound();

	bool isPlaying(eSound type);

	void StopAll();

};

#endif

