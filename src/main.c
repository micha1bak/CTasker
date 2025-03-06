#include <stdio.h>
#include <string.h>
#include "lib/todo.h"

void save_todos_to_file(Todo todos[], int todos_size, const char *filename);
int read_todos_from_file(Todo todos[], const char *filename);

int main(void) {
	int driver = 1;
	while (driver) {
		int temp_id = 0;
		char temp_name[250];
		printf("+======================================+\n");
		printf("| Choose one of the following options: |\n");
		printf("| 1. Show the list of todos            |\n");
		printf("| 2. Add a new todo                    |\n");
		printf("| 3. Modify an existing todo           |\n");
		printf("| 4. Delete a todo from the list       |\n");
		printf("| 5. Read todos from a file            |\n");
		printf("| 6. Save todos to a file              |\n");
		printf("| 7. Exit                              |\n");
		printf("+======================================+\n");
		printf(">> ");
		if (scanf("%d", &driver) != 1) {
			printf("Invalid input! Please enter a number.\n");
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');
		switch (driver) {
			case 1:
				display_todos();
				break;
			case 2:
				printf("Enter todo: ");
				if (fgets(temp_name, sizeof(temp_name), stdin) == NULL) {
					printf("Error reading input.\n");
					break;
				}
				temp_name[strcspn(temp_name, "\n")] = '\0';
				create_todo(todos_size, temp_name, false);
				break;
			case 3:
				printf("Enter id: ");
				scanf("%d", &temp_id);
				modify_todo(temp_id);
				break;
			case 4:
				printf("Enter id: ");
				scanf("%d", &temp_id);
				delete_todo(temp_id);
				break;
			case 5:
				read_todos_from_file(todos, "todos.txt");
			case 7:
				driver = 0;
		}
	}
	return 0;
}

void save_todos_to_file(Todo todos[], int todos_size, const char *filename) {
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		printf("Nie można otworzyć pliku do zapisu.\n");
		return;
	}
	for (int i = 0; i < todos_size; i++) {
		fprintf(file, "%d|%s|%d\n", todos[i].id, todos[i].name, todos[i].isCompleted);
	}
	fclose(file);
}

int read_todos_from_file(Todo todos[], const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Nie można otworzyć pliku do odczytu.\n");
		return 0;
	}
	int count = 0;
	char line[300];
	while (fgets(line, sizeof(line), file) && count < MAX_TODOS) {
		line[strcspn(line, "\n")] = '\0';
		int id, isCompleted;
		char name[250];
		if (sscanf(line, "%d|%249[^|]|%d", &id, name, &isCompleted) == 3) {
			todos[count].id = id;
			strcpy(todos[count].name, name);
			todos[count].isCompleted = isCompleted;
			count++;
		}
	}
	fclose(file);
	return count;
}