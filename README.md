# Inverted Search Project

## Introduction

This is a **C language project** based on the concept of **Inverted Search**.

In this project, we take multiple `.txt` files as input and create a database of the words present in those files.

For each word, the database stores:

* The word
* Number of files in which the word is present
* File names
* Number of times the word occurs in each file

The project uses a **Hash Table, Main Node, Sub Node and Linked List** to store the data.

---

## Objective

The main objective of this project is to learn and implement:

* Hash table
* Linked list
* Structures
* Pointers
* Dynamic memory allocation
* File handling
* Command line arguments
* Searching and storing data

---

## Features

This project provides the following operations:

1. Create database
2. Display database
3. Save database
4. Search a word
5. Update database

---

## Data Structures Used

### 1. Singly Linked List

A singly linked list is used to store the input file names.

```c
typedef struct node
{
    char file[30];
    struct node *link;
} Slist_t;
```

This list is also used to avoid adding the same file more than once.

### 2. Main Node

The main node stores each unique word.

```c
typedef struct mainnode
{
    char words[30];
    int f_count;
    struct mainnode *m_link;
    struct subnode *s_link;
} m_node;
```

`f_count` represents the number of files in which the word is present.

### 3. Sub Node

The sub node stores the file name and word count.

```c
typedef struct subnode
{
    char filename[30];
    int w_count;
    struct subnode *s_link;
} s_node;
```

`w_count` represents how many times the word occurs in that particular file.

### 4. Hash Table

A hash table of size **28** is used.

```c
hash_t hash_table[28];
```

The indexes are divided as follows:

| Index  | Characters         |
| ------ | ------------------ |
| 0 - 25 | A-Z / a-z          |
| 26     | 0-9                |
| 27     | Special characters |

For example:

```text
apple   -> 0
banana  -> 1
cat     -> 2
123     -> 26
@hello  -> 27
```

---

## How the Project Works

First, we give text files through the command line.

Example:

```bash
./inverted_search file1.txt file2.txt
```

The program checks:

* File extension should be `.txt`
* File should exist
* File should not be empty
* Duplicate files are not added

After validation, the program shows the menu.

```text
:::Inverted Search Project:::

1.Create
2.Display
3.Save
4.Search
5.Update

Enter the option :
```

---

## 1. Create Database

The **Create** option reads all the input files and creates the inverted database.

For every word:

1. Hash index is calculated using the first character.
2. The program checks whether the word already exists.
3. If the word is new, a main node is created.
4. If the word already exists in the same file, its word count is increased.
5. If the word is found in another file, a new sub node is created.

For example, if:

### file1.txt

```text
hello hello world
```

### file2.txt

```text
hello programming
```

The database will store something like:

```text
hello
    file1.txt -> 2
    file2.txt -> 1

world
    file1.txt -> 1

programming
    file2.txt -> 1
```

---

## 2. Display Database

The **Display** option displays all the words stored in the database.

Example:

```text
--------------------------------------------------------------------------
Index    Word            Filecount    Filename             Wordcount
--------------------------------------------------------------------------
[ 0]     apple           2            file1.txt            3
                                     file2.txt            1
[ 1]     banana          1            file1.txt            2
--------------------------------------------------------------------------
```

It displays:

* Hash index
* Word
* File count
* File name
* Word count

---

## 3. Save Database

The **Save** option is used to save the created database into a `.txt` file.

Example:

```text
Enter the file name: database.txt
```

The database is stored in a specific format so that it can be loaded again using the **Update** option.

The saved data contains:

```text
Index
Word
File count
File name
Word count
```

---

## 4. Search Database

The **Search** option is used to search for a particular word.

Example:

```text
Enter the word: hello
```

If the word is present, it displays the files and the number of occurrences.

Example:

```text
--------------------------------------------------------------------------
Index    Word            Filecount    Filename             Wordcount
--------------------------------------------------------------------------
[ 7]     hello           2            file1.txt            2
                                     file2.txt            1
--------------------------------------------------------------------------
```

If the word is not present:

```text
DATA_NOT_FOUND
```

---

## 5. Update Database

The **Update** option is used to load a previously saved database.

Example:

```text
Enter the saved database file name: database.txt
```

The program reads the saved file and creates the main nodes and sub nodes again.

This is useful when we want to use an already saved database without creating it again from the original files.

---

## Project Files

```text
Inverted_Search/
│
├── main.c
├── header.h
├── validation.c
├── create_database.c
├── display_database.c
├── save_database.c
├── search_database.c
├── update_database.c
└── README.md
```

### Description

| File                  | Description                                   |
| -------------------- | ---------------------------------------------- |
| `main.c`              | Contains the main function and menu           |
| `header.h`            | Contains structures and function declarations |
| `validation.c`        | Validates input files                         |
| `create_database.c`   | Creates the inverted database                 |
| `display_database.c`  | Displays the database                         |
| `save_database.c`     | Saves the database into a file                |
| `search_database.c`   | Searches for a word                           |
| `update_database.c`   | Loads the saved database                      |

---

## Compilation

Use GCC to compile the project:

```bash
gcc main.c validation.c create_database.c display_database.c save_database.c search_database.c update_database.c -o inverted_search
```

---

## Running the Project

After compilation:

```bash
./inverted_search file1.txt file2.txt
```

Example:

```bash
./inverted_search file1.txt file2.txt file3.txt
```

---

## Sample Menu

```text
:::Inverted Search Project:::

1.Create
2.Display
3.Save
4.Search
5.Update

Enter the option :
```

---

## Technologies Used

* **Language:** C
* **Compiler:** GCC
* **Concepts:** Hash Table, Linked List, Structures, Pointers, File Handling

---

## Conclusion

This project helped me understand how an **Inverted Search** works using C.

I learned how to use **hash tables and linked lists** together to store and search words from multiple files. I also learned about file handling, dynamic memory allocation, structures and command line arguments.

---

## Author

**Inverted Search Project**

*C Programming Project*