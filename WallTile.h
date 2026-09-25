#pragma once
#include "TileBase.h"
#include "Tile.h"
#include "Struct.h"

class WallTile : public Tile<TileType::Wall> {
public:
	WallTile( Vector2 new_pos );
	~WallTile( );

	void Draw(Vector2 camera_pos) override;
private:
	void OnSetup( ) override;
	void OnUpdate( ) override;
};

