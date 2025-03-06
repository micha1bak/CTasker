#ifndef TODO_H
#define TODO_H
#define MAX_TODOS 100
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

#endif //TODO_H
