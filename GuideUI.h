#pragma once
#include "UI.h"
#include "UIBase.h"
#include "Enum.h"
#include "DxLib.h"
#include "Parameters.h"
#include "Resource.h"
#include <string>

class GuideUI : public UI<UIType::None> {
public:
	GuideUI( );
	~GuideUI( );

	void Draw( ) override;
private:
	void OnSetup( )override;
	void OnUpdate( )override;

	std::wstring m_titile_text = L"Press Space";
	int m_title_width = Parameters::FONT_SIZE + GetDrawStringWidthToHandle( m_titile_text.c_str( ),
																			( int )m_titile_text.length( ),
																			Resource::GetInstance( ).GetFontHandle( ) );
	Vector2 m_pos = { Parameters::WINDOW_CENTER.x - m_title_width / 2,Parameters::HEIGHT - Parameters::FONT_SIZE_2X };
};

