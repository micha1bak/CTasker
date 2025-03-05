#ifndef TASK_H
#define TASK_H

#include <stdbool.h>

typedef struct {
	int id;
	char name[250];
    bool idCompleted;
} Task;

void addTask(Task *task);
void removeTask(int taskId);
void completeTask(int taskId);

#endif
