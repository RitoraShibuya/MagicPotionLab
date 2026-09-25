#include "Resource.h"
#include "Dxlib.h"
#include "Parameters.h"
#include <array>

Resource::Resource( ) {
	m_icon_graph.fill( -1 );
	m_window_graph.fill( -1 );
	m_target_window_graph.fill( -1 );
	m_player_graph.fill( -1 );
	m_shadow_graph.fill( -1 );
	m_map_graph.fill( -1 );
	m_material_graph.fill( -1 );
}

Resource& Resource::GetInstance( ) {
	static Resource instance;
	return instance;
}

void Resource::LoadResource( ) {
	//フォントロード
	AddFontResourceEx( Parameters::ASSET_FONT, FR_PRIVATE, NULL );
	m_dot_font = CreateFontToHandle( Parameters::FONT_TYPE,
									 Parameters::FONT_SIZE,
									 Parameters::FONT_TICKNESS,
									 DX_FONTTYPE_EDGE );
	//タイトルフォントロード
	m_dot_title_font = CreateFontToHandle( Parameters::FONT_TYPE,
										   Parameters::FONT_TITLE_SIZE,
										   Parameters::FONT_TITLE_TICKNESS,
										   DX_FONTTYPE_EDGE,
										   -1,
										   Parameters::FONT_TITLE_EDGE,
										   FALSE,
										   -1 );
	//リザルトフォントロード
	m_dot_result_font = CreateFontToHandle( Parameters::FONT_TYPE,
											Parameters::FONT_RESULT_SIZE,
											Parameters::FONT_RESULT_TICKNESS,
											DX_FONTTYPE_EDGE );

	//アイコングラフィックロード
	LoadDivGraph( Parameters::GRAPH_ICON, Parameters::GRAPH_ICON_NUM_ALL,
				  Parameters::GRAPH_ICON_NUM_X,
				  Parameters::GRAPH_ICON_NUM_Y,
				  Parameters::GRAPH_ICON_SIZE,
				  Parameters::GRAPH_ICON_SIZE,
				  m_icon_graph.data( )
	);
	//ウィンドウグラフィックロード
	LoadDivGraph( Parameters::GRAPH_WINDOW, Parameters::GRAPH_WINDOW_NUM_ALL,
				  Parameters::GRAPH_WINDOW_NUM_X,
				  Parameters::GRAPH_WINDOW_NUM_Y,
				  Parameters::GRAPH_WINDOW_SIZE,
				  Parameters::GRAPH_WINDOW_SIZE,
				  m_window_graph.data( )
	);
	//目標ウィンドウグラフィックロード
	LoadDivGraph( Parameters::GRAPH_TARGET_WINDOW, Parameters::GRAPH_WINDOW_NUM_ALL,
				  Parameters::GRAPH_WINDOW_NUM_X,
				  Parameters::GRAPH_WINDOW_NUM_Y,
				  Parameters::GRAPH_WINDOW_SIZE,
				  Parameters::GRAPH_WINDOW_SIZE,
				  m_target_window_graph.data( )
	);
	//背景グラフィックロード
	m_back_ground_graph = LoadGraph( Parameters::GRAPH_BACK_GROUND );
	//タイトル背景グラフィックロード
	m_result_back_graph = LoadGraph( Parameters::GRAPH_RESULT_BACK );
	//タイトル背景グラフィックロード
	m_title_graph = LoadGraph( Parameters::GRAPH_TITLE );
	//マップグラフィックロード
	LoadDivGraph( Parameters::GRAPH_MAP, Parameters::GRAPH_MAP_NUM_ALL,
				  Parameters::GRAPH_MAP_NUM_X,
				  Parameters::GRAPH_MAP_NUM_Y,
				  Parameters::GRAPH_MAP_SIZE,
				  Parameters::GRAPH_MAP_SIZE,
				  m_map_graph.data( )
	);
	//影グラフィックロード
	LoadDivGraph( Parameters::GRAPH_SHADOW,
				  Parameters::GRAPH_SHADOW_NUM_ALL,
				  Parameters::GRAPH_SHADOW_NUM_X,
				  Parameters::GRAPH_SHADOW_NUM_Y,
				  Parameters::GRAPH_SHADOW_SIZE,
				  Parameters::GRAPH_SHADOW_SIZE,
				  m_shadow_graph.data( )
	);
	//プレイヤーグラフィックロード
	LoadDivGraph( Parameters::GRAPH_PLAYER, Parameters::GRAPH_PLAYER_NUM_ALL,
				  Parameters::GRAPH_PLAYER_NUM_X,
				  Parameters::GRAPH_PLAYER_NUM_Y,
				  Parameters::GRAPH_PLAYER_SIZE,
				  Parameters::GRAPH_PLAYER_SIZE,
				  m_player_graph.data( )
	);
	//素材グラフィックロード
	LoadDivGraph( Parameters::GRAPH_MATERIAL, Parameters::GRAPH_MATERIAL_NUM_ALL,
				  Parameters::GRAPH_MATERIAL_NUM_X,
				  Parameters::GRAPH_MATERIAL_NUM_Y,
				  Parameters::GRAPH_MATERIAL_SIZE,
				  Parameters::GRAPH_MATERIAL_SIZE,
				  m_material_graph.data( )
	);

	//タイトルBGMロード
	m_title_bgm = LoadSoundMem( Parameters::SOUND_BGM_TITLE );
	//タイトルBGMロード
	m_stage_bgm = LoadSoundMem( Parameters::SOUND_BGM_STAGE );
	//タイトルBGMロード
	m_result_bgm = LoadSoundMem( Parameters::SOUND_BGM_RESULT );

	//決定SEロード
	m_confirm_se = LoadSoundMem( Parameters::SOUND_SE_CONFIRM);
	//決定SEロード
	m_get_se = LoadSoundMem( Parameters::SOUND_SE_GET);
	//決定SEロード
	m_clear_se = LoadSoundMem( Parameters::SOUND_SE_CLEAR);
	//決定SEロード
	m_over_se = LoadSoundMem( Parameters::SOUND_SE_OVER);

	//デモ映像ロード
	m_demo_movie = LoadGraph( Parameters::MOVIE_DEMO );
}

