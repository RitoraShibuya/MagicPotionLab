#include "Input.h"


char m_current_key[ 256 ] = { 0 };
char m_old_key[ 256 ] = { 0 };

void Input::Update( ) {
	for ( int i = 0; i < 256; i++ ) {
		m_old_key[ i ] = m_current_key[ i ];
	}
	GetHitKeyStateAll( m_current_key );
}

bool Input::IsPress( int key_code ) {
	return m_current_key[ key_code ] == 1;
}

bool Input::IsTrigger( int key_code ) {
	return m_current_key[ key_code ] == 1 && m_old_key[ key_code ] == 0;
}