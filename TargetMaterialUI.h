#pragma once
#include "UI.h"
#include "UIBase.h"
#include "Enum.h"

class TargetMaterialUI : public UI<UIType::Target> {
public:
	TargetMaterialUI( MaterialType material1, MaterialType material2, MaterialType material3 );
	~TargetMaterialUI( );

	void Draw( )override;
private:
	void OnSetup( )override;
	void OnUpdate( )override;
	void GetTypeToIndex( MaterialType type, int& index );

	MaterialType m_material_types[ 3 ];
	int m_material_indexs[ 3 ] = { 0,0,0 };
	int m_material_count = 0;
	int m_total_count = 0;
	int m_step = 0;
	int m_start_step = 0;
};

