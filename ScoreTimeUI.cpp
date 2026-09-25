#include "ScoreTimeUI.h"
#include "Common.h"

ScoreTimeUI::ScoreTimeUI( std::vector<double>times ) {
	m_size = Vector2( m_width, Parameters::STAGE_CLEAR_NUM * ( Parameters::FONT_SIZE_2X ) );
	m_pos = Vector2( Parameters::WINDOW_CENTER.x - m_size.x / 2,
					 Parameters::WINDOW_CENTER.y - m_size.y / 2);
	m_times = times;
}

ScoreTimeUI::~ScoreTimeUI( ) {

}

void ScoreTimeUI::OnSetup( ) {

}

void ScoreTimeUI::OnUpdate( ) {

}

void ScoreTimeUI::Draw( ) {
	Draw9SliceWindow( m_min_x, m_min_y,
					  m_max_x, m_max_y );
	for ( int i = 0; i < Parameters::STAGE_CLEAR_NUM; i++ ) {
		DrawFormatStringToHandle( ( int )m_pos.x + ( Parameters::FONT_SIZE_HALF ),
								  ( int )m_pos.y + ( Parameters::FONT_SIZE_HALF ) + ( i * Parameters::FONT_SIZE_2X ),
								  GetColor( 255, 255, 255 ),
								  Resource::GetInstance( ).GetFontHandle( ),
								  L"STAGE:%d Time：%05.2f", i + 1, m_times[ i ] );
	}
}