void Resource::Finalize( ) {
	DeleteFontToHandle( m_dot_font );
	RemoveFontResourceEx( Parameters::ASSET_FONT, FR_PRIVATE, NULL );
}

int Resource::GetFontHandle( ) {
	return m_dot_font;
}

int Resource::GetTitleFontHandle( ) {
	return m_dot_title_font;
}

int Resource::GetResultFontHandle( ) {
	return m_dot_result_font;
}

std::array<int, Parameters::GRAPH_ICON_NUM_ALL> Resource::GetIconGraph( ) {
	return m_icon_graph;
}

std::array<int, Parameters::GRAPH_WINDOW_NUM_ALL> Resource::GetWindowGraph( ) {
	return m_window_graph;
}

std::array<int, Parameters::GRAPH_WINDOW_NUM_ALL> Resource::GetTargetWindowGraph( ) {
	return m_target_window_graph;
}

int Resource::GetBackGroundGraph( ) {
	return m_back_ground_graph;
}

int Resource::GetResultBackGraph( ) {
	return m_result_back_graph;
}

int Resource::GetTitleGraph( ) {
	return m_title_graph;
}

std::array<int, Parameters::GRAPH_MAP_NUM_ALL> Resource::GetMapGraph( ) {
	return m_map_graph;
}

std::array<int, Parameters::GRAPH_SHADOW_NUM_ALL> Resource::GetShadowGraph( ) {
	return m_shadow_graph;
}

std::array<int, Parameters::GRAPH_PLAYER_NUM_ALL> Resource::GetPlayerGraph( ) {
	return m_player_graph;
}

std::array<int, Parameters::GRAPH_MATERIAL_NUM_ALL> Resource::GetMaterialGraph( ) {
	return m_material_graph;
}

int Resource::GetTitleBGM( ) {
	return m_title_bgm;
}

int Resource::GetStageBGM( ) {
	return m_stage_bgm;
}

int Resource::GetResultBGM( ) {
	return m_result_bgm;
}

int Resource::GetConfirmSE( ) {
	return m_confirm_se;
}

int Resource::GetGetSE( ) {
	return m_get_se;
}

int Resource::GetClearSE( ) {
	return m_clear_se;
}

int Resource::GetOverSE( ) {
	return m_over_se;
}

int Resource::GetDemoMovie( ) {
	return m_demo_movie;
}