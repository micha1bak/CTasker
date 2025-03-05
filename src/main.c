#include <stdio.h>
#include "./modules/task/task.h"
#include "./modules/db/db.h"

int main(void) {

	Task task = {1, "First Task", false};
	printf("%d\n %s\n", task.id, task.name);

	return 0;
}
