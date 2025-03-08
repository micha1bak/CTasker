#ifndef TODO_H
#define TODO_H
#define MAX_TODOS 100
#define FILENAME "../todos.txt"
#include <stdbool.h>

typedef struct Todo {
	int id;
	char name[250];
	bool isCompleted;
} Todo;

extern Todo todos[100];
extern int todos_size;

void create_todo(int id, char name[250], bool isCompleted);
void delete_todo(int id);
void modify_todo(int id);
void display_todos(void);
void save_todos_to_file(const char *filename);
void read_todos_from_file(const char *filename);
void freeze_program(void);

#endif
