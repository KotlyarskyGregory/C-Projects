# 📝 Terminal To-Do List (C Implementation)

A modular, efficient, and extensible terminal-based to-do list application written in C — built from scratch without external libraries. Tasks are stored in a doubly linked list, with a hash table for fast lookup, and a flexible view system that supports custom sorting.

---

## 📐 Project Goals

- Efficient and scalable task management
- Clean, maintainable architecture
- Sorting by various fields (urgency, due date, etc.)
- No use of external libraries — full implementation of data structures and algorithms in C

---

## 🧱 Architecture Overview

### 1. **Doubly Linked List**
- Holds all tasks in **insertion order**
- Used for main storage and iteration
- Append-only for simplicity and performance

### 2. **Hash Table**
- Maps task IDs to their corresponding task or list node
- Enables fast lookup, editing, and deletion (O(1) expected)

### 3. **View System**
- When the user requests a sorted view:
  - The linked list is traversed
  - Task pointers are copied into a temporary array
  - The array is sorted using a chosen comparator
  - The result is printed, and then the array is discarded when changes are made to linked list


---


## 📦 Task Data Model

Each task contains:

- Unique `id`
- `title` and optional `description`
- `created` timestamp
- `due` date
- `urgency` level (e.g., 1–5)
- `estimated_time` (minutes)

---

## 🔄 Key Features

### Core
- Add task (append to list, insert into hash table)
- Delete task (lookup via hash table, remove from list)
- List all tasks (in insertion order)

### View/Sort
- View sorted by:
  - Due date
  - Urgency
  - Estimated time
  - Created date
- View is **non-destructive** — original list remains unchanged

### Persistence
- Load tasks from file on startup
- Save tasks to file on exit or command


