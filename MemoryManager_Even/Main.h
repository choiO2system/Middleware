#pragma once
#include "Camera.h"
#include "MemoryManager.h"
class Main
{
public:
	Main() {
		char *pBuffer = new char[1000];
		Object::pMemoryManager = new(pBuffer) MemoryManager(sizeof(char)* 1024, 256);
		// MemoryManager::new(sizeof(MemoryManager));

	}
	virtual ~Main() {
	}

	void run() {
		Camera* pCamera;
		pCamera= new Camera();
		pCamera->run();
		delete pCamera;

		pCamera = new Camera();
		pCamera->run();
		delete pCamera;
	}
};

