#include "Memory.h"

#include <string.h>
#include <stdlib.h>

#include "BaseObject.h"

int Slot::g_Id = 0;

void Slot::setNameObject(const char* nameObject) {
	strcpy_s(this->nameObject, nameObject);
}

void* Memory::allocate(size_t size, const char* pName) {
	void* pObject = malloc(size);
	this->allocateASlot(pObject, size, pName);
	return pObject;
}
void Memory::dellocate(void* pObject) {
	this->dellocateASlot(pObject);
	free(pObject);
} 
void Memory::printSlots() {
	printf("%s: Allocated Slots\n", __func__);
	for (Slot* pSlot = this->pAllocatedSlots; pSlot != nullptr; pSlot = pSlot->getPNext()) {
		BaseObject* pObject = (BaseObject*)pSlot->getPObject();
		printf("  %d: %p, %d, %s, %zu, %s\n",
			pSlot->getId(),
			pSlot->getPObject(),
			pObject->getIdClass(),
			pObject->getNameClass(),
			pSlot->getSizeObject(),
			pSlot->getNameObject());
	}
	printf("%s: Free Slots\n", __func__);
	for (Slot* pSlot = this->pFreeSlots; pSlot != nullptr; pSlot = pSlot->getPNext()) {
		printf("  %d: %p\n", pSlot->getId(), pSlot);
	}
}