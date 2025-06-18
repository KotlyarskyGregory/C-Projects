📝 Text-Based To-Do List Manager (C Project Guide)


📌 Project Overview
    Build a terminal-based to-do list manager in C that allows a user to manage tasks with operations like adding, listing, marking complete, deleting, and saving/loading from a file. This will help reinforce your skills with structs, dynamic memory, file I/O, and user interaction.


🎯 Objectives
    Practice using structs and dynamic memory (malloc, realloc, free)

    Manage arrays of custom data types

    Handle file I/O with fopen, fprintf, and fscanf or fgets

    Design a user-friendly command-line interface using menus and loops

    Improve string handling and input validation


🧱 Project Structure
    You will build a program that:

    Displays a menu with options

    Accepts user input

    Performs actions based on the input

    Loops until the user chooses to exit

    The main components are:

    Task Representation: Use a struct to define a task with at least a description and a completion flag.

    Task List: Use a dynamic array to store tasks and resize it as tasks are added or removed.

    Menu System: Loop to prompt the user with actions (add, delete, etc.).

    Persistence: Read and write tasks from a plain text file.


🧩 Features and Implementation Plan
    1. Add a Task
        Prompt the user for a task description (a string).

        Store the task in a dynamically allocated array.

        Set the "completed" flag to false (0).

    2. List All Tasks
        Print each task with:

        An index number

        Its description

        A status indicator (e.g., [ ] or [x] for incomplete/complete)

    3. Mark Task as Completed
        Ask the user for the index of the task.

        Change its completed status to true (1).

        Validate input to avoid invalid indices.

    4. Delete a Task
        Ask for the index of the task to delete.

        Shift tasks in the array to close the gap.

        Optionally resize the array (realloc) or just update the count.

    5. Save Tasks to File
        Write the list of tasks to a file (e.g., todo.txt).

        Format each line clearly: e.g., 0|Buy groceries or 1|Do homework

        Overwrite the file every time you save.

    6. Load Tasks from File
        Read the file line-by-line at the start (or on user command).

        Parse each line and extract the status and description.

        Allocate memory for each task as you read them in.

    7. Exit
        On exit, free all dynamically allocated memory to prevent leaks.

        Optionally ask to save if changes were made.


💾 File Format Suggestions

    Use a simple format for readability and parsing:

        0|Buy milk
        1|Write C program
        0|Call friend
        Where:

        The number indicates completion (0 = incomplete, 1 = complete)

        The rest is the task description


💡 Additional Tips
    Use a loop and switch to handle menu selections.

    Use fgets instead of scanf("%s") to handle full-line input.

    Always validate user input and file operations.

    Build incrementally: get "Add" and "List" working first.

