#pragma once
#include "MaterialBase.h"
#include "Material.h"
#include "Struct.h"
#include "Enum.h"

class DiaMaterial : public Material<MaterialType::Water> {
public:
	DiaMaterial( Vector2 new_pos );
	~DiaMaterial( );

	void OnSetup( ) override;
	void OnUpdate( ) override;
	void Draw( Vector2 camera_pos ) override;
};

