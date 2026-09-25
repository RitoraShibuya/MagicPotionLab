#include "DiaMaterial.h"
#include "Material.h"
#include "Common.h"

DiaMaterial::DiaMaterial( Vector2 new_pos ) : Material( new_pos ) {

}

DiaMaterial::~DiaMaterial( ) {

}

void DiaMaterial::OnSetup( ) {

}

void DiaMaterial::OnUpdate( ) {

}

void DiaMaterial::Draw( Vector2 camera_pos ) {
	//影描画
	DrawRotaGraph( ( int )( m_pos.x - camera_pos.x ),
				   ( int )( m_pos.y - 5 - camera_pos.y ),
				   1.0,
				   0.0,
				   Resource::GetInstance( ).GetShadowGraph( ).at( 0 ),
				   TRUE );
	//素材描画
	DrawRotaGraph( ( int )( m_pos.x - camera_pos.x ),
				   ( int )( m_pos.y - camera_pos.y ),
				   1.0,
				   0.0,
				   Resource::GetInstance( ).GetMaterialGraph( ).at( 1 ),
				   TRUE );
}