#include <stdio.h>
#include <string.h>
#include "task.h"
#include "../db/db.h"

void addTask(char* taskName) {
	db[dbSize].id = dbSize + 1;
    strcpy(db[dbSize].name, taskName);
}

void removeTask(int taskId) {
	taskId--;
    for (int i = 0; i < dbSize; i++) {
      	db[taskId].id = db[taskId + 1].id;
      	strcpy(db[taskId].name, db[taskId + 1].name);
      	db[taskId].isCompleted = db[taskId + 1].isCompleted;
    }
}

void completeTask(int taskId) {
 	db[taskId].isCompleted = true;
}
