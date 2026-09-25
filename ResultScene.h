#pragma once
#include "SceneBase.h"
#include "Scene.h"
#include "Enum.h"
#include <vector>

class ResultScene : public Scene<SceneType::Result> {
public:
	ResultScene( std::vector<double>times );
	~ResultScene( );

	void OnSetup( ) override;
	void OnUpdate( ) override;

	void UpdateAnimTimer( );
	void DrawPot( );
	void DrawMaterials( );
private:
	std::vector<double>m_times;
	double m_ang = 5.0 * 3.14 / 180;
	double m_anim_time = 0.0;
};

