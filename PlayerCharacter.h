#pragma once
#include "Struct.h"
#include "Enum.h"
#include "Parameters.h"
#include <vector>

class MaterialBase;

class PlayerCharacter {
public:
	PlayerCharacter( );
	~PlayerCharacter( );

	void Setup( );
	void Update( );
	void Draw( Vector2 camera_pos );

	Vector2 GetPos( );
	Vector2 GetOldPos( );
	Vector2 GetRadius( );
	void SetPos( Vector2 new_pos );
	void AddPos( Vector2 add_pos );
	void SetDirection( PlayerDirection new_direction );

	void OnHitWall( );
	void OnHitMaterial( MaterialBase* new_material );
	void OnHitCircle( bool is_clear );
	std::vector<MaterialType> RemoveMaterial( );
private:
	void Move( );
	void AddMaterialCount( MaterialBase* new_material );
	void UpdateAnim( );
	int GetAnimIndex( );

	Vector2 m_pos { 0.0,0.0 };
	Vector2 m_old_pos = m_pos;
	Vector2 m_player_radius { Parameters::PLAYER_RADIUS,Parameters::PLAYER_RADIUS };
	std::vector<MaterialType> m_material_types;
	PlayerDirection m_current_direction = PlayerDirection::Down;
	double m_current_anim_time = 0.0;
	int m_current_anim_index = 0;
	int m_result_start_index = 0;
	int m_result_anim_index = 0;
	bool m_result = false;
};

