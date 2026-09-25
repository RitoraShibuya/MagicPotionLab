#pragma once
#include "TileBase.h"
#include "Struct.h"
#include "Enum.h"

template <TileType Type >

class Tile : public TileBase {
public:
	Tile( Vector2 new_pos ) :TileBase( new_pos ) {};
	virtual ~Tile( ) = default;

	TileType GetType( ) const override {
		return Type;
	}
};