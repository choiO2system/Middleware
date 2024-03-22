#pragma once

#include "Type.h"
#include "IMemory.h"

class BaseObject
{
private:
	// object id counter
	static int g_idObject;

	// attributes
	int idClass;
	char nameClass[LENGTH_NAME];

public:
	static IMemory* g_pMemory;

	void* operator new(size_t size, const char *pName){
		return g_pMemory->allocate(size, pName);
	}
	void operator delete(void* pObject) {
		g_pMemory->dellocate(pObject);
	}
	void operator delete(void* pObject, const char* pName) {
		g_pMemory->dellocate(pObject);
	}

	// constructors and destructors
	BaseObject(int idClass, const char* nameClass);
	virtual ~BaseObject() {}

	virtual void initialize() {}
	virtual void finalize() {}

	// getters and setters
	int getIdClass() { return this->idClass; }
	char* getNameClass() { return this->nameClass; }
};

