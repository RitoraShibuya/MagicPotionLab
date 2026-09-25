#pragma once
#include "Enum.h"
#include "UIBase.h"
#include <vector>
#include <memory>

class UIManager {
private:
	UIManager( );
	void FadeIn( );
	void FadeOut( );
	void UpdateFadeTimer( );
public:
	static UIManager& GetInstance( );
	void Setup( );
	void Update( );
	void Draw( );
	void PlayAnim(FadeState new_state, double fade_time );

	template <typename T>
	T* CreateUI( T* new_ui ) {
		m_ui.emplace_back( new_ui );
		m_ui.back( )->Setup( );
		return new_ui;
	}

	void RemoveUI( UIType type);
	void ClearAllUI( );

	FadeState m_state = FadeState::None;
	double m_current_fade_time = 0;
	double m_target_fade_time = 0;

	std::vector<std::unique_ptr<UIBase>> m_ui;
};

