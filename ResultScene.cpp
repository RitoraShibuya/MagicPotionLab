#include "ResultScene.h"
#include "Common.h"
#include "ScoreTimeUI.h"
#include "TotalScoreUI.h"
#include "GuideUI.h"

ResultScene::ResultScene( std::vector<double>times ) {
	m_times = times;
}

ResultScene::~ResultScene( ) {

}

void ResultScene::OnSetup( ) {
	UIManager::GetInstance( ).CreateUI( new ScoreTimeUI( m_times ) );
	double total_time = 0.0;
	for ( double time : m_times ) {
		total_time += time;
	}
	UIManager::GetInstance( ).CreateUI( new TotalScoreUI( total_time ) );
	UIManager::GetInstance( ).CreateUI( new GuideUI(  ) );

	//BGM再生
	SoundManager::GetInstance( ).PlayAudio( Resource::GetInstance( ).GetResultBGM( ), SoundType::BGM );
}

void ResultScene::OnUpdate( ) {
	DrawExtendGraph( 0, 0,
					 Parameters::WIDTH, Parameters::HEIGHT,
					 Resource::GetInstance( ).GetResultBackGraph( ), FALSE );

	UpdateAnimTimer( );
	//DrawPot( );
	DrawMaterials( );

	if ( Input::IsTrigger( KEY_INPUT_SPACE ) ) {
		RequestSceneChange( false );
		SoundManager::GetInstance( ).PlayAudio( Resource::GetInstance( ).GetConfirmSE( ), SoundType::SE );
	}
}

void ResultScene::UpdateAnimTimer( ) {
	m_anim_time += Time::GetInstance( ).GetDeltaTime( );
	if ( m_anim_time > Parameters::RESULT_ANIM_TIME ) {
		m_anim_time -= Parameters::RESULT_ANIM_TIME;
		m_ang *= -1;
	}
}

void ResultScene::DrawPot( ) {
	int x = Parameters::CENTER_WIDTH;
	int y = Parameters::CENTER_HEIGHT;
	int scale = 5;
	DrawRotaGraph( x,
				   y - Parameters::GRAPH_MAP_SIZE * scale / 2,
				   5.0,
				   0.0,
				   Resource::GetInstance( ).GetMapGraph( ).at( 991 ),
				   TRUE );
	DrawRotaGraph( x,
				   y + Parameters::GRAPH_MAP_SIZE * scale / 2,
				   5.0,
				   0.0,
				   Resource::GetInstance( ).GetMapGraph( ).at( 999 ),
				   TRUE );

	
}

void ResultScene::DrawMaterials( ) {

	DrawRotaGraph( Parameters::CENTER_WIDTH - 200,
				   Parameters::CENTER_HEIGHT,
				   3.0,
				   m_ang,
				   Resource::GetInstance( ).GetMaterialGraph( ).at( 1 ),
				   TRUE );
	DrawRotaGraph( Parameters::CENTER_WIDTH,
				   Parameters::CENTER_HEIGHT - 150,
				   3.0,
				   m_ang,
				   Resource::GetInstance( ).GetMaterialGraph( ).at( 2 ),
				   TRUE );
	DrawRotaGraph( Parameters::CENTER_WIDTH + 200,
				   Parameters::CENTER_HEIGHT,
				   3.0,
				   m_ang,
				   Resource::GetInstance( ).GetMaterialGraph( ).at( 3 ),
				   TRUE );

	DrawRotaGraph( Parameters::CENTER_WIDTH,
				   Parameters::CENTER_HEIGHT + 150,
				   5.0,
				   m_ang,
				   Resource::GetInstance( ).GetMaterialGraph( ).at( 0 ),
				   TRUE );
}