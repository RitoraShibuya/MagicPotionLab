#pragma once
#include "UI.h"
#include "UIBase.h"
#include "Enum.h"
#include "Parameters.h"
#include "DxLib.h"
#include "Resource.h"
#include <string>

class TotalScoreUI : public UI<UIType::Score> {
public:
	TotalScoreUI( double total_time );
	~TotalScoreUI( );

	void Draw( ) override;

private:
	void OnSetup( )override;
	void OnUpdate( )override;

	double m_total_time = 0.0;
	std::wstring m_dammy_text = L"TotalTime：000.00";
	int m_width = Parameters::FONT_RESULT_SIZE + GetDrawStringWidthToHandle( m_dammy_text.c_str( ),
																	  ( int )m_dammy_text.length( ),
																	  Resource::GetInstance( ).GetResultFontHandle( ) );
};

