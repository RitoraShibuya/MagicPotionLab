#include "UIBase.h"
#include "Common.h"

void UIBase::Setup( ) {
	m_min_x = ( int )( m_pos.x );
	m_max_x = ( int )( m_pos.x + m_size.x );
	m_min_y = ( int )( m_pos.y );
	m_max_y = ( int )( m_pos.y + m_size.y );
	OnSetup( );
}

void UIBase::Update(int mx, int my ) {

	if ( mx > m_min_x && mx < m_max_x &&
		 my > m_min_y && my < m_max_y ) {
		m_is_overlaping = true;
		MouseOverlaping( );
	}
	OnUpdate( );
}

Vector2 UIBase::GetCenterSize( ) {
	return Vector2( m_size.x * 0.5, m_size.y * 0.5 );
}

void UIBase::Draw9SliceWindow( int min_x, int min_y, int max_x, int max_y ) {
	DrawExtendGraph( min_x, min_y,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 0 ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, min_y,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 1 ),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, min_y,
					 max_x, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 2 ),
					 TRUE
	);

	DrawExtendGraph( min_x, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 3 ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 4 ),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 max_x, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 5 ),
					 TRUE
	);

	DrawExtendGraph( min_x, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, max_y,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 6 ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, max_y,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 7 ),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 max_x, max_y,
					 Resource::GetInstance( ).GetWindowGraph( ).at( 8 ),
					 TRUE
	);
}

/*
void UIBase::Draw9SliceWindow( int min_x, int min_y, int max_x, int max_y ) {
	DrawExtendGraph( min_x, min_y,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, min_y,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX + 1 ),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, min_y,
					 max_x, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX + 2),
					 TRUE
	);

	DrawExtendGraph( min_x, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX + 8 ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX + 9),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 max_x, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX + 10),
					 TRUE
	);

	DrawExtendGraph( min_x, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, max_y,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX + 16 ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, max_y,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX + 17),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 max_x, max_y,
					 Resource::GetInstance( ).GetMapGraph( ).at( Parameters::GRAPH_WINDOW_INDEX + 18),
					 TRUE
	);
}
*/

void UIBase::Draw9SliceTargetWindow( int min_x, int min_y, int max_x, int max_y ) {
	DrawExtendGraph( min_x, min_y,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 0 ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, min_y,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 1 ),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, min_y,
					 max_x, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 2 ),
					 TRUE
	);

	DrawExtendGraph( min_x, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 3 ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 4 ),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, min_y + Parameters::GRAPH_WINDOW_SIZE,
					 max_x, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 5 ),
					 TRUE
	);

	DrawExtendGraph( min_x, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 min_x + Parameters::GRAPH_WINDOW_SIZE, max_y,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 6 ),
					 TRUE
	);

	DrawExtendGraph( min_x + Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 max_x - Parameters::GRAPH_WINDOW_SIZE, max_y,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 7 ),
					 TRUE
	);

	DrawExtendGraph( max_x - Parameters::GRAPH_WINDOW_SIZE, max_y - Parameters::GRAPH_WINDOW_SIZE,
					 max_x, max_y,
					 Resource::GetInstance( ).GetTargetWindowGraph( ).at( 8 ),
					 TRUE
	);
}
