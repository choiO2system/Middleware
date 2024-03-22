#include "BaseObject.h"

#include <string.h>

int BaseObject::g_idObject = 0;
IMemory *BaseObject::g_pMemory;

BaseObject::BaseObject(int idClass, const char* nameClass) {
	this->idClass = idClass;
	strcpy_s(this->nameClass, nameClass);
}