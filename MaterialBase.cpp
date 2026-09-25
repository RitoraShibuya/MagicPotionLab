#include "MaterialBase.h"
#include "Common.h"

MaterialBase::MaterialBase(Vector2 pos ) {
	m_pos = pos;
}

void MaterialBase::Setup( ) {
	OnSetup( );
}

void MaterialBase::Update( ) {
	OnUpdate( );
}

Vector2 MaterialBase::GetPos( ) {
	return m_pos;
}

bool MaterialBase::GetDestroyRequested( ) {
	return m_destroy_requested;
}

void MaterialBase::OnHitPlayer( ) {
	RequestDestroy( );
}

void MaterialBase::RequestDestroy( ) {
	m_destroy_requested = true;
}