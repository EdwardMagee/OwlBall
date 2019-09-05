#pragma once

#include <Box2D/Box2D.h>
#include "GameSensor.h"

class Listener : public b2ContactListener
{
public:
	void BeginContact(b2Contact * contact); //!< start of contact
	void EndContact(b2Contact * contact); //!< end of contact
};
