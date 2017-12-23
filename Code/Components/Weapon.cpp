#include "StdAfx.h"
#include "Weapon.h"

// Called on entity initialization
void CWeapon::Initialize()
{
	GetEntity()->PrePhysicsActivate(true);
}

// Called for every event
void CWeapon::ProcessEvent(SEntityEvent& event)
{
	switch (event.event)
	{
	case ENTITY_EVENT_UPDATE:
	{
		FrameUpdate();
	}
	}
}

// Fires the weapon
void CWeapon::Fire()
{
	if (m_fLastFireTime >= 500.f)
	{
		SEntitySpawnParams sBulletSpawnParams;
		sBulletSpawnParams.pClass = gEnv->pEntitySystem->GetClassRegistry()->GetDefaultClass();
		sBulletSpawnParams.vPosition = GetEntity()->GetPos();
		sBulletSpawnParams.qRotation = GetEntity()->GetRotation();

		IEntity* pSpawnedBullet = gEnv->pEntitySystem->SpawnEntity(sBulletSpawnParams);
		pSpawnedBullet->GetOrCreateComponentClass<CBullet>();

		m_fLastFireTime = 0;
	}
}

// Called on every frame
void CWeapon::FrameUpdate()
{
	if(m_fLastFireTime < 500.f)
		++m_fLastFireTime;
}