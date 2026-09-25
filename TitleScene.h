#pragma once
#include "SceneBase.h"
#include "Scene.h"
#include "Enum.h"

class TitleScene : public Scene<SceneType::Title> {
public:
	TitleScene( );
	~TitleScene( );

	void OnSetup( ) override;
	void OnUpdate( ) override;

private:
	
};

