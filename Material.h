#pragma once
#include "MaterialBase.h"
#include "Struct.h"
#include "Enum.h"

template <MaterialType Type>

class Material : public MaterialBase {
public:
	Material( Vector2 pos ) : MaterialBase( pos ) {};
	virtual ~Material( ) = default;

	MaterialType GetMaterialType( ) const override {
		return Type;
	}
};