<div align="center">

# 📖 get_next_line

### *A 42 School Project - Reading Files Line by Line in C*

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-Compliant-success?style=flat)](https://github.com/42School/norminette)

*Master the art of file reading with efficient buffer management*

</div>

---

## 🎯 **Project Overview**

**get_next_line** is a fundamental 42 School project that challenges you to implement a function capable of reading a file line by line, regardless of buffer size or file length. This project introduces essential concepts of file manipulation, memory management, and static variables in C programming.

### 🔧 **Function Prototype**
\`\`\`c
char *get_next_line(int fd);
\`\`\`

### ✨ **Key Features**
- 📄 **Line-by-line reading** from any file descriptor
- 🔄 **Multiple file descriptors** support (bonus)
- 💾 **Efficient memory management** with no leaks
- ⚡ **Configurable buffer size** via compilation flags
- 🛡️ **Robust error handling** for edge cases

---

## 🚀 **Getting Started**

### 📋 **Prerequisites**
- GCC compiler
- Make utility
- Basic understanding of C programming

### 🔨 **Compilation**

#### Standard Version
\`\`\`bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
\`\`\`

#### Bonus Version (Multiple FDs)
\`\`\`bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
\`\`\`

### 💡 **Usage Example**

\`\`\`c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    // Open file for reading
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    // Read file line by line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("📝 %s", line);
        free(line);  // Don't forget to free!
    }
    
    close(fd);
    return (0);
}
\`\`\`

---

## 📁 **Project Structure**

\`\`\`
get_next_line/
├── 📄 get_next_line.c           # Main function implementation
├── 📄 get_next_line.h           # Header file with prototypes
├── 📄 get_next_line_utils.c     # Utility functions
├── 🎁 get_next_line_bonus.c     # Bonus: multiple FDs support
├── 🎁 get_next_line_bonus.h     # Bonus header file
├── 🎁 get_next_line_utils_bonus.c # Bonus utility functions
└── 📖 README.md                 # This file
\`\`\`

---

## 🧠 **Core Concepts Learned**

<table>
<tr>
<td width="50%">

### 🔍 **Technical Skills**
- **File Descriptors** manipulation
- **Static Variables** for state persistence
- **Buffer Management** and optimization
- **Memory Allocation** strategies
- **String Manipulation** in C

</td>
<td width="50%">

### 🎯 **Problem Solving**
- **Edge Case Handling** (empty files, large files)
- **Memory Leak Prevention**
- **Efficient Algorithm Design**
- **Code Modularity** and reusability
- **Error Management** patterns

</td>
</tr>
</table>

---

## ⚙️ **Implementation Details**

### 🔧 **Key Functions**

| Function | Purpose | Return Value |
|----------|---------|--------------|
| `get_next_line()` | Main function to read next line | Line string or NULL |
| `ft_strchr()` | Find character in string | Character or 0 |
| `ft_strjoin()` | Join two strings | New allocated string |
| `ft_strlen()` | Calculate string length | Length as size_t |
| `ft_substr()` | Extract substring | New allocated substring |
| `ft_clear()` | Memory cleanup utility | NULL |

### 💾 **Buffer Size Configuration**

The buffer size can be configured at compilation time:

\`\`\`bash
# Small buffer (testing edge cases)
gcc -D BUFFER_SIZE=1 [files...]

# Medium buffer (balanced performance)
gcc -D BUFFER_SIZE=42 [files...]

# Large buffer (performance optimization)
gcc -D BUFFER_SIZE=8192 [files...]
\`\`\`

---

## 🎁 **Bonus Features**

The bonus implementation adds support for **multiple file descriptors simultaneously**:

\`\`\`c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);  // Read from file1
char *line2 = get_next_line(fd2);  // Read from file2
char *line3 = get_next_line(fd1);  // Continue reading file1
\`\`\`

---

## 🧪 **Testing**

### 📝 **Test Cases**
- ✅ Empty files
- ✅ Single line files
- ✅ Files without final newline
- ✅ Very long lines
- ✅ Binary files
- ✅ Multiple file descriptors (bonus)
- ✅ Invalid file descriptors
- ✅ Memory leak testing with Valgrind

### 🔍 **Memory Testing**
\`\`\`bash
valgrind --leak-check=full --show-leak-kinds=all ./your_program
\`\`\`

---

## 📊 **Performance Considerations**

| Buffer Size | Memory Usage | Read Calls | Performance |
|-------------|--------------|------------|-------------|
| 1 | Low | High | Slow |
| 42 | Balanced | Moderate | Good |
| 1024 | Higher | Low | Fast |
| 8192+ | High | Very Low | Very Fast |

---

## 🎓 **Learning Outcomes**

After completing this project, you will have mastered:

- 🔧 **Low-level file operations** in C
- 💾 **Dynamic memory management** techniques
- 🔄 **Static variable usage** for state persistence
- 🛡️ **Defensive programming** practices
- ⚡ **Performance optimization** strategies

---

## 👨‍💻 **Author**

<div align="center">

**Mohamed Benchahyd** *(mbenchah)*

*42 School Student | C Programming Enthusiast*

[![GitHub](https://img.shields.io/badge/GitHub-MMMBenchahyd-181717?style=flat&logo=github)](https://github.com/MMMBenchahyd)
[![42 Profile](https://img.shields.io/badge/42-mbenchah-000000?style=flat&logo=42&logoColor=white)](https://profile.intra.42.fr/users/mbenchah)

</div>

---

## 📜 **License & Usage**

This project is part of the 42 School curriculum. Feel free to study the code for educational purposes, but please respect the 42 School's academic integrity policies.

---

<div align="center">

### 🌟 **If this helped you, consider giving it a star!** ⭐

*Made with ❤️ at 42 School*

</div>
