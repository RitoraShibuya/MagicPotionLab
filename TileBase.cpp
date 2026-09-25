#include "TileBase.h"
#include "Common.h"

TileBase::TileBase( Vector2 new_pos ) {
	m_pos = new_pos;
}

void TileBase::Setup( ) {
	OnSetup( );
}

void TileBase::Update( ) {
	OnUpdate( );
}

Vector2 TileBase::GetPos( ) {
	return m_pos;
}

Vector2 TileBase::GetCenter( ) {
	return m_pos + m_wall_radius;
}

Vector2 TileBase::GetSize( ) {
	return m_wall_size;
}