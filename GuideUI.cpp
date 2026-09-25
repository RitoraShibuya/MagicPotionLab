#include "GuideUI.h"

GuideUI::GuideUI( ) {
	
}

GuideUI::~GuideUI( ) {

}

void GuideUI::OnSetup( ) {

}

void GuideUI::OnUpdate( ) {

}

void GuideUI::Draw( ) {
	DrawFormatStringToHandle( ( int )m_pos.x + ( Parameters::FONT_SIZE_HALF ),
							  ( int )m_pos.y + ( Parameters::FONT_SIZE_HALF ),
							  GetColor( 255, 255, 255 ),
							  Resource::GetInstance( ).GetFontHandle( ),
							  L"Press Space" );
}