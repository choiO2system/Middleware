#pragma once
#include "MemoryManager.h"
#include <stdio.h>
class Object
{
private:
	int id;
public:
	static MemoryManager* pMemoryManager;
	Object() {
	}
	virtual ~Object() {
	}
	void* operator new (size_t size) {
		void *pAllocated = pMemoryManager->alloc(size);
		printf("Object::new(%zu) %p\n", size, pAllocated);
		return pAllocated;
	}
	void operator delete(void* pObject) {
		printf("Object::delete(%p)\n", pObject);
		pMemoryManager->delloc(pObject);
	}
};

