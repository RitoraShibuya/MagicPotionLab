#pragma once
#include "Struct.h"
#include <tchar.h>

namespace Parameters {
//画面横幅
inline constexpr int WIDTH = 800;
//画面縦幅
inline constexpr int HEIGHT = 600;
//画面横中心
inline constexpr int CENTER_WIDTH = WIDTH / 2;
//画面縦中心
inline constexpr int CENTER_HEIGHT = HEIGHT / 2;
//画面中心
inline constexpr Vector2 WINDOW_CENTER = { ( double )CENTER_WIDTH,( double )CENTER_HEIGHT };

//フォントパス
inline constexpr const TCHAR* ASSET_FONT = _T( "Assets/Font.ttf" );
//フォント
inline constexpr const wchar_t* FONT_TYPE = L"DotGothic16";
//フォントサイズ
inline constexpr int FONT_SIZE = 24;
//フォントサイズ2倍
inline constexpr int FONT_SIZE_2X = FONT_SIZE * 2;
//フォントサイズ1/2
inline constexpr int FONT_SIZE_HALF = (int)(FONT_SIZE * 0.5);
//フォント太さ
inline constexpr int FONT_TICKNESS = 6;

//タイトルフォントサイズ
inline constexpr int FONT_TITLE_SIZE = 72;
//タイトルフォントサイズ2倍
inline constexpr int FONT_TITLE_SIZE_2X = FONT_TITLE_SIZE * 2;
//タイトルフォントサイズ1/2
inline constexpr int FONT_TITLE_SIZE_HALF = ( int )( FONT_TITLE_SIZE * 0.5 );
//タイトルフォント太さ
inline constexpr int FONT_TITLE_TICKNESS = 9;
//タイトルフォントエッジ太さ
inline constexpr int FONT_TITLE_EDGE = 3;

//リザルトフォントサイズ
inline constexpr int FONT_RESULT_SIZE = 48;
//リザルトフォントサイズ2倍
inline constexpr int FONT_RESULT_SIZE_2X = FONT_RESULT_SIZE * 2;
//リザルトフォントサイズ1/2
inline constexpr int FONT_RESULT_SIZE_HALF = ( int )( FONT_RESULT_SIZE * 0.5 );
//リザルトフォント太さ
inline constexpr int FONT_RESULT_TICKNESS = 10;

//アイコングラフィックパス
inline constexpr const TCHAR* GRAPH_ICON = _T( "Assets/Emotion.png" );
//総分割数
inline constexpr int GRAPH_ICON_NUM_ALL = 270;
//横分割数
inline constexpr int GRAPH_ICON_NUM_X = 30;
//縦分割数
inline constexpr int GRAPH_ICON_NUM_Y = 9;
//ピクセルサイズ
inline constexpr int GRAPH_ICON_SIZE = 32;

//ウィンドウグラフィックパス
inline constexpr const TCHAR* GRAPH_WINDOW = _T( "Assets/Window.png" );
//総分割数
inline constexpr int GRAPH_WINDOW_NUM_ALL = 9;
//横分割数
inline constexpr int GRAPH_WINDOW_NUM_X = 3;
//縦分割数
inline constexpr int GRAPH_WINDOW_NUM_Y = 3;
//ピクセルサイズ
inline constexpr int GRAPH_WINDOW_SIZE = 10;

//目標ウィンドウグラフィックパス
inline constexpr const TCHAR* GRAPH_TARGET_WINDOW = _T( "Assets/TargetWindow.png" );

//背景グラフィックパス
inline constexpr const TCHAR* GRAPH_BACK_GROUND = _T( "Assets/BackGround.jpg" );

//リザルト背景グラフィックパス
inline constexpr const TCHAR* GRAPH_RESULT_BACK = _T( "Assets/ResultBack.jpg" );

//タイトルグラフィックパス
inline constexpr const TCHAR* GRAPH_TITLE = _T( "Assets/Title.png" );

//マップグラフィックパス
inline constexpr const TCHAR* GRAPH_MAP = _T( "Assets/Map.png" );
//総分割数
inline constexpr int GRAPH_MAP_NUM_ALL = 1992;
//横分割数
inline constexpr int GRAPH_MAP_NUM_X = 8;
//縦分割数
inline constexpr int GRAPH_MAP_NUM_Y = 249;
//ピクセルサイズ
inline constexpr int GRAPH_MAP_SIZE = 32;
//ワールドサイズ
inline constexpr int GRAPH_MAP_WORLD_SIZE = 32;
//ワールド半径サイズ
inline constexpr int GRAPH_MAP_WORLD_RADIUS = GRAPH_MAP_WORLD_SIZE / 2;
//フィールド素材開始インデックス
inline constexpr int GRAPH_MAP_START_INDEX = 72;
//床インデックス
inline constexpr int GRAPH_MAP_INDEX_FIRLD = 0;
//壁インデックス
inline constexpr int GRAPH_MAP_INDEX_WALL = 42;
//魔法陣インデックス
inline constexpr int GRAPH_MAP_INDEX_MAGIC_CIRECLE = 70;

//プレイヤーグラフィックパス
inline constexpr const TCHAR* GRAPH_PLAYER = _T( "Assets/Character.png" );
//総分割数
inline constexpr int GRAPH_PLAYER_NUM_ALL = 12;
//横分割数
inline constexpr int GRAPH_PLAYER_NUM_X = 3;
//縦分割数
inline constexpr int GRAPH_PLAYER_NUM_Y = 4;
//ピクセルサイズ
inline constexpr int GRAPH_PLAYER_SIZE = 32;

//影グラフィックパス
inline constexpr const TCHAR* GRAPH_SHADOW = _T( "Assets/Shadow.png" );
//総分割数
inline constexpr int GRAPH_SHADOW_NUM_ALL = 12;
//横分割数
inline constexpr int GRAPH_SHADOW_NUM_X = 3;
//縦分割数
inline constexpr int GRAPH_SHADOW_NUM_Y = 4;
//ピクセルサイズ
inline constexpr int GRAPH_SHADOW_SIZE = 32;

//素材グラフィックパス
inline constexpr const TCHAR* GRAPH_MATERIAL = _T( "Assets/Items.png" );
//総分割数
inline constexpr int GRAPH_MATERIAL_NUM_ALL = 4;
//横分割数
inline constexpr int GRAPH_MATERIAL_NUM_X = 2;
//縦分割数
inline constexpr int GRAPH_MATERIAL_NUM_Y = 2;
//ピクセルサイズ
inline constexpr int GRAPH_MATERIAL_SIZE = 24;

//タイトルBGMパス
inline constexpr const TCHAR* SOUND_BGM_TITLE = _T( "Assets/TitleBGM.mp3" );
//ステージBGMパス
inline constexpr const TCHAR* SOUND_BGM_STAGE = _T( "Assets/StageBGM.mp3" );
//リザルトBGMパス
inline constexpr const TCHAR* SOUND_BGM_RESULT = _T( "Assets/ResultBGM.mp3" );

//決定SEパス
inline constexpr const TCHAR* SOUND_SE_CONFIRM = _T( "Assets/Confirm.mp3" );
//獲得SEパス
inline constexpr const TCHAR* SOUND_SE_GET = _T( "Assets/Heal.mp3" );
//成功SEパス
inline constexpr const TCHAR* SOUND_SE_CLEAR = _T( "Assets/StageClear.mp3" );
//失敗SEパス
inline constexpr const TCHAR* SOUND_SE_OVER = _T( "Assets/GameOver.mp3" );

//デモ映像パス
inline constexpr const TCHAR* MOVIE_DEMO = _T( "Assets/DemoMovie.mp4" );

//マップ横幅
inline constexpr int MAP_WIDTH = 21;
//マップ縦幅
inline constexpr int MAP_HEIGHT = 15;
//マップワールド横幅
inline constexpr int MAP_WORLD_WIDTH = MAP_WIDTH * GRAPH_MAP_WORLD_SIZE;
//マップワールド縦幅
inline constexpr int MAP_WORLD_HEIGHT = MAP_HEIGHT * GRAPH_MAP_WORLD_SIZE;
//マップスタート横位置
inline constexpr int MAP_START_INDEX_WIDTH = 1;
//マップスタート縦位置
inline constexpr int MAP_START_INDEX_HEIGHT = 1;
//マップゴール横位置
inline constexpr int MAP_GOAL_INDEX_WIDTH = MAP_WIDTH - 2;
//マップゴール縦位置
inline constexpr int MAP_GOAL_INDEX_HEIGHT = MAP_HEIGHT - 2;
//マップ探索思考回数
inline constexpr int MAP_DIG_COUNT = MAP_WIDTH * MAP_HEIGHT;

//カメラ最低限界
inline constexpr Vector2 CAMERA_MIN = { 0,0 };
//カメラ最大限界
inline constexpr Vector2 CAMERA_MAX = { 0,0 };//{ MAP_WIDTH * GRAPH_MAP_WORLD_SIZE - WIDTH, MAP_HEIGHT * GRAPH_MAP_WORLD_SIZE - HEIGHT };

//プレイヤー当たり判定直径
inline constexpr int PLAYER_SIZE = GRAPH_PLAYER_SIZE / 4;
//プレイヤー当たり判定半径
inline constexpr int PLAYER_RADIUS = PLAYER_SIZE / 2;
//プレイヤー秒速
inline constexpr int PLAYER_MOVE_SPD = 150;
//アニメーション時間
inline constexpr double PLAYER_ANIM_TIME = 0.33;

//素材当たり判定直径
inline constexpr int MATERIAL_DIAMETER = 32;
//素材当たり判定半径
inline constexpr int MATERIAL_RADIUS = MATERIAL_DIAMETER / 2;

//ステージクリア数
inline constexpr int STAGE_CLEAR_NUM = 3;

//矢印画像インデックス
inline constexpr int ARROW_INDEX = 191;

//ゴール画像インデックス
inline constexpr int GOAL_INDEX = 249;
//アニメーション時間
inline constexpr double GOAL_ANIM_TIME = 0.33;

//プレイヤー成功インデックス
inline constexpr int PLAYER_SUCCESS_IDEX = 9;
//プレイヤー失敗インデックス
inline constexpr int PLAYER_FAILURE_IDEX = 42;

//リザルトアニメーション時間
inline constexpr double RESULT_ANIM_TIME = 0.5;

//シーン強制遷移
inline constexpr int SCENE_AUTO_CHAGE_TIME = 99;


}