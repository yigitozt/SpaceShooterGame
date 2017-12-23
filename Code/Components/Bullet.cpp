#include "StdAfx.h"
#include "Bullet.h"

// Called on entity creation time
void CBullet::Initialize()
{
	GetEntity()->LoadGeometry(0, "objects/bullet/bullet.cgf");

	SEntityPhysicalizeParams sPhysicsParams;
	sPhysicsParams.type = PE_RIGID;
	sPhysicsParams.mass = 0.f;
	
	GetEntity()->Physicalize(sPhysicsParams);

	GetEntity()->PrePhysicsActivate(true);
}

void CBullet::ProcessEvent(SEntityEvent& event)
{
	switch (event.event)
	{
	case ENTITY_EVENT_UPDATE:
	{
		FrameUpdate();
	}
	case ENTITY_EVENT_COLLISION:
	{
		OnCollision((EventPhysCollision*)event.nParam[0]);
	}
	}
}

void CBullet::FrameUpdate()
{
	GetEntity()->SetPos(Vec3(GetEntity()->GetPos().x, GetEntity()->GetPos().y + 0.1f, GetEntity()->GetPos().z));

	++m_DestroyTimer;

	if (m_DestroyTimer >= 500.f)
	{
		gEnv->pEntitySystem->RemoveEntity(GetEntity()->GetId(), true);
	}
}

void CBullet::OnCollision(EventPhysCollision *pCollision)
{
	//gEnv->pEntitySystem->RemoveEntity(GetEntity()->GetId()); Todo: uncomment after entity spawn control
}