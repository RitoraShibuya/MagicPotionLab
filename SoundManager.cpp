#include "SoundManager.h"
#include "Dxlib.h"
#include "Enum.h"

SoundManager::SoundManager( ) {
	m_current_bgm = -1;
}

SoundManager& SoundManager::GetInstance( ) {
	static SoundManager instance;
	return instance;
}

void SoundManager::Finalize( ) {

}

void SoundManager::PlayBGM( ) {
	if ( m_current_bgm != -1 ) {
		StopSoundMem( m_current_bgm );
		m_current_bgm = -1;
	}
}

void SoundManager::PlaySE( ) {

}

void SoundManager::PlayAudio( int handle, SoundType type ) {
	if ( handle < 0 ) {
		return;
	}
	ChangeVolumeSoundMem( 100, handle );
	switch ( type ) {
	default:
		break;
	case SoundType::BGM:
		PlayBGM( );
		PlaySoundMem( handle, DX_PLAYTYPE_LOOP );
		m_current_bgm = handle;
		break;
	case SoundType::SE:
		PlaySE( );
		PlaySoundMem( handle, DX_PLAYTYPE_BACK );
		break;
	}
}
