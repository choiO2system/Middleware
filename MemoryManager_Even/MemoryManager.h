#pragma once
#include <stdio.h>
class MemoryManager
{
public:
	class Slot {
	public:
		Slot* pNext;
		size_t size;
	};
private:
	Slot* pHead;
	
public:
	void* operator new(size_t size, char* pBuffer) {
		return pBuffer;
	}
	void operator delete(void* pObject) {
	}
	void operator delete(void* pObject, char* pBuffer) {
	}

	MemoryManager(size_t sizeBuffer) {
		pHead = (Slot*)((size_t)this + sizeof(MemoryManager));
		pHead->pNext = nullptr;
		pHead->size = sizeBuffer - sizeof(MemoryManager);
	}
	virtual ~MemoryManager() {
	}

	void* alloc(size_t size) {
		Slot *pPrevious = this->pHead;
		void* pAllocated = nullptr;
		for (Slot* pSlot = this->pHead; pSlot != nullptr; pSlot = pSlot->pNext) {
			if (pSlot->size > size) {
				pAllocated = (void*)pSlot;
				if (pSlot == this->pHead) {
					pHead = pHead + size;
					pHead->size = pHead->size - size;
				} else {
					pPrevious->pNext = pPrevious->pNext + size;
					pSlot->size = pSlot->size - size;
				}
				
				printf("MemoryManager::alloc(%zu)\n", size);
				return pAllocated;
			}
			pPrevious = pSlot;
		}
		return pAllocated;
	}
	void delloc(void* pObject) {

	}
};

