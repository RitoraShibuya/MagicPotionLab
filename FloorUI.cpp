#include "FloorUI.h"
#include "Common.h"

FloorUI::FloorUI( int current_floor ) {
	int width = 10;
	std::wstring text = L"00/00";
	width = Parameters::FONT_SIZE + GetDrawStringWidthToHandle( text.c_str( ), ( int )text.length( ), Resource::GetInstance( ).GetFontHandle( ) );

	m_size = Vector2( width, Parameters::FONT_SIZE_2X );
	m_pos = Vector2( Parameters::WIDTH - width, 0 );

	m_current_floor = current_floor;
}

FloorUI::~FloorUI( ) {

}

void FloorUI::OnSetup( ) {

}

void FloorUI::OnUpdate( ) {

}

void FloorUI::Draw( ) {
	Draw9SliceWindow( m_min_x, m_min_y,
					  m_max_x, m_max_y );
	DrawFormatStringToHandle( ( int )m_pos.x + ( Parameters::FONT_SIZE_HALF ),
							  ( int )m_pos.y + ( Parameters::FONT_SIZE_HALF ),
							  GetColor( 255, 255, 255 ),
							  Resource::GetInstance( ).GetFontHandle( ),
							  L"%02d/%02d", m_current_floor, Parameters::STAGE_CLEAR_NUM );
}