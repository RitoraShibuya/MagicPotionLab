#pragma once
#include "Dxlib.h"
#include "Struct.h"
#include <vector>

class Time {
private:
	Time( );
	LONGLONG m_prev_time = GetNowHiPerformanceCount( );
	double m_delta_time = 0.0;
	std::vector<DelayTask> m_tasks;
public:
	static Time& GetInstance( );
	void Update( );
	double GetDeltaTime( );
	void SetTimeout( double delay_sec, std::function<void( )> func );
};

