#include "Main.h"

#include "Memory.h"
int main() {
	char* pBuffer = new char[10000];
	int sizeSlots = 10;
	BaseObject::g_pMemory = new(pBuffer) Memory(sizeSlots);
	pBuffer = pBuffer + sizeof(Memory);
	BaseObject::g_pMemory->printSlots();

	Main main;
	main.initialize();
	main.run();
	main.finalize();
}
