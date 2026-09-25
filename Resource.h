#pragma once
#include "Dxlib.h"
#include "Parameters.h"
#include <array>

class Resource {
private:
	Resource( );
	//フォント格納
	int m_dot_font = -1;
	//フォント格納
	int m_dot_title_font = -1;
	//フォント格納
	int m_dot_result_font = -1;

	//アイコングラフィック格納
	std::array<int, Parameters::GRAPH_ICON_NUM_ALL> m_icon_graph;
	//ウィンドウグラフィック格納
	std::array<int, Parameters::GRAPH_WINDOW_NUM_ALL> m_window_graph;
	//目標ウィンドウグラフィック格納
	std::array<int, Parameters::GRAPH_WINDOW_NUM_ALL> m_target_window_graph;
	//背景グラフィック格納
	int m_back_ground_graph = -1;
	//リザルト背景グラフィック格納
	int m_result_back_graph = -1;
	//タイトルグラフィック格納
	int m_title_graph = -1;
	//マップグラフィック格納
	std::array<int, Parameters::GRAPH_MAP_NUM_ALL> m_map_graph;
	//影グラフィック格納
	std::array<int, Parameters::GRAPH_SHADOW_NUM_ALL> m_shadow_graph;
	//プレイヤーグラフィック格納
	std::array<int, Parameters::GRAPH_PLAYER_NUM_ALL> m_player_graph;
	//素材グラフィック格納
	std::array<int, Parameters::GRAPH_MATERIAL_NUM_ALL> m_material_graph;

	//タイトルBGM
	int m_title_bgm = -1;
	//メインBGM
	int m_stage_bgm = -1;
	//リザルトBGM
	int m_result_bgm = -1;

	//決定SE
	int m_confirm_se = -1;
	//獲得SE
	int m_get_se = -1;
	//成功SE
	int m_clear_se = -1;
	//失敗SE
	int m_over_se = -1;

	//タイトル映像
	int m_demo_movie = -1;
public:
	//リソースクラス実体取得
	static Resource& GetInstance( );
	//リソース読み込み
	void LoadResource( );
	//リソース解放
	void Finalize( );

	//フォント取得
	int GetFontHandle( );
	//タイトル用フォント取得
	int GetTitleFontHandle( );
	//リザルト用フォント取得
	int GetResultFontHandle( );

	//アイコングラフィック取得
	std::array<int, Parameters::GRAPH_ICON_NUM_ALL> GetIconGraph( );
	//ウィンドウグラフィック取得
	std::array<int, Parameters::GRAPH_WINDOW_NUM_ALL> GetWindowGraph( );
	//目標ウィンドウグラフィック取得
	std::array<int, Parameters::GRAPH_WINDOW_NUM_ALL> GetTargetWindowGraph( );
	//背景グラフィック取得
	int GetBackGroundGraph( );
	//リザルト背景グラフィック取得
	int GetResultBackGraph( );
	//タイトルグラフィック取得
	int GetTitleGraph( );
	//マップグラフィック取得
	std::array<int, Parameters::GRAPH_MAP_NUM_ALL> GetMapGraph( );
	//影グラフィック取得
	std::array<int, Parameters::GRAPH_SHADOW_NUM_ALL> GetShadowGraph( );
	//プレイヤーグラフィック取得
	std::array<int, Parameters::GRAPH_PLAYER_NUM_ALL> GetPlayerGraph( );
	//素材グラフィック取得
	std::array<int, Parameters::GRAPH_MATERIAL_NUM_ALL> GetMaterialGraph( );

	//タイトルBGM取得
	int GetTitleBGM( );
	//ステージBGM取得
	int GetStageBGM( );
	//リザルトBGM取得
	int GetResultBGM( );

	//決定SE
	int GetConfirmSE( );
	//獲得SE
	int GetGetSE( );
	//成功SE
	int GetClearSE( );
	//失敗SE
	int GetOverSE( );

	//映像取得
	int GetDemoMovie( );
};

