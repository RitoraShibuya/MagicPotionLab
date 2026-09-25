#pragma once
#include "Common.h"
#include "SceneBase.h"

class SceneManager {
public:
	SceneManager( );
	~SceneManager( );

	void Setup( );
	void Update( );
private:
	void CheckSceneChangeEvent( );
	bool CheckClear( bool is_clear );

	std::unique_ptr<SceneBase> m_current_scene;
	SceneType m_current_scene_type;
	std::vector<double>m_times;

	int m_current_floor_num = 0;
	double m_last_time = 0;
	bool m_is_changing = false;
};

