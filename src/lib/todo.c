#include <stdio.h>
#include <string.h>
#include "todo.h"

Todo todos[100];
int todos_size = 0;

void create_todo(int id, char name[250], bool isCompleted) {
	Todo todo;
	todo.id = id;
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
	for (int i = id; i <= todos_size - id; i++) {
		todos[i] = todos[i + 1];
		todos[i].id--;
	}
	todos_size--;
}

void modify_todo(int id) {
	todos[id].isCompleted = true;
}

void display_todos(void) {
	for (int i = 0; i < todos_size; i++) {
		printf("id: %d, name: %s, status: %d\n", todos[i].id, todos[i].name, todos[i].isCompleted);
		printf("\n");
	}
}
