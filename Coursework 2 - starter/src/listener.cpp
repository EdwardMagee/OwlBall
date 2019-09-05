#include "listener.h"

void Listener::BeginContact(b2Contact * contact)
{
}

void Listener::EndContact(b2Contact * contact)   //At the end of contact it will set the sensor to active
{
	b2Fixture *fixA = contact->GetFixtureA();
	b2Fixture *fixB = contact->GetFixtureB();

	bool isSensorA = fixA->IsSensor();
	bool isSensorB = fixB->IsSensor();

	GameSensor * sensor;
	if (isSensorA)
	{
		sensor = static_cast<GameSensor*>(fixA->GetBody()->GetUserData());
		if (sensor != nullptr) sensor->setActive();
	}
	if (isSensorB)
	{
		sensor = static_cast<GameSensor*>(fixB->GetBody()->GetUserData());
		if (sensor != nullptr) sensor->setActive();
	}
}
