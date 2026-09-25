#pragma once
#include "Tile.h"
#include "Enum.h"
#include "Struct.h"
#include <vector>

class GetItemTile : public Tile<TileType::Item> {
public:
	GetItemTile(Vector2 pos );
	~GetItemTile( );

	void Draw( Vector2 camera_pos ) override;
private:
	void OnSetup( ) override;
	void OnUpdate( ) override;
	
	int m_anim_index = 0;
	double m_anim_time = 0.0;
};

