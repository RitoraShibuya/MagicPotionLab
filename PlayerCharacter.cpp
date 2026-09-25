#include "PlayerCharacter.h"
#include "Common.h"
#include "MaterialBase.h"

PlayerCharacter::PlayerCharacter( ) {

}

PlayerCharacter::~PlayerCharacter( ) {

}

void PlayerCharacter::Setup( ) {

}

void PlayerCharacter::Update( ) {
	Move( );
	UpdateAnim( );
}

void PlayerCharacter::Draw( Vector2 camera_pos ) {
	//影描画
	DrawRotaGraph( ( int )( m_pos.x - camera_pos.x ),
				   ( int )( m_pos.y - camera_pos.y  + 2),
				   1.0,
				   0.0,
				   Resource::GetInstance( ).GetShadowGraph( ).at( GetAnimIndex( ) ),
				   TRUE );
	//プレイヤー描画
	DrawRotaGraph( ( int )( m_pos.x - camera_pos.x ),
				   ( int )( m_pos.y - camera_pos.y ),
				   1.0,
				   0.0,
				   Resource::GetInstance( ).GetPlayerGraph( ).at( GetAnimIndex( ) ),
				   TRUE );
	//成功・失敗アイコン表示
	if ( m_result ) {
		DrawRotaGraph( ( int )( m_pos.x - camera_pos.x ),
					   ( int )( m_pos.y - camera_pos.y - Parameters::GRAPH_PLAYER_SIZE),
					   1.0,
					   0.0,
					   Resource::GetInstance( ).GetIconGraph( ).at( m_result_start_index + m_result_anim_index ),
					   TRUE );
	}
}

Vector2 PlayerCharacter::GetPos( ) {
	return m_pos;
}

Vector2 PlayerCharacter::GetOldPos( ) {
	return m_old_pos;
}

Vector2 PlayerCharacter::GetRadius( ) {
	return m_player_radius;
}

void PlayerCharacter::SetPos( Vector2 new_pos ) {
	m_pos = new_pos;
}

void PlayerCharacter::AddPos( Vector2 add_pos ) {
	m_pos = m_pos + add_pos;
}

void PlayerCharacter::SetDirection( PlayerDirection new_direction ) {
	m_current_direction = new_direction;
}

std::vector<MaterialType> PlayerCharacter::RemoveMaterial( ) {
	return std::move( m_material_types );
}

void PlayerCharacter::Move( ) {

	m_old_pos = m_pos;

	if ( m_result ) {
		return;
	}

	if ( Input::IsPress( KEY_INPUT_UP ) ) {
		m_pos.y -= Parameters::PLAYER_MOVE_SPD * Time::GetInstance( ).GetDeltaTime( );
		SetDirection( PlayerDirection::Up );
	}
	if ( Input::IsPress( KEY_INPUT_DOWN ) ) {
		m_pos.y += Parameters::PLAYER_MOVE_SPD * Time::GetInstance( ).GetDeltaTime( );
		SetDirection( PlayerDirection::Down );
	}
	if ( Input::IsPress( KEY_INPUT_RIGHT ) ) {
		m_pos.x += Parameters::PLAYER_MOVE_SPD * Time::GetInstance( ).GetDeltaTime( );
		SetDirection( PlayerDirection::Right );
	}
	if ( Input::IsPress( KEY_INPUT_LEFT ) ) {
		m_pos.x -= Parameters::PLAYER_MOVE_SPD * Time::GetInstance( ).GetDeltaTime( );
		SetDirection( PlayerDirection::Left );
	}
}

void PlayerCharacter::OnHitWall( ) {
	SetPos( GetOldPos( ) );
}

void PlayerCharacter::OnHitMaterial( MaterialBase* new_material ) {
	AddMaterialCount( new_material );
	SoundManager::GetInstance( ).PlayAudio( Resource::GetInstance( ).GetGetSE( ), SoundType::SE );
}

void PlayerCharacter::OnHitCircle( bool is_clear ) {
	m_result = true;
	if ( is_clear ) {
		SoundManager::GetInstance( ).PlayAudio( Resource::GetInstance( ).GetClearSE( ), SoundType::SE );
		m_result_start_index = Parameters::PLAYER_SUCCESS_IDEX;
	} else {
		SoundManager::GetInstance( ).PlayAudio( Resource::GetInstance( ).GetOverSE( ), SoundType::SE );
		m_result_start_index = Parameters::PLAYER_FAILURE_IDEX;
	}
}

void PlayerCharacter::AddMaterialCount( MaterialBase* new_material ) {
	m_material_types.push_back( new_material->GetMaterialType( ) );
}

void PlayerCharacter::UpdateAnim( ) {
	m_current_anim_time += Time::GetInstance( ).GetDeltaTime( );
	if ( m_current_anim_time > Parameters::PLAYER_ANIM_TIME ) {
		m_current_anim_time -= Parameters::PLAYER_ANIM_TIME;

		m_current_anim_index = ( m_current_anim_index + 1 ) % Parameters::GRAPH_PLAYER_NUM_X;
		m_result_anim_index = ( m_result_anim_index + 1 ) % 3;
	}
}

int PlayerCharacter::GetAnimIndex( ) {
	int direction_index = 0;

	switch ( m_current_direction ) {
	default:
		break;
	case PlayerDirection::Up: direction_index = 3;
		break;
	case PlayerDirection::Down: direction_index = 0;
		break;
	case PlayerDirection::Right:direction_index = 2;
		break;
	case PlayerDirection::Left:direction_index = 1;
		break;
	}

	int return_index = Parameters::GRAPH_PLAYER_NUM_X * direction_index + m_current_anim_index;

	if ( return_index >= Parameters::GRAPH_PLAYER_NUM_ALL ||
		 return_index < 0 ) {
		return 0;
	} else {
		return return_index;
	}
}