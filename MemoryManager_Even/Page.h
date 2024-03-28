#pragma once
class Page
{
private:
	class Slot {
	public:
		Slot* pNext;
		size_t size;
	};
	Slot* pHeadFree;
	Slot* pHeadAllocated;
public:
	void* operator new(size_t size, char* pBuffer) {
		return pBuffer;
	}
	void operator delete(void* pObject) {
	}
	void operator delete(void* pObject, char* pBuffer) {
	}

	Page(size_t sizePage, size_t sizeSlot) {
		int numSlots = sizePage / sizeSlot;
		this->pHeadFree = (Slot*)(this + sizeof(Page));
		this->pHeadAllocated = nullptr;
		Slot* pSlot = pHeadFree;
		Slot* pPreviousSlot = nullptr;
		for (int i = 0; i < numSlots; i++) {
			pSlot->pNext = pSlot + sizeof(Slot);
			pPreviousSlot = pSlot;
			pSlot = pSlot->pNext;
		}
		pPreviousSlot->pNext = nullptr;
	}
	virtual ~Page() {}

	void* alloc() {
		Slot* pAllocated = pHeadFree;
		pHeadFree = pHeadFree->pNext;
		return (void*)pAllocated;
	}
	void delloc(void* pObject) {
		Slot* pSlot = (Slot*)pObject;
		pSlot->pNext = pHeadFree;
		pHeadFree = pSlot;
	}
};

