# 📘 get_next_line – 42 School  

## 📝 Description  
**get_next_line (GNL)** is a 42 project that introduces **file reading in C**.  
The goal is to implement a function that reads a line from a file descriptor **one line at a time**, no matter the buffer size or file length.  

Prototype:  
```c
char *get_next_line(int fd);
```
This project helps you practice:

* File descriptors and read()

* Static variables

* Buffer management

* Memory allocation and string handling

## 🚀 Getting Started

### ▶️ Usage

Include the header in your project:
```c
#include "get_next_line.h"
```

* Example main.c:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### 📂 Repository Structure
```bash
get_next_line/
├── get_next_line.c
├── get_next_line.h
├── get_next_line_utils.c
├── main.c            # (for testing)
├── Makefile
└── README.md
```

### 📚 Concepts Covered

File descriptors

read() system call

Buffering and memory management

Static variables for persistence between calls

String manipulation

✅ Norm & Guidelines

Compliant with 42 Norm

No memory leaks (checked with valgrind)

Must handle multiple file descriptors simultaneously

Must compile with:

-Wall -Wextra -Werror

🧑‍💻 Author

Project developed at 1337 (42 Network) by:

[Your Name]