#ifndef TASK_H
#define TASK_H

#include <stdbool.h>

typedef struct {
	int id;
	char name[250];
    bool isCompleted;
} Task;

void addTask(char* taskName);
void removeTask(int taskId);
void completeTask(int taskId);

#endif
