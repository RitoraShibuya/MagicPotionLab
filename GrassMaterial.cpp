#include "GrassMaterial.h"
#include "Material.h"
#include "Common.h"

GrassMaterial::GrassMaterial( Vector2 new_pos ) : Material( new_pos ) {

}

GrassMaterial::~GrassMaterial( ) {

}

void GrassMaterial::OnSetup( ) {

}

void GrassMaterial::OnUpdate( ) {

}

void GrassMaterial::Draw( Vector2 camera_pos ) {
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
				   Resource::GetInstance( ).GetMaterialGraph( ).at( 3 ),
				   TRUE );
}