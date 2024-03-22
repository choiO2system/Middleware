#pragma once
#include "Camera.h"
#include "MemoryManager.h"
class Main
{
public:
	Main() {
		char *pBuffer = new char[1000];
		Object::pMemoryManager = new(pBuffer) MemoryManager(sizeof(char)* 100);
		// MemoryManager::new(sizeof(MemoryManager));

	}
	virtual ~Main() {
	}

	void run() {
		Object* pObject = new Object();


		Camera* pCamera;
		pCamera= new Camera();
		pCamera->run();
		delete pCamera;

		pCamera = new Camera();
		pCamera->run();
		delete pCamera;
	}
};

