#pragma once

#include "Type.h"
#include "IMemory.h"

class Slot {
public:
	static int g_Id;

private:
	int id;
	Slot* pNext;

	void* pObject;
	size_t sizeObject;
	char nameObject[LENGTH_NAME] = { 0 };

public:
	void* operator new(size_t size, char* pAddress){
		return (void *) pAddress;
	}
	void operator delete(void* pObjet) {
		// do nothing
	}
	void operator delete(void* pObjet, char* pAddress) {
		// default desturctor, do nothing
	}

	Slot() {
		this->id = g_Id++;
		this->sizeObject = 0;
		this->pNext = nullptr;
	}
	virtual ~Slot() {
	}
	int getId() { return this->id; }
	void setId(int id) { this->id = id; }
	void* getPObject() { return this->pObject; }
	void setPObject(void* pObject) { this->pObject = pObject; }
	size_t getSizeObject() { return this->sizeObject; }
	void setSize(size_t sizeObject) { this->sizeObject = sizeObject; }
	const char* getNameObject() { return this->nameObject; }
	void setNameObject(const char* nameObject);
	Slot* getPNext() { return this->pNext; }
	void setPNext(Slot* pNext) { this->pNext = pNext; }
};

class Memory : public IMemory
{
private:
//	char* pBuffer;
	char* pCurrent;
	int countSlots;
	Slot* pFreeSlots;
	Slot* pAllocatedSlots;

	void allocateASlot(void *pObject, size_t sizeObject, const char *nameObject) {
		if (this->pFreeSlots == nullptr) {
			// exception - out of slot
			printf("%s: exception - out of slot\n", __func__);
		}
		// detach
		Slot* pSlot = this->pFreeSlots;
		this->pFreeSlots = pSlot->getPNext();
		// set attributes
		pSlot->setPObject(pObject);
		pSlot->setSize(sizeObject);
		pSlot->setNameObject(nameObject);
		// attach
		pSlot->setPNext(this->pAllocatedSlots);
		this->pAllocatedSlots = pSlot;
	}

	void dellocateASlot(void* pObject) {
		Slot* pPreviousSlot = this->pAllocatedSlots;
		Slot *pSlot = this->pAllocatedSlots;
		while (pSlot != nullptr) {
			if (pSlot->getPObject() == pObject) {
			// if found
				// detach
				if (pSlot == this->pAllocatedSlots) {
					this->pAllocatedSlots = pSlot->getPNext();
				}
				else {
					pPreviousSlot->setPNext(pSlot->getPNext());
				}
				// attach
				pSlot->setPNext(this->pFreeSlots);
				this->pFreeSlots = pSlot;
				return;
			}
			pPreviousSlot = pSlot;
			pSlot = pPreviousSlot->getPNext();
		}
		// exception - not found
		printf("%s: exception - not found\n", __func__);
	}
public:
	void* operator new(size_t size, char *pBuffer) {
		return pBuffer;
	}
	void operator delete(void* pObject) {
	}
	void operator delete(void* pObject, char* pBuffer) {
	}

	Memory (int countSlots) {
		this->countSlots = countSlots;

		this->pCurrent = (char*)((size_t)this + sizeof(Memory));
		this->pFreeSlots = nullptr;
		for (int i = 0; i < this->countSlots; i++) {
			Slot* newSlot = new (this->pCurrent) Slot();
			this->pCurrent = (char*)((size_t)this->pCurrent + sizeof(Slot));

			newSlot->setPNext(this->pFreeSlots);
			this->pFreeSlots = newSlot;
		}
		this->pAllocatedSlots = nullptr;
	}
	virtual ~Memory() {

	}
	void* allocate(size_t size, const char* pName);
	void dellocate(void* pObject);

	void printSlots();
};

