#pragma once
#include "SceneBase.h"
#include "Scene.h"
#include "Enum.h"
#include "Struct.h"
#include "Parameters.h"
#include <vector>
#include <memory>
#include <unordered_set>
#include <utility>
#include "TimerUI.h"

class PlayerCharacter;
class MaterialBase;
class Camera;
class MapGenerator;
class TileBase;

class MainStageScene : public Scene<SceneType::Main> {
public:
	MainStageScene( int floor_num );
	~MainStageScene( );

private:
	void OnSetup( ) override;
	void OnUpdate( ) override;
	void MakeTargetMaterilas( );
	void CheckHitPlayerToTile( );
	void CheckHitPlayerToMaterials( );
	void CheckDestroyMaterials( );
	void RemakeMap( );
	void OnGameClear( );
	void OnGameOver( );

	std::unique_ptr<PlayerCharacter> m_player;
	std::unique_ptr<Camera> m_camera;
	std::unique_ptr<MapGenerator> m_map_generator;
	std::vector<std::unique_ptr<TileBase>> m_tiles;
	std::vector<std::unique_ptr<MaterialBase>> m_materials;
	std::vector<MaterialType> m_target_materials;
	std::vector<MaterialType> m_material_types;
	std::unordered_set<TileBase*> m_prev_overlap_tiles;

	TimerUI* m_timer_ui = nullptr;

	int m_current_floor_num = 0;
};

