#include "MapGenerator.h"
#include "Common.h"
#include "PlayerCharacter.h"
#include "TileBase.h"
#include "FirldTile.h"
#include "WallTile.h"
#include "GetItemTile.h"
#include "MaterialBase.h"
#include "DiaMaterial.h"
#include "GrassMaterial.h"
#include "AppleMaterial.h"

MapGenerator::MapGenerator( ) {

}

MapGenerator::~MapGenerator( ) {

}

void MapGenerator::Setup( ) {

	int map_data[ Parameters::MAP_HEIGHT ][ Parameters::MAP_WIDTH ];
	GenerateRandMap( map_data );

	//パラメーターの配列を基にタイル生成
	for ( int i = 0; i < Parameters::MAP_HEIGHT; i++ ) {
		for ( int j = 0; j < Parameters::MAP_WIDTH; j++ ) {
			//インデックスを座標変換
			double x = j * Parameters::GRAPH_MAP_WORLD_SIZE;
			double y = i * Parameters::GRAPH_MAP_WORLD_SIZE;
			Vector2 pos = { x,y };

			//マップデータの数字によってタイルを生成する
			int id = map_data[ i ][ j ];
			switch ( id ) {
			default:
				break;
			case 0:
				break;
			case 1:
				m_tiles.push_back( std::make_unique<WallTile>( pos ) );
				break;
			case 2:
			case 3:
				m_tiles.push_back( std::make_unique<FirldTile>( pos ) );
				break;
			case 4:
				m_tiles.push_back( std::make_unique<GetItemTile>( pos ) );
				break;
			}
		}
	}

	//マテリアル生成
	for ( std::unique_ptr<MaterialBase>& material : m_materials ) {
		material->Setup( );
	}
}

void MapGenerator::Update( ) {

}

void MapGenerator::Draw( Vector2 camera_pos ) {

}

std::vector<std::unique_ptr<TileBase>> MapGenerator::RemoveTiles( ) {
	return std::move( m_tiles );
}

std::vector<std::unique_ptr<MaterialBase>> MapGenerator::RemoveMaterials( ) {
	return std::move( m_materials );
}

void MapGenerator::GenerateRandMap( int( &map )[ Parameters::MAP_HEIGHT ][ Parameters::MAP_WIDTH ] ) {
	//マップを壁で埋める
	for ( int y = 0; y < Parameters::MAP_HEIGHT; y++ ) {
		for ( int x = 0; x < Parameters::MAP_WIDTH; x++ ) {
			//外周1マスは道にする
			if ( x >= 1 && x <= Parameters::MAP_WIDTH - 2 &&
				 y >= 1 && y <= Parameters::MAP_HEIGHT - 2 &&
				 ( x == 1 || x == Parameters::MAP_WIDTH - 2 ||
				   y == 1 || y == Parameters::MAP_HEIGHT - 2 ) ) {
				map[ y ][ x ] = 2;
			} else {
				map[ y ][ x ] = 1;
			}

		}
	}

	//方向を管理する配列
	int dir_x[ 4 ] = { 0,0,1,-1 };
	int dir_y[ 4 ] = { -1,1,0,0 };

	//スタート地点
	int current_x = Parameters::MAP_START_INDEX_WIDTH;
	int current_y = Parameters::MAP_START_INDEX_HEIGHT;
	map[ current_y ][ current_x ] = 3;

	//ゴール地点
	map[ Parameters::MAP_GOAL_INDEX_HEIGHT ][ Parameters::MAP_GOAL_INDEX_WIDTH ] = 4;

	//アイテムスポーン地点候補
	std::vector<Vector2> event_tiles;
	bool is_prev_jump = false;
	//無限ループ対策
	int dig_count = 0;
	while ( dig_count < Parameters::MAP_DIG_COUNT ) {

		dig_count++;

		//進行方向用の被りなし乱数生成
		int rand_num[ 4 ] = { 0,1,2,3 };
		for ( int c = 0; c < 4; c++ ) {
			int r = GetRand( c );
			int val = rand_num[ c ];
			rand_num[ c ] = rand_num[ r ];
			rand_num[ r ] = val;
		}

		//4方向確認
		for ( int i = 0; i < 4; i++ ) {
			//2マス先を確認する
			int dir_num = rand_num[ i ];
			int next_x = current_x + ( dir_x[ dir_num ] * 2 );
			int next_y = current_y + ( dir_y[ dir_num ] * 2 );
			//壁の外ならやめる
			if ( next_x < 1 || next_x > Parameters::MAP_WIDTH - 2 ||
				 next_y < 1 || next_y > Parameters::MAP_HEIGHT - 2 ) {
				continue;
			}
			//壁か外周の道なら進む
			if ( map[ next_y ][ next_x ] == 1 ||
				 map[ next_y ][ next_x ] == 2 ) {
				for ( int j = 0; j < 2; j++ ) {
					current_x += dir_x[ dir_num ];
					current_y += dir_y[ dir_num ];
					//道にする
					map[ current_y ][ current_x ] = 3;
				}
				//移動できた
				is_prev_jump = false;
				break;

			} else {
				//もし全方向進めず、先がゴールでない
				if ( i == 3 && map[ next_y ][ next_x ] != 4 ) {
					//前回強制的に飛んでいない
					if ( !is_prev_jump ) {
						is_prev_jump = true;
						//現在地を物をおく候補地にする
						Vector2 new_event_tile( current_x, current_y );
						if ( std::find( event_tiles.begin( ),
										event_tiles.end( ),
										new_event_tile ) == event_tiles.end( ) ) {
							event_tiles.push_back( new_event_tile );
						}
					}
					//強制的に飛ぶ
					current_x = next_x;
					current_y = next_y;
				}
			}
		}
	}



	for ( int i = 0; i < 3 && i < static_cast< int >( event_tiles.size( ) ); i++ ) {

		Vector2 pos = event_tiles[ i ];
		pos.x = pos.x * Parameters::GRAPH_MAP_WORLD_SIZE + Parameters::GRAPH_MAP_WORLD_RADIUS;
		pos.y = pos.y * Parameters::GRAPH_MAP_WORLD_SIZE + Parameters::GRAPH_MAP_WORLD_RADIUS;

		switch ( i ) {
		default:
			break;
		case 0:
			m_materials.push_back( std::make_unique<DiaMaterial>(
				Vector2( pos.x, pos.y )
			) );
			break;
		case 1:
			m_materials.push_back( std::make_unique<GrassMaterial>(
				Vector2( pos.x, pos.y )
			) );
			break;
		case 2:
			m_materials.push_back( std::make_unique<AppleMaterial>(
				Vector2( pos.x, pos.y )
			) );
			break;
		}
	}
}