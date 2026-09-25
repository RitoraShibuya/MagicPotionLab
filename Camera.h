#pragma once
#include "Enum.h"
#include "Struct.h"
#include "Parameters.h"

class Camera {
public:
	Camera( );
	~Camera( );

	//開始時
	void Setup( );
	//更新
	void Update( Vector2 player_pos );
	//座標取得
	Vector2 GetPos( );
	//ステート取得
	void SetState( CameraState new_state );
private:
	//座標を基にしたステート分岐
	CameraState DetermineCameraState( Vector2 target_pos );
	//カメラ座標の更新
	void UpdatePos( Vector2 target_pos );
	//カメラ座標
	Vector2 m_pos { (Parameters::MAP_WORLD_WIDTH / 2)- Parameters::CENTER_WIDTH, 0 };
	//カメラ状態
	CameraState m_current_state = CameraState::LockX;
};

