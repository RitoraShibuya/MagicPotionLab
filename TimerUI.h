#pragma once
#include "UI.h"
#include "UIBase.h"
#include "Enum.h"

class TimerUI : public UI<UIType::Timer> {
public:
	TimerUI( );
	~TimerUI( );

	void Draw( )override;

	void SetTime( double current_time );
private:
	void OnSetup( )override;
	void OnUpdate( )override;

	double m_current_time = 0.0;
};

