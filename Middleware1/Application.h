#pragma once
#include "BaseObject.h"

class Application: public BaseObject
{
public:
	Application() : BaseObject(1, "Application") {
	}

	virtual ~Application() {
	}
};

