#pragma once

class IMemory {
public:
	virtual void* allocate(size_t size, const char* pName) = 0;
	virtual void dellocate(void* pObject) = 0;
	virtual void printSlots() = 0;
};