#include "MainStageScene.h"
#include "Common.h"
#include "PlayerCharacter.h"
#include "MaterialBase.h"
#include "DiaMaterial.h"
#include "Camera.h"
#include "MapGenerator.h"
#include "TileBase.h"
#include "GetItemTile.h"
#include "TargetMaterialUI.h"
#include "TimerUI.h"
#include "FloorUI.h"

MainStageScene::MainStageScene( int floor_num ) {
	m_map_generator = std::make_unique<MapGenerator>( );
	m_player = std::make_unique<PlayerCharacter>( );
	m_camera = std::make_unique<Camera>( );
	m_current_floor_num = floor_num;
}

MainStageScene::~MainStageScene( ) {

}

void MainStageScene::OnSetup( ) {
	//初期化順　マップ→プレイヤー→カメラ
	m_map_generator->Setup( );
	m_player->Setup( );
	m_camera->Setup( );

	//マップを取得
	m_tiles = std::move( m_map_generator->RemoveTiles( ) );
	m_materials = std::move( m_map_generator->RemoveMaterials( ) );

	//プレイヤーの初期位置設定
	m_player->SetPos( Vector2(
		Parameters::MAP_START_INDEX_WIDTH * Parameters::GRAPH_MAP_WORLD_SIZE + Parameters::GRAPH_MAP_WORLD_RADIUS,
		Parameters::MAP_START_INDEX_HEIGHT * Parameters::GRAPH_MAP_WORLD_SIZE + Parameters::GRAPH_MAP_WORLD_RADIUS
	) );

	//素材取得順序生成
	MakeTargetMaterilas( );

	//素材UI生成
	UIManager::GetInstance( ).CreateUI( new TargetMaterialUI(
		m_target_materials[ 0 ],
		m_target_materials[ 1 ],
		m_target_materials[ 2 ] ) );
	//タイマーUI生成
	m_timer_ui = UIManager::GetInstance( ).CreateUI( new TimerUI( ) );
	//階層UI生成
	UIManager::GetInstance( ).CreateUI( new FloorUI( m_current_floor_num ) );
	

	//BGM再生
	SoundManager::GetInstance().PlayAudio(Resource::GetInstance().GetStageBGM(),SoundType::BGM );
}

void MainStageScene::OnUpdate( ) {
	DrawExtendGraph( 0, 0,
					 Parameters::WIDTH, Parameters::HEIGHT,
					 Resource::GetInstance( ).GetBackGroundGraph( ), FALSE );

	//タイマーUI値設定
	m_timer_ui->SetTime( GetTime( ) );

	//更新順　マップ→素材→プレイヤー→カメラ
	for ( const std::unique_ptr<TileBase>& tile : m_tiles ) {
		tile->Update( );
	}
	for ( std::unique_ptr<MaterialBase>& material : m_materials ) {
		material->Update( );
	}

	//プレイヤーの当たり判定の感触用に例外でここで壁判定
	m_player->Update( );
	m_camera->Update( m_player->GetPos( ) );

	//当たり判定関係
	CheckHitPlayerToTile( );
	CheckHitPlayerToMaterials( );
	CheckDestroyMaterials( );

	//描画順　マップ→素材→プレイヤー
	for ( std::unique_ptr<TileBase>& tile : m_tiles ) {
		tile->Draw( m_camera->GetPos( ) );
	}
	for ( std::unique_ptr<MaterialBase>& material : m_materials ) {
		material->Draw( m_camera->GetPos( ) );
	}
	m_player->Draw( m_camera->GetPos( ) );
}

void MainStageScene::MakeTargetMaterilas( ) {
	MaterialType types[ 3 ] = {
		MaterialType::Fire,
		MaterialType::Grass,
		MaterialType::Water };

	
	for ( int i = 0; i < 3; i++ ) {
		int rand_num = GetRand( 2 );
		MaterialType copy = types[ i ];
		types[ i ] = types[ rand_num ];
		types[ rand_num ] = copy;
	}
	

	for ( int i = 0; i < 3; i++ ) {
		m_target_materials.push_back( types[ i ] );
	}
}

