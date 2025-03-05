#include <stdio.h>
#include "./modules/menu/menu.h"

void main(void) {
	printf("+---------------------------------------------------------------+\n");
	printf("|                        To Do App!                             |\n");
	printf("+---------------------------------------------------------------+\n");
	while (1) {
		displayMenu();
	}
}

