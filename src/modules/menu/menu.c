#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../task/task.h"
#include "../db/db.h"
#include "../ui/ui.h"

void displayMenu(void) {
  	int choice;
	printf("=================================================================\n");
	printf(" 1. Add a task\n");
	printf(" 2. Mark as completed\n");
	printf(" 3. Delete a task\n");
	printf(" 4. Show task list\n");
	printf(" 0. Exit\n");
	printf("=================================================================\n");
	printf(" Choose an option: ");
    scanf("%i", &choice);
    handleUserInput(choice);
}

void handleUserInput(int choice) {
	char taskName[250];
	int taskId;
   	switch (choice) {
    	case 1:
            printf("Enter the task: ");
            fgets(taskName, 250, stdin);
            addTask(taskName);
            dbSize++;
            break;
        case 2:
            printf("Enter the task id to complete: ");
            scanf("%d", &taskId);
            completeTask(taskId);
            break;
        case 3:
   			printf("Enter the task id to delete: ");
   			scanf("%d", &taskId);
            deleteTask(taskId);
            dbSize--;
           	break;
        case 4:
        	displayAllTasks();
            break;
        case 0:
          	exit(0);
        default:
        	printf("Invalid choice!\n");
            printf("Please try again!\n");
            displayMenu();
 	}
}