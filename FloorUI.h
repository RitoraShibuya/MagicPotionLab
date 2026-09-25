#pragma once
#include "UI.h"
#include "UIBase.h"
#include "Enum.h"

class FloorUI :public UI<UIType::Floor> {
public:
	FloorUI(int current_floor);
	~FloorUI( );

	void Draw( ) override;

private:
	void OnSetup( )override;
	void OnUpdate( )override;

	int m_current_floor = 0;
};

