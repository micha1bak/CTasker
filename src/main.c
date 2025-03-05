#include <stdio.h>
#include <string.h>
#include "lib/todo.h"

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
		printf("| 5. Exit                              |\n");
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
				driver = 0;
		}
	}
	return 0;
}
