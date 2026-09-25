#include "TargetMaterialUI.h"
#include "Common.h"

TargetMaterialUI::TargetMaterialUI( MaterialType material1, MaterialType material2, MaterialType material3 ) {
	m_size = Vector2( 450, 75 );
	m_pos = Vector2( Parameters::WINDOW_CENTER.x - m_size.x / 2, 0 );

	m_material_types[ 0 ] = material1;
	m_material_types[ 1 ] = material2;
	m_material_types[ 2 ] = material3;
}

TargetMaterialUI::~TargetMaterialUI( ) {

}

void TargetMaterialUI::OnSetup( ) {

	for ( int i = 0; i < 3; i++ ) {
		GetTypeToIndex( m_material_types[ i ], m_material_indexs[ i ] );
	}


	m_material_count = ( int )std::size( m_material_indexs );
	m_total_count = m_material_count * 2 - 1;
	m_step = ( int )m_size.x / m_total_count;
	m_start_step = m_step / 2;
}

void TargetMaterialUI::OnUpdate( ) {

}

void TargetMaterialUI::Draw( ) {
	Draw9SliceTargetWindow( m_min_x, m_min_y,
							m_max_x, m_max_y );

	int pos_y = ( int )(m_pos.y + ( m_size.y / 2 ));

	for ( int i = 0; i < m_total_count; i++ ) {
		int pos_x = ( int )m_pos.x + m_start_step + m_step * i;
		if ( i % 2 == 0 ) {
			int index = i / 2;
			DrawRotaGraph( ( int )( pos_x ),
						   ( int )( pos_y ),
						   2.0,
						   0.0,
						   Resource::GetInstance( ).GetMaterialGraph( ).at( m_material_indexs[ index ] ),
						   TRUE );
		} else {
			DrawRotaGraph( ( int )( pos_x ),
						   ( int )( pos_y ),
						   2.0,
						   0.0,
						   Resource::GetInstance( ).GetIconGraph( ).at( Parameters::ARROW_INDEX ),
						   TRUE );
		}
	}
}

void TargetMaterialUI::GetTypeToIndex( MaterialType type, int& index ) {
	switch ( type ) {
	default:
		index = 0;
		break;
	case MaterialType::Fire:
		index = 2;
		break;
	case MaterialType::Water:
		index = 1;
		break;
	case MaterialType::Grass:
		index = 3;
		break;
	case MaterialType::Dark:
		index = 0;
		break;
	}
}

