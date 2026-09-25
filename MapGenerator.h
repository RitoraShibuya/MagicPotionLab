#pragma once
#include "Common.h"

class TileBase;
class MaterialBase;
class PlayerCharacter;

class MapGenerator {
public:
	MapGenerator( );
	~MapGenerator( );

	void Setup( );
	void Update( );
	void Draw( Vector2 camera_pos );
	std::vector<std::unique_ptr<TileBase>> RemoveTiles( );
	std::vector<std::unique_ptr<MaterialBase>> RemoveMaterials( );
private:
	void GenerateRandMap( int( &map )[ Parameters::MAP_HEIGHT ][ Parameters::MAP_WIDTH ] );

	std::vector<std::unique_ptr<TileBase>> m_tiles;
	std::vector<std::unique_ptr<MaterialBase>> m_materials;
};

