#pragma once
#include "Struct.h"

class UIBase {
public:
	virtual ~UIBase( ) = default;

	void Setup( );
	void Update( int mx, int my );
	virtual void Draw( ) = 0;

	virtual UIType GetUIType( ) const = 0;
	Vector2 GetCenterSize( );
private:
	virtual void OnSetup( ) = 0;
	virtual void OnUpdate( ) = 0;

protected:
	virtual void MouseOverlaping( ) {};
	void Draw9SliceWindow( int min_x, int min_y, int max_x, int max_y );
	void Draw9SliceTargetWindow( int min_x, int min_y, int max_x, int max_y );

	Vector2 m_pos;
	Vector2 m_size;
	int m_min_x = 0;
	int m_max_x = 0;
	int m_min_y = 0;
	int m_max_y = 0;
	bool m_is_overlaping = false;
};

