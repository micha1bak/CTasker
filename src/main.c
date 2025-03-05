#include <stdio.h>
#include "./modules/task/task.h"

int main(void) {
	Task task = {1, "First Task", false};
	printf("%d\n %s\n", task.id, task.name);
	return 0;
}