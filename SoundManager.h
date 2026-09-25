#pragma once
#include "Enum.h"

class SoundManager {
private:
	SoundManager( );

	void PlayBGM( );
	void PlaySE( );
public:
	static SoundManager& GetInstance( );

	void Finalize( );

	void PlayAudio( int handle, SoundType type );

private:
	int m_current_bgm = -1;
};

