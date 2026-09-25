#pragma once
#include "SceneBase.h"
#include "Enum.h"

template <SceneType Type>

class Scene : public SceneBase {
public:
	SceneType GetSceneType( ) const override {
		return Type;
	}
};