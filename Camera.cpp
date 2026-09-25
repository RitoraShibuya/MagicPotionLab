#include "Camera.h"
#include "Common.h"
#include "PlayerCharacter.h"

Camera::Camera( ) {

}

Camera::~Camera( ) {

}

void Camera::Setup( ) {
	int map_center_index_x = ( Parameters::MAP_WIDTH - 1 ) / 2;
	int map_center_index_y = ( Parameters::MAP_HEIGHT - 1 ) / 2;
	m_pos = { Parameters::MAP_WORLD_WIDTH / 2 - Parameters::CENTER_WIDTH,
		-(Parameters::HEIGHT - Parameters::MAP_WORLD_HEIGHT) };
}

void Camera::Update( Vector2 player_pos ) {
	/*Vector2 target_pos = player_pos - Parameters::WINDOW_CENTER;
	SetState( DetermineCameraState( target_pos ) );
	UpdatePos( target_pos );*/
}

Vector2 Camera::GetPos( ) {
	return m_pos;
}

void Camera::SetState( CameraState new_state ) {
	m_current_state = new_state;
}

CameraState Camera::DetermineCameraState( Vector2 target_pos ) {
	CameraState return_state = CameraState::Movable;
	bool lock_x = false;
	bool lock_y = false;

	if ( target_pos.x > Parameters::CAMERA_MAX.x ||
		 target_pos.x < Parameters::CAMERA_MIN.x ) {
		lock_x = true;
		return_state = CameraState::LockX;
	}
	if ( target_pos.y > Parameters::CAMERA_MAX.y ||
		 target_pos.y < Parameters::CAMERA_MIN.y ) {
		lock_y = true;
		return_state = CameraState::LockY;
	}
	if ( lock_x && lock_y ) {
		return_state = CameraState::Lock;
	}
	return return_state;
}

void Camera::UpdatePos( Vector2 target_pos ) {
	switch ( m_current_state ) {
	default:
		break;
	case CameraState::Movable:
		//Vector2 dist = target_pos - m_pos;
		//m_pos = m_pos + ( dist * 0.01 );
		m_pos = target_pos;
		break;
	case CameraState::Lock:
		break;
	case CameraState::LockX:
		m_pos.y = target_pos.y;
		break;
	case CameraState::LockY:
		m_pos.x = target_pos.x;
		break;
	}
}