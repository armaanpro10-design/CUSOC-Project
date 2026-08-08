# C++ Terminal Todo App

A lightweight, blazing-fast Command Line Interface (CLI) Todo application written entirely in standard C++. 

This project uses standard file streams for persistent storage and requires no external libraries. It is designed to be easily compilable across Linux (including WSL), macOS, and Windows environments.

## Features

- **Add Tasks**: Include descriptions, priorities, categories, and due dates.
- **List Tasks**: Formatted, tabular console output.
- **Mark Completed**: Easily toggle task status.
- **Edit & Delete**: Full control over existing tasks.
- **Auto-Save**: Changes are persistently saved to `tasks.txt` in real-time.
- **Categorization**: Sort tasks by Work, Personal, or Study.

## Project Structure

```text
├── Makefile                # Build instructions
├── README.md               # Project documentation
├── src/
│   ├── main.cpp            # Entry point & CLI loop
│   ├── Task.h              # Task data structure
│   ├── TodoManager.h       # Manager class declaration
│   └── TodoManager.cpp     # Logic and File I/O implementation
             //