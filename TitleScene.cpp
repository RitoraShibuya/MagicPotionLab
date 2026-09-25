#include "TitleScene.h"
#include "Common.h"
#include "GuideUI.h"

TitleScene::TitleScene( ) {

}

TitleScene::~TitleScene( ) {

}

void TitleScene::OnSetup( ) {
	//BGM再生
	SoundManager::GetInstance( ).PlayAudio( Resource::GetInstance( ).GetTitleBGM( ), SoundType::BGM );
	//案内UI
	UIManager::GetInstance( ).CreateUI( new GuideUI( ) );

	PlayMovieToGraph( Resource::GetInstance( ).GetDemoMovie( ), DX_PLAYTYPE_LOOP );
}

void TitleScene::OnUpdate( ) {
	DrawRotaGraph( Parameters::CENTER_WIDTH,
				   Parameters::CENTER_HEIGHT,
				   0.55,
				   0.0,
				   Resource::GetInstance( ).GetDemoMovie( ),
				   TRUE );
	DrawRotaGraph( Parameters::CENTER_WIDTH,
				   Parameters::CENTER_HEIGHT - 100,
				   0.6,
				   0.0,
				   Resource::GetInstance( ).GetTitleGraph( ),
				   TRUE );

	if ( Input::IsTrigger( KEY_INPUT_SPACE ) ) {
		RequestSceneChange( false );
		SeekMovieToGraph( Resource::GetInstance( ).GetDemoMovie( ), 0 );
		SoundManager::GetInstance( ).PlayAudio( Resource::GetInstance( ).GetConfirmSE( ), SoundType::SE );
	}
}