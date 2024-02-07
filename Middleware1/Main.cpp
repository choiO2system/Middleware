#include "Main.h"

int main() {
	Main main;
	main.initialize();
	main.run();
	main.finalize();

	Main* pMain = new Main();
	delete pMain;
}
