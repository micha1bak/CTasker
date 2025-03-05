#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../db/db.h"
#include "../task/task.h"

void displayHeader(void) {
	printf("+----+----------------------------------------+-----------------+\n");
	printf("| ID |                  Task                  |      Status     |\n");
	printf("+----+----------------------------------------+-----------------+\n");
}

void displayTaskRow(Task task) {
	printf("| %-2d | %-38s | %-15s |\n",
		 task.id,
         task.name,
		 task.isCompleted ? "✔ Completed" : "❌ Not Completed");
}

void displayAllTasks(void) {
	if (dbSize == 0) {
		printf("No tasks in database!\n");
		return;
	}
	displayHeader();
	for (int i = 0; i < dbSize; i++) {
		displayTaskRow(db[i]);
	}
	printf("+----+----------------------------------------+-----------------+\n");
}