#include "Common.h"
#include "SceneManager.h"

// WinMain関数（Windowsアプリのエントリーポイント）
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {

	ChangeWindowMode( FALSE ); // ウィンドウモードで起動（FALSEだとフルスクリーン）
	SetGraphMode( Parameters::WIDTH, Parameters::HEIGHT, 32 );
	SetWindowSize( Parameters::WIDTH, Parameters::HEIGHT );
	SetFullScreenResolutionMode( DX_FSRESOLUTIONMODE_DESKTOP );
	SetFullScreenScalingMode( DX_FSSCALINGMODE_NEAREST );

	// 【展示向けセーフティ】ウィンドウの「閉じる(X)」ボタンを無効化
	SetWindowUserCloseEnableFlag( FALSE );

	// DXLibの初期化（失敗したら即終了）
	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}

	// 描画先を「裏画面」に設定（アニメーションのちらつきを防止する必須設定）
	SetDrawScreen( DX_SCREEN_BACK );

	Resource::GetInstance( ).LoadResource( );
	std::unique_ptr<SceneManager> scene_manager = std::make_unique<SceneManager>( );
	scene_manager->Setup( );
	UIManager::GetInstance().Setup( );


	// ※展示本番では CheckHitKey(KEY_INPUT_ESCAPE) の条件を外し、別の終了方法を用意するのがおすすめ。
	while ( ProcessMessage( ) == 0 && ClearDrawScreen( ) == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) {

		Input::Update( );
		Time::GetInstance( ).Update();
		UIManager::GetInstance( ).Update( );

		scene_manager->Update( );

		UIManager::GetInstance().Draw( );

		ScreenFlip( );
	}

	Resource::GetInstance( ).Finalize( );

	DxLib_End( );

	return 0;
}