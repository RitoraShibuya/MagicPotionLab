#include "TotalScoreUI.h"
#include "Common.h"

TotalScoreUI::TotalScoreUI(double total_time ) {
	m_size = Vector2( m_width, Parameters::FONT_RESULT_SIZE_2X );
	m_pos = Vector2( Parameters::WINDOW_CENTER.x - m_size.x / 2,
					 0 );
	m_total_time = total_time;
}

TotalScoreUI::~TotalScoreUI( ) {

}

void TotalScoreUI::OnSetup( ) {

}

void TotalScoreUI::OnUpdate( ) {

}

void TotalScoreUI::Draw( ) {
	Draw9SliceWindow( m_min_x, m_min_y,
					  m_max_x, m_max_y );
	DrawFormatStringToHandle( ( int )m_pos.x + ( Parameters::FONT_RESULT_SIZE_HALF ),
							  ( int )m_pos.y + ( Parameters::FONT_RESULT_SIZE_HALF ),
							  GetColor( 255, 255, 255 ),
							  Resource::GetInstance( ).GetResultFontHandle( ),
							  L"TotalTime：%06.2f", m_total_time );

}