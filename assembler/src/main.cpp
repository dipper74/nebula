#include "../include/regi.h"

using namespace nebula;

// Reg Type Test

void printType(nbReg ro) {
	if (dynamic_cast<nbRegFilterGp8*>(ro.getRef())) {
		cout << "Gp8\n";
	}
	if (dynamic_cast<nbRegFilterGp16*>(ro.getRef())) {
		cout << "Gp16\n";
	}
	if (dynamic_cast<nbRegFilterGp32*>(ro.getRef())) {
		cout << "Gp32\n";
	}
	if (dynamic_cast<nbRegFilterGp64*>(ro.getRef())) {
		cout << "Gp64\n";
	}
}

int main() {

	printType(al );
	printType(ax );
	printType(eax);
	printType(rax);

	return 0;
}