#include <stdio.h>
#include <string.h>
#include "todo.h"

Todo todos[100];
int todos_size = 0;

void create_todo(int id, char name[250], bool isCompleted) {
	Todo todo;
	todo.id = id + 1;
	strcpy(todo.name, name);
	todo.isCompleted = isCompleted;
	todos[todos_size] = todo;
	todos_size++;
}

void delete_todo(int id) {
	if (id >= todos_size) {
		printf("Id out of range\n");
		return;
	}
	for (int i = id - 1; i <= todos_size - id; i++) {
		todos[i] = todos[i + 1];
		todos[i].id--;
	}
	todos_size--;
	printf("Deleted a todo.\n");
}

void complete_todo(int id) {
	todos[id - 1].isCompleted = true;
}

void display_todos(void) {
	printf("+==============================================================+\n");
	printf("| ID  |                  TODO                     |   Status   |\n");
	printf("+==============================================================+\n");
	for (int i = 0; i < todos_size; i++) {
		printf("| %-3d | %-41s | %-10s |\n", todos[i].id, todos[i].name,
			todos[i].isCompleted ? "Completed" : "Pending");
	}
	if (todos_size < 10) {
		for (int i = 0; i < 10; i++) {
			printf("|     |                                           |            |\n");
		}
	}
	printf("+==============================================================+\n");
	printf("|   1 - Add   |   2 - Complete  |  3 - Delete   |   4 - Exit   |\n");
	printf("+==============================================================+\n\n");
	printf(">>");
}

void save_todos_to_file(const char *filename) {
	FILE *fptr = fopen(filename, "w");
	if (fptr == NULL) {
		printf("Err\n");
		return;
	}
	for (int i = 0; i < todos_size; i++) {
		fprintf(fptr, "%d|%s|%d\n", todos[i].id, todos[i].name, todos[i].isCompleted);
	}
	fclose(fptr);
}

void read_todos_from_file(const char *filename) {
	FILE *fptr = fopen(filename, "r");
	if (fptr == NULL) {
		printf("Err\n");
		return;
	}
	char line[300];
	while (fgets(line, sizeof(line), fptr) && todos_size < MAX_TODOS ) {
		line[strcspn(line, "\n")] = '\0';
		int id, isCompleted;
		char name[250];
		if (sscanf(line, "%d|%249[^|]|%d", &id, name, &isCompleted) == 3) {
			todos[todos_size].id = id;
			strcpy(todos[todos_size].name, name);
			todos[todos_size].isCompleted = isCompleted;
			todos_size++;
		}
	}
	fclose(fptr);
}
