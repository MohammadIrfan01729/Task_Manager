# Daily Task Manager

A console-based Task Manager application written in C++ that allows users to manage daily tasks efficiently by adding, deleting, editing, and viewing tasks sorted by priority or deadline.

---

## Features

- Add tasks with name, priority, deadline date, and deadline time.
- Delete tasks by task name.
- Edit existing tasks including name, priority, and deadlines.
- View all tasks sorted by priority.
- View all tasks sorted by deadline date and time.
- Supports UTF-8 encoding for emoji display in console.
- Priority is sorted in ascending order (1 = highest priority).
- Clean and user-friendly console menu interface.

---

## Usage

Run the program and use the interactive menu options:

1. Add a new task by entering task details.
2. Delete a task by specifying the task name.
3. Edit an existing task with options to keep or update fields.
4. View all tasks sorted by priority.
5. View all tasks sorted by deadline date and time.
6. Exit the program.

The program stores tasks in a sorted linked list internally and automatically reorders tasks by priority after edits.

---

## Code Highlights

- Task class encapsulates task details and linked list node.
- TaskManager class manages tasks using a singly linked list.
- Console output supports UTF-8 emojis using `SetConsoleOutputCP(CP_UTF8)`.
- Sorting of tasks by deadline implemented using `std::vector` and `std::sort` with a custom comparator.
- Memory cleanup handled properly in destructor.
- Input handling supports editing tasks with optional updates.

---

## About the Author

This project was developed by an Information Technology undergraduate student at Chaitanya Bharathi Institute of Technology (CBIT). The author is focused on programming and software development, with a keen interest in creating efficient and user-friendly applications.

---

## How to Compile and Run

Use a C++ compiler supporting C++11 or later. On Windows, compile with:


---

## Future Enhancements

- Save tasks to a file and load on startup.
- Add search functionality by task name or date.
- Implement GUI for better usability.
- Support task categories and progress tracking.

---

## Contact

For questions or suggestions, please reach out during academic or college forums related to CBIT programming projects.

---

*Thank you for using the Daily Task Manager! Stay productive and organized!*  
