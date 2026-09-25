#pragma once
#include "TileBase.h"
#include "Tile.h"
#include "Struct.h"
#include "Enum.h"

class FirldTile : public Tile<TileType::Firld> {
public:
	FirldTile(Vector2 new_pos );
	~FirldTile( );

	void Draw(Vector2 camera_pos ) override;
private:
	void OnSetup( ) override;
	void OnUpdate( ) override;
};

