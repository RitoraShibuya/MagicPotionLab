#pragma once
#include "MaterialBase.h"
#include "Material.h"
#include "Struct.h"
#include "Enum.h"

class GrassMaterial : public Material<MaterialType::Grass> {
public:
	GrassMaterial( Vector2 new_pos );
	~GrassMaterial( );

	void OnSetup( ) override;
	void OnUpdate( ) override;
	void Draw( Vector2 camera_pos ) override;
};

