#ifndef TODO_H
#define TODO_H
#define MAX_TODOS 100
#include <stdbool.h>

typedef struct
{
	int id;
	char name[250];
	int priority;
	bool isCompleted;
} Todo;

extern Todo todos[MAX_TODOS];
extern int todos_size;

void create_todo(int id, char name[250],int temp_priority, bool isCompleted);
void delete_todo(int id);
void update_todo(int id, int prop);
void display_todos(void);
void save_todos_to_file(const char *filename);
void read_todos_from_file(const char *filename);

#endif
