#include "Time.h"
#include "Dxlib.h"
#include "Struct.h"
#include <algorithm>
#include <functional>

Time::Time( ) {

}

Time& Time::GetInstance( ) {
	static Time instance;
	return instance;
}

void Time::Update( ) {
	LONGLONG current_time = GetNowHiPerformanceCount( );
	m_delta_time = static_cast< double >( current_time - m_prev_time ) / 1000000.0;
	m_delta_time = std::clamp( m_delta_time, 0.0, 0.1 );
	m_prev_time = current_time;

	std::vector<DelayTask>::iterator it = m_tasks.begin( );
	while ( it != m_tasks.end( ) ) {
		DelayTask& task = *it;
		task.time_left -= m_delta_time;
		if ( task.time_left <= 0.0 ) {
			task.action( );
			it = m_tasks.erase( it );
		} else {
			it++;
		}
	}
}

double Time::GetDeltaTime( ) {
	return m_delta_time;
}

void Time::SetTimeout( double delay_sec, std::function<void( )> func ) {
	m_tasks.push_back( { delay_sec,func } );
}