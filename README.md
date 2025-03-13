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
![Menu](/utils/main.png)


## Installation

Clone the repository and compile the project using `gcc`:

````
git clone https://github.com/micha1bak/CTasker.git
cd CTasker
gcc -o CTasker src/main.c src/lib/todo.c
````

Run the aplication:

````
./CTasker ../name_of_your_file.txt
````

## File format

Todos are stored in a text file with the following format:

![todos.txt](/utils/file.png)