#include "TimerUI.h"
#include "Common.h"

TimerUI::TimerUI( ) {
	int width = 10;
	std::wstring text = L"00/00";
	width = Parameters::FONT_SIZE + GetDrawStringWidthToHandle( text.c_str( ), ( int )text.length( ), Resource::GetInstance( ).GetFontHandle( ) );

	m_size = Vector2( width, Parameters::FONT_SIZE_2X );
	m_pos = Vector2( 0, 0 );
}

TimerUI::~TimerUI( ) {

}

void TimerUI::OnSetup( ) {
	
}

void TimerUI::OnUpdate( ) {

}

void TimerUI::Draw( ) {
	Draw9SliceWindow( m_min_x, m_min_y,
					  m_max_x, m_max_y );
	DrawFormatStringToHandle( ( int )m_pos.x + ( Parameters::FONT_SIZE_HALF ),
							  ( int )m_pos.y + ( Parameters::FONT_SIZE_HALF),
							  GetColor( 255, 255, 255 ),
							  Resource::GetInstance( ).GetFontHandle( ),
							  L"%05.2f", m_current_time );
}

void TimerUI::SetTime(double current_time ) {
	m_current_time = current_time;
}