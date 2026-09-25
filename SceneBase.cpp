#include "SceneBase.h"
#include "Common.h"

void SceneBase::Setup( ) {


	OnSetup( );
}

void SceneBase::Update( ) {
	m_current_time += Time::GetInstance( ).GetDeltaTime( );

	if ( m_current_time > Parameters::SCENE_AUTO_CHAGE_TIME ) {
		RequestSceneChange( true );
	}

	OnUpdate( );
}

SceneChangeEvent SceneBase::GetSceneChangeEvent( ) {
	return m_change_event;
}

double SceneBase::GetTime( ) {
	return m_current_time;
}

void SceneBase::RequestSceneChange( bool is_clear ) {
	m_change_event.change_time = 1.0;
	m_change_event.is_end = true;
	m_change_event.is_clear = is_clear;
}