void MainStageScene::CheckHitPlayerToTile( ) {
	//今回重なったタイルの配列
	std::unordered_set<TileBase*> current_overlap_tiles;
	//プレイヤー座標取得
	Vector2 p_pos = m_player->GetPos( );
	//プレイヤー半径取得
	Vector2 p_radius = m_player->GetRadius( );

	//Box座標生成
	Vector2 p_pos_min = p_pos - p_radius;
	Vector2 p_pos_max = p_pos + p_radius;

	//タイル枚数分チェック
	for ( std::unique_ptr<TileBase>& tile : m_tiles ) {
		//壁でも重なりでも無いなら離脱
		if ( tile->GetType( ) != TileType::Wall &&
			 tile->GetType( ) != TileType::Item ) {
			continue;
		}

		//タイル原点座標取得＋Box座標生成
		Vector2 w_pos_min = tile->GetPos( );
		Vector2 w_pos_max = w_pos_min + tile->GetSize( );

		//x座標重なり計算
		if ( p_pos_max.x >= w_pos_min.x &&
			 p_pos_min.x <= w_pos_max.x ) {
			//y座標重なり検知
			if ( p_pos_max.y >= w_pos_min.y &&
				 p_pos_min.y <= w_pos_max.y ) {

				//タイプで分岐
				switch ( tile->GetType( ) ) {
				default:
					break;
				case TileType::Wall:
					// プレイヤーに壁にあたったことを通知
					m_player->OnHitWall( );
					break;
				case TileType::Item:
					//今回のフレームで重なったタイルに追加する
					current_overlap_tiles.insert( tile.get( ) );
					//前回重なったタイルにいるか確認する
					std::unordered_set<TileBase*>::iterator it = m_prev_overlap_tiles.find( tile.get( ) );
					//なければendを返す
					if ( it == m_prev_overlap_tiles.end( ) ) {
						//プレイヤーの持っている素材をすべて受け取る
						m_material_types = m_player->RemoveMaterial( );
						if ( m_material_types == m_target_materials ) {
							OnGameClear( );
						} else {
							OnGameOver( );
						}
					}
					break;
				}
			}
		}
	}
	//今回重なった床情報をコピー
	m_prev_overlap_tiles = std::move( current_overlap_tiles );

}

void MainStageScene::CheckHitPlayerToMaterials( ) {
	//プレイヤー座標取得
	Vector2 p_pos = m_player->GetPos( );
	//当たり判定距離計算
	double total_radius = Parameters::PLAYER_RADIUS + Parameters::MATERIAL_RADIUS;
	//当たり判定の二乗
	double hit_range = total_radius * total_radius;
	//フィールドの素材個数分計算
	for ( std::unique_ptr<MaterialBase>& material : m_materials ) {
		if ( material->GetDestroyRequested( ) ) {
			continue;
		}
		//プレイヤーとの距離の二乗を計算
		double dist = ( p_pos - material->GetPos( ) ).LengthSq( );
		//当たり判定の二乗と比較し、距離がそれ以上なら当たっているない
		if ( dist > hit_range ) {
			continue;
		}
		//プレイヤーに当たった素材を通知
		m_player->OnHitMaterial( material.get( ) );
		//素材に当たった時の処理を通知
		material->OnHitPlayer( );

	}
}

void MainStageScene::CheckDestroyMaterials( ) {
	//破壊を求めている素材を破壊する
	m_materials.erase(
		std::remove_if( m_materials.begin( ), m_materials.end( ),
						[ ] ( const std::unique_ptr<MaterialBase>& material ) {
		return material->GetDestroyRequested( );
	}
		),
		m_materials.end( )
	);
}

void MainStageScene::RemakeMap( ) {
	m_map_generator->Setup( );
	m_player->Setup( );
	m_camera->Setup( );

	m_tiles = std::move( m_map_generator->RemoveTiles( ) );
	m_materials = std::move( m_map_generator->RemoveMaterials( ) );

	m_player->SetPos( Vector2(
		Parameters::MAP_START_INDEX_WIDTH * Parameters::GRAPH_MAP_WORLD_SIZE + Parameters::GRAPH_MAP_WORLD_RADIUS,
		Parameters::MAP_START_INDEX_HEIGHT * Parameters::GRAPH_MAP_WORLD_SIZE + Parameters::GRAPH_MAP_WORLD_RADIUS
	) );
}

void MainStageScene::OnGameClear( ) {
	m_player->OnHitCircle( true );
	Time::GetInstance( ).SetTimeout( 1.0, [ this ] ( ) {
		RequestSceneChange( true );
	} );
}

void MainStageScene::OnGameOver( ) {
	m_player->OnHitCircle( false );
	Time::GetInstance( ).SetTimeout( 1.0, [ this ] ( ) {
		RequestSceneChange( false );
	} );
}