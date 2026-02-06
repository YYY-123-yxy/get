# get_next_line

*This project has been created as part of the 42 curriculum by <ziyang>.*

## Description

`get_next_line` is a function that reads and returns a single line from a file descriptor. This project introduces the concept of static variables in C and challenges students to manage memory efficiently while handling file I/O operations.

The main goal is to implement a function that:
- Reads from a file descriptor one line at a time
- Returns the line including the newline character `\n`
- Returns `NULL` when there's nothing left to read or an error occurs
- Works with any valid `BUFFER_SIZE` value
- Handles multiple consecutive calls to read an entire file line by line

This project is fundamental for understanding file manipulation and memory management in C, skills that are essential for system programming.

## Instructions

### Compilation

The project must be compiled with the following flags:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c
```

You can change the `BUFFER_SIZE` value during compilation:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Files

The project consists of the following files:
- `get_next_line.c` - Main function implementation
- `get_next_line.h` - Header file with function prototypes
- `get_next_line_utils.c` - Utility functions (ft_strlen, ft_strchr, ft_strjoin, ft_strchr, extraire_line, save_reste)

### Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Testing

To test the function:
```bash
# Create a test file
vim test.txt
hello world!
how are you?
have a nice day!

# Compile with main
cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c 

# Run
./a.out

# valgrind
valgrind ./a.out
```

## Resources

### Documentation
- [Linux man page - read(2)](https://man7.org/linux/man-pages/man2/read.2.html) - System call documentation
- [Linux man page - open(2)](https://man7.org/linux/man-pages/man2/open.2.html) - File descriptor operations
- [Static variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - Understanding static keyword

### Articles and Tutorials
- [Medium - @lannur-s's get_next_line series](https://medium.com/@lannur-s) - Comprehensive project explanation and implementation guidance
- [YouTube - get_next_line explanation](https://www.youtube.com/watch?v=-Mt2FdJjVno) - Video tutorial on the project implementation

### Testers
- [xicodomingues/francinette](https://github.com/xicodomingues/francinette) - 42 project tester

---

## Additional Notes

- This implementation covers the **mandatory part** only (single file descriptor)
