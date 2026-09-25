#pragma once
#include "MaterialBase.h"
#include "Material.h"
#include "Struct.h"
#include "Enum.h"

class AppleMaterial : public Material<MaterialType::Fire> {
public:
	AppleMaterial( Vector2 new_pos );
	~AppleMaterial( );

	void OnSetup( ) override;
	void OnUpdate( ) override;
	void Draw( Vector2 camera_pos ) override;
};

