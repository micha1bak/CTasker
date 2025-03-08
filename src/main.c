#include <stdio.h>
#include <string.h>
#include "lib/todo.h"

void display_menu(void);

int main(void) {
	int driver = 1;
	while (driver) {
		int temp_id = 0;
		char temp_name[250];
		display_menu();
		if (scanf("%d", &driver) != 1) {
			printf("Invalid input! Please enter a number.\n");
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');
		switch (driver) {
			case 1:
				display_todos();
				freeze_program();
				break;
			case 2:
				display_todos();
				printf("Enter a todo discription:\n");
				printf(">> ");
				if (fgets(temp_name, sizeof(temp_name), stdin) == NULL) {
					printf("Error reading input.\n");
					break;
				}
				temp_name[strcspn(temp_name, "\n")] = '\0';
				create_todo(todos_size, temp_name, false);
				display_todos();
				freeze_program();
				break;
			case 3:
				display_todos();
				printf("Enter id:\n");
				printf(">> ");
				scanf("%d", &temp_id);
				while (getchar() != '\n');
				modify_todo(temp_id);
				display_todos();
				freeze_program();
				break;
			case 4:
				display_todos();
				printf("Enter id:\n");
				printf(">> ");
				scanf("%d", &temp_id);
				while (getchar() != '\n');
				delete_todo(temp_id);
				display_todos();
				freeze_program();
				break;
			case 5:
				read_todos_from_file(FILENAME);
				display_todos();
				freeze_program();
				break;
			case 6:
				save_todos_to_file(FILENAME);
				display_todos();
				freeze_program();
				break;
			case 7:
				driver = 0;
		}
	}
	return 0;
}

void display_menu(void) {
	printf("+==============================================================+\n");
	printf("|                             MENU                             |\n");
	printf("+==============================================================+\n");
	printf("| 1 | Show the list of todos                                   |\n");
	printf("|--------------------------------------------------------------|\n");
	printf("| 2 | Add a new todo                                           |\n");
	printf("|--------------------------------------------------------------|\n");
	printf("| 3 | Mark todo as completed                                   |\n");
	printf("|--------------------------------------------------------------|\n");
	printf("| 4 | Delete a todo from the list                              |\n");
	printf("|--------------------------------------------------------------|\n");
	printf("| 5 | Read todos from a file                                   |\n");
	printf("|--------------------------------------------------------------|\n");
	printf("| 6 | Save todos to a file                                     |\n");
	printf("|--------------------------------------------------------------|\n");
	printf("| 7 | Exit                                                     |\n");
	printf("+==============================================================+\n");
	printf(">> ");
}