#pragma once
#include <stdio.h>
#include "Page.h"

class MemoryManager
{
public:
	Page* pHead;
	size_t sizeBuffer;
	size_t sizePage;
	
public:
	void* operator new(size_t size, char* pBuffer) {
		return pBuffer;
	}
	void operator delete(void* pObject) {
	}
	void operator delete(void* pObject, char* pBuffer) {
	}

	MemoryManager(size_t sizeBuffer, size_t sizePage) :
		pHead(nullptr),
		sizeBuffer(sizeBuffer),
		sizePage(sizePage)
	{
	}
	virtual ~MemoryManager() {
	}

	void* alloc(size_t sizeSlot) {
		void* pAllocated = nullptr;
		if (pHead == nullptr) {
			pHead = new((char*)((size_t)this + sizeof(MemoryManager))) Page(sizePage, sizeSlot);
		}
		return pHead->alloc();
	}
	void delloc(void* pObject) {
		pHead->delloc(pObject);
	}
};

