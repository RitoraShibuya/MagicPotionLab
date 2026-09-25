#include "FirldTile.h"
#include "Common.h"

FirldTile::FirldTile( Vector2 new_pos ) : Tile( new_pos ) {

}

FirldTile::~FirldTile( ) {

}

void FirldTile::OnSetup( ) {

}

void FirldTile::OnUpdate( ) {

}

void FirldTile::Draw( Vector2 camera_pos ) {
	DrawExtendGraph( ( int )( m_pos.x - camera_pos.x ),
			   ( int )( m_pos.y - camera_pos.y ),
			   ( int )( m_pos.x - camera_pos.x ) + Parameters::GRAPH_MAP_WORLD_SIZE,
			   ( int )( m_pos.y - camera_pos.y ) + Parameters::GRAPH_MAP_WORLD_SIZE,
			   Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_MAP_INDEX_FIRLD ),
			   TRUE );
}