#include "GetItemTile.h"
#include "Common.h"

GetItemTile::GetItemTile( Vector2 new_pos ) :Tile( new_pos ) {

}

GetItemTile::~GetItemTile( ) {

}

void GetItemTile::OnSetup( ) {

}

void GetItemTile::OnUpdate( ) {
	m_anim_time += Time::GetInstance( ).GetDeltaTime( );
	if ( m_anim_time > Parameters::GOAL_ANIM_TIME ) {
		m_anim_time -= Parameters::GOAL_ANIM_TIME;
		m_anim_index = ( m_anim_index + 1 ) % 3;
	}
}

void GetItemTile::Draw( Vector2 camera_pos ) {
	DrawExtendGraph( ( int )( m_pos.x - camera_pos.x ),
					 ( int )( m_pos.y - camera_pos.y ),
					 ( int )( m_pos.x - camera_pos.x ) + Parameters::GRAPH_MAP_WORLD_SIZE,
					 ( int )( m_pos.y - camera_pos.y ) + Parameters::GRAPH_MAP_WORLD_SIZE,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_MAP_INDEX_FIRLD ),
					 TRUE );
	DrawExtendGraph( ( int )( m_pos.x - camera_pos.x ),
					 ( int )( m_pos.y - camera_pos.y ),
					 ( int )( m_pos.x - camera_pos.x ) + Parameters::GRAPH_MAP_WORLD_SIZE,
					 ( int )( m_pos.y - camera_pos.y ) + Parameters::GRAPH_MAP_WORLD_SIZE,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_MAP_INDEX_MAGIC_CIRECLE ),
					 TRUE );

	int dist = Parameters::GRAPH_MAP_WORLD_RADIUS;
	DrawExtendGraph( ( int )( m_pos.x - camera_pos.x - dist ),
					 ( int )( m_pos.y - camera_pos.y - Parameters::GRAPH_ICON_SIZE - dist ),
					 ( int )( m_pos.x - camera_pos.x ) + Parameters::GRAPH_ICON_SIZE + dist,
					 ( int )( m_pos.y - camera_pos.y ) + dist,//+Parameters::GRAPH_MAP_WORLD_SIZE - Parameters::GRAPH_MAP_WORLD_SIZE,
					 Resource::GetInstance( ).GetIconGraph( ).at( Parameters::GOAL_INDEX + m_anim_index ),
					 TRUE );
	/*DrawExtendGraph( ( int )( m_pos.x - camera_pos.x ),
					 ( int )( m_pos.y - camera_pos.y - Parameters::GRAPH_ICON_SIZE ),
					 ( int )( m_pos.x - camera_pos.x ) + Parameters::GRAPH_MAP_WORLD_SIZE,
					 ( int )( m_pos.y - camera_pos.y ),
					 Resource::GetInstance( ).GetMapGraph( ).at( 2 ),
					 TRUE );*/
}
