#pragma once
#include "Struct.h"
#include "Enum.h"
#include "Parameters.h"

class TileBase {
public:
	TileBase( Vector2 new_pos );
	virtual ~TileBase( ) = default;

	void Setup( );
	void Update( );
	virtual void Draw( Vector2 camera_pos ) = 0;

	virtual TileType GetType( ) const = 0;
	Vector2 GetPos( );
	Vector2 GetCenter( );
	Vector2 GetSize( );
protected:
	Vector2 m_pos = { 0.0,0.0 };
	Vector2 m_wall_size = { Parameters::GRAPH_MAP_WORLD_SIZE,Parameters::GRAPH_MAP_WORLD_SIZE };
	Vector2 m_wall_radius = { Parameters::GRAPH_MAP_WORLD_RADIUS,Parameters::GRAPH_MAP_WORLD_RADIUS };
private:
	virtual void OnSetup( ) = 0;
	virtual void OnUpdate( ) = 0;
};

