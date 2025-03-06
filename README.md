# CTasker

A command-line To-Do application written in C.

## Features

- ✅ Show the list of todos
- ➕ Add a new todo
- ✅ Mark todo as completed
- ❌ Delete a todo from the list
- 📂 Read todos from a file
- 💾 Save todos to a file
- 🚪 Exit the application

## Screenshots

### Main Menu
![Menu](/utils/menu.png)

### Todo List
![Todo List](/utils/todos.png)

## Installation

Clone the repository and compile the project using `gcc`:

````
git clone https://github.com/yourusername/c-todo-cli.git
cd c-todo-cli
gcc -o CTasker main.c
````

Run the aplication:

````
./CTasker
````

## File format

Todos are stored in a text file with the following format:

![todos.txt](/utils/file.png)