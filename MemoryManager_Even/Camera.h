#pragma once

#include "Object.h"
class Camera: public Object
{
private:
	int id;
	int id1;
	int id2;
	int id3;
	int id4;
public:
	Camera() {
		this->id = 0;
		printf("Camera::Camera()\n");

		printf("sizeof(char)=%zu\n", sizeof(char));
		printf("sizeof(int)=%zu\n", sizeof(int));
		printf("sizeof(float)=%zu\n", sizeof(float));
		printf("sizeof(Object)=%zu\n", sizeof(Object));
		printf("sizeof(Camera)=%zu\n", sizeof(Camera));
		printf("sizeof(MemoryManager)=%zu\n", sizeof(MemoryManager));
	}
	virtual ~Camera() {
		printf("Camera::~Camera()\n");
	}

	void run() {
		printf("Camera::run(%d)\n", this->id);
	}
};

