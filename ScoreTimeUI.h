#pragma once
#include "UI.h"
#include "UIBase.h"
#include "Enum.h"
#include "Parameters.h"
#include "DxLib.h"
#include "Resource.h"
#include <string>
#include <vector>

class ScoreTimeUI : public UI<UIType::Score> {
public:
	ScoreTimeUI( std::vector<double>times );
	~ScoreTimeUI( );

	void Draw( )override;
private:
	void OnSetup( )override;
	void OnUpdate( )override;

	std::vector<double>m_times;
	std::wstring m_dammy_text = L"STAGE:0 Time：00.00";
	int m_width = Parameters::FONT_SIZE + GetDrawStringWidthToHandle( m_dammy_text.c_str( ),
																	  ( int )m_dammy_text.length( ),
																	  Resource::GetInstance( ).GetFontHandle( ) );
};

