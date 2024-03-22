#pragma once

#include "Application.h"

class Main
{
private:
	Application* pApplication;
public:
	Main() {
		printf("%s\n", __func__);
		this->pApplication = nullptr;
	}
	virtual ~Main() {
		printf("%s\n", __func__);
	}

	void initialize() {
		printf("%s\n", __func__);
		this->pApplication = new("pApplication") Application();
		BaseObject::g_pMemory->printSlots();
	}
	void run() {
		printf("%s\n", __func__);

		printf("%d %s\n",
			this->pApplication->getIdClass(),
			this->pApplication->getNameClass());		
	}
	void finalize() {
		printf("%s\n", __func__);
		delete this->pApplication;
		BaseObject::g_pMemory->printSlots();
	}
};

