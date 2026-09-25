#include "UIManager.h"
#include "Common.h"
#include "UIBase.h"
#include "TargetMaterialUI.h"

UIManager::UIManager( ) {

}

UIManager& UIManager::GetInstance( ) {
	static UIManager instance;
	return instance;
}

void UIManager::Setup( ) {
	for ( std::unique_ptr<UIBase>& ui : m_ui ) {
		ui->Setup( );
	}
}

void UIManager::Update( ) {
	int mx;
	int my;
	GetMousePoint( &mx, &my );

	for ( std::unique_ptr<UIBase>& ui : m_ui ) {
		ui->Update( mx, my );
	}

	UpdateFadeTimer( );
}

void UIManager::Draw( ) {
	for ( std::unique_ptr<UIBase>& ui : m_ui ) {
		ui->Draw( );
	}

	switch ( m_state ) {
	default:
		break;
	case FadeState::None:
		break;
	case FadeState::FadeIn:
		FadeIn( );
		break;
	case FadeState::FadeOut:
		FadeOut( );
		break;
	}
}

void UIManager::UpdateFadeTimer( ) {
	if ( m_current_fade_time > m_target_fade_time ) {
		m_current_fade_time = 0;
		m_target_fade_time = 0;
		m_state = FadeState::None;
	} else {
		m_current_fade_time += Time::GetInstance( ).GetDeltaTime( );
	}
}

void UIManager::PlayAnim( FadeState new_state, double fade_time ) {
	m_current_fade_time = 0;
	m_state = new_state;
	m_target_fade_time = fade_time;
}

void UIManager::FadeIn( ) {
	double rate = m_current_fade_time / m_target_fade_time;
	rate = std::clamp( rate, 0.0, 1.0 );
	int alpha = ( int )( rate * 255 );
	alpha = 255 - alpha;
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, alpha );
	DrawBox( 0, 0, Parameters::WIDTH, Parameters::HEIGHT, GetColor( 0, 0, 0 ), TRUE );
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}

void UIManager::FadeOut( ) {
	double rate = m_current_fade_time / m_target_fade_time;
	rate = std::clamp( rate, 0.0, 1.0 );
	int alpha = ( int )( rate * 255 );
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, alpha );
	DrawBox( 0, 0, Parameters::WIDTH, Parameters::HEIGHT, GetColor( 0, 0, 0 ), TRUE );
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}

void UIManager::RemoveUI( UIType type ) {
	std::erase_if( m_ui, [ type ] ( const std::unique_ptr<UIBase>& ui ) {
		return ui->GetUIType( ) == type;
	} );
}

void UIManager::ClearAllUI( ) {
	m_ui.clear( );
}