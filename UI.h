#pragma once
#include "UIBase.h"
#include "Enum.h"

template <UIType Type>

class UI : public UIBase {
public:
	UIType GetUIType( ) const override {
		return Type;
	}
};

