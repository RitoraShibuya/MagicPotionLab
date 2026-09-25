#pragma once
#include "Dxlib.h"

class Input {

public:
	static void Update( );
	static bool IsPress(int key_code);
	static bool IsTrigger( int key_code);
private:
	char m_current_keys[ 256 ];
	char m_old_keys[ 256 ];

};

