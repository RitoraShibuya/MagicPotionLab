#pragma once
#include "Struct.h"

class MaterialBase {
public:
	MaterialBase( Vector2 pos );
	virtual ~MaterialBase( ) = default;

	void Setup( );
	void Update( );
	virtual void Draw( Vector2 camera_pos ) = 0;

	virtual MaterialType GetMaterialType( )const = 0;
	Vector2 GetPos( );
	bool GetDestroyRequested( );
	void OnHitPlayer( );
protected:
	Vector2 m_pos = { 0.0,0.0 };
private:
	virtual void OnSetup( ) = 0;
	virtual void OnUpdate( ) = 0;
	void RequestDestroy( );

	bool m_destroy_requested = false;
};

