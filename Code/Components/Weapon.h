#pragma once

#include "GamePlugin.h"
#include <CryEntitySystem/IEntityComponent.h>
#include <CrySchematyc/CoreAPI.h>

class CWeapon : public IEntityComponent
{
public:
	CWeapon() : m_fLastFireTime(500.f){};
	~CWeapon() {};

	// IEntityComponent
	virtual void Initialize() override;
	virtual uint64 GetEventMask() const override { return BIT64(ENTITY_EVENT_UPDATE); }
	virtual void ProcessEvent(SEntityEvent& event) override;
	// ~IEntityComponent

	void Fire();


	// Reflect type to set a unique identifier for this component
	static void ReflectType(Schematyc::CTypeDesc<CWeapon>& desc)
	{
		desc.SetGUID("{D07266EC-6743-4107-85C2-27E3957FB99B}"_cry_guid);
		desc.SetEditorCategory("MyComponents");
		desc.SetLabel("Weapon");
	}

private:
	void FrameUpdate();

private:
	float m_fLastFireTime;
};