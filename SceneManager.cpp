#include "SceneManager.h"
#include "TitleScene.h"
#include "MainStageScene.h"
#include "ResultScene.h"

SceneManager::SceneManager( ) {
	m_current_scene = std::make_unique<TitleScene>( );
	m_current_scene_type = m_current_scene->GetSceneType( );
	m_times.clear( );
}

SceneManager::~SceneManager( ) {

}

void SceneManager::Setup( ) {
	m_current_scene->Setup( );
	m_current_floor_num = 1;
}

void SceneManager::Update( ) {
	m_current_scene->Update( );

	CheckSceneChangeEvent( );
}

void SceneManager::CheckSceneChangeEvent( ) {
	if ( m_is_changing ) {
		return;
	}

	SceneChangeEvent request = m_current_scene->GetSceneChangeEvent( );

	if ( !request.is_end ) {
		return;
	}

	switch ( m_current_scene->GetSceneType( ) ) {
	default:
		break;
	case SceneType::Title:
		m_is_changing = true;
		UIManager::GetInstance( ).PlayAnim( FadeState::FadeOut, request.change_time );
		if ( request.is_clear ) {
			Time::GetInstance( ).SetTimeout( request.change_time, [ this ] ( ) {
				UIManager::GetInstance( ).ClearAllUI( );
				m_times.clear( );
				m_current_floor_num = 1;
				m_current_scene = std::make_unique<TitleScene>( );
				m_current_scene->Setup( );
				UIManager::GetInstance( ).PlayAnim( FadeState::FadeIn, 1.0 );
				m_is_changing = false;
			} );
		} else {
			Time::GetInstance( ).SetTimeout( request.change_time, [ this ] ( ) {
				UIManager::GetInstance( ).ClearAllUI( );
				m_current_scene = std::make_unique<MainStageScene>( m_current_floor_num );
				m_current_scene->Setup( );
				UIManager::GetInstance( ).PlayAnim( FadeState::FadeIn, 1.0 );
				m_is_changing = false;
			} );
		}
		break;
	case SceneType::Main:
		m_is_changing = true;
		UIManager::GetInstance( ).PlayAnim( FadeState::FadeOut, request.change_time );
		if ( CheckClear( request.is_clear ) ) {
			Time::GetInstance( ).SetTimeout( request.change_time, [ this ] ( ) {
				UIManager::GetInstance( ).ClearAllUI( );
				m_current_scene = std::make_unique<ResultScene>( m_times );
				m_current_scene->Setup( );
				UIManager::GetInstance( ).PlayAnim( FadeState::FadeIn, 1.0 );
				m_is_changing = false;
			} );
		} else {
			Time::GetInstance( ).SetTimeout( request.change_time, [ this ] ( ) {
				UIManager::GetInstance( ).ClearAllUI( );
				m_current_scene = std::make_unique<MainStageScene>( m_current_floor_num );
				m_current_scene->Setup( );
				UIManager::GetInstance( ).PlayAnim( FadeState::FadeIn, 1.0 );
				m_is_changing = false;
			} );
		}
		break;
	case SceneType::Result:
		m_is_changing = true;
		UIManager::GetInstance( ).PlayAnim( FadeState::FadeOut, request.change_time );
		Time::GetInstance( ).SetTimeout( request.change_time, [ this ] ( ) {
			UIManager::GetInstance( ).ClearAllUI( );
			m_times.clear( );
			m_current_floor_num = 1;
			m_current_scene = std::make_unique<TitleScene>( );
			m_current_scene->Setup( );
			UIManager::GetInstance( ).PlayAnim( FadeState::FadeIn, 1.0 );
			m_is_changing = false;
		} );
		break;
	}
}

bool SceneManager::CheckClear( bool is_clear ) {
	if ( is_clear ) {
		m_current_floor_num++;
		m_times.push_back( m_last_time + m_current_scene->GetTime( ) );
		m_last_time = 0.0;
		if ( m_current_floor_num > Parameters::STAGE_CLEAR_NUM ) {
			return true;
		}
	} else {
		m_last_time = m_current_scene->GetTime( );
	}
	return false;
}