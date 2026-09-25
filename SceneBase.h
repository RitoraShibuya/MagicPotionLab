#pragma once
#include "Enum.h"
#include "Struct.h"

class SceneBase {
public:
	virtual ~SceneBase( ) = default;

	void Setup( );
	void Update( );

	SceneChangeEvent GetSceneChangeEvent( );
	virtual SceneType GetSceneType( ) const = 0;
	double GetTime( );
protected:
	void RequestSceneChange( bool is_clear );
private:
	virtual void OnSetup( ) = 0;
	virtual void OnUpdate( ) = 0;

	SceneChangeEvent m_change_event {};

	double m_current_time = 0;
};

