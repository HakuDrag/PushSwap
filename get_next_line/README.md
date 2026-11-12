*This project has been created as part of the 42 curriculum by dkryvono.*

# get_next_line

A 42 C project that implements `get_next_line(int fd)`, returning one line from a file descriptor on every call. A returned line includes its trailing `\n` when present; the caller must `free()` it. The function returns `NULL` at EOF (once all text has been returned) or on error.

## Description

The mandatory implementation keeps unread bytes in one function-local static pointer. It calls `read()` with `BUFFER_SIZE` chunks, joins those bytes to the saved data, extracts the next line and retains any leftover bytes for the next invocation.

The bonus version uses a single static **array** of pointers, indexed by file descriptor, so calls for different descriptors can be interleaved. This implementation supports descriptor numbers from 0 to 1023.

## Files

| File | Purpose |
| --- | --- |
| `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h` | Mandatory implementation |
| `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h` | Standalone bonus implementation |
| `Makefile` | Builds the mandatory and bonus static libraries |

The bonus implementation uses separate files, rather than linking against the mandatory sources.

## Instructions

### Build

Use the standard Makefile targets:

```sh
make
make bonus
make clean
make fclean
make re
```

The default `make` builds the mandatory archive; `make bonus` builds the bonus archive. `make clean` removes object files, `make fclean` removes object files and archives, and `make re` rebuilds the mandatory archive.

### Test locally with the copied example

Copy the C program and text sample below into `main.c` and `test_gnl.txt`. Compile them directly, without extra Makefile targets:

```sh
make
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.a -o gnl
./gnl test_gnl.txt

make bonus
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -D GNL_BONUS main.c get_next_line_bonus.a -o gnl_bonus
./gnl_bonus test_gnl.txt test_gnl.txt
```

You can change `BUFFER_SIZE=42` to `1` or `9999` to test different buffer sizes. These commands link the temporary test program against the libraries built by the standard Makefile targets. Rebuild the libraries when changing their BUFFER_SIZE.

Check source formatting with:

```sh
norminette get_next_line*.c get_next_line*.h
```

## Copy-ready test programs

These are **optional local testers**, not files required for the 42 submission. Copy one example at a time into a temporary `main.c` and use the corresponding build command above.

### Mandatory `main.c`

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (fprintf(stderr, "Usage: ./gnl file\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

### Bonus `main.c`

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd[2];
	int		i;
	char	*line;

	if (argc != 3)
		return (fprintf(stderr, "Usage: ./gnl_bonus file1 file2\n"), 1);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		return (perror("open"), 1);
	fd[1] = open(argv[2], O_RDONLY);
	if (fd[1] < 0)
		return (close(fd[0]), perror("open"), 1);
	i = 0;
	while (fd[0] >= 0 || fd[1] >= 0)
	{
		if (fd[i] >= 0)
		{
			line = get_next_line(fd[i]);
			if (line)
			{
				printf("file %d: %s", i + 1, line);
				free(line);
			}
			else
			{
				close(fd[i]);
				fd[i] = -1;
			}
		}
		i = (i + 1) % 2;
	}
	return (0);
}
```

## Copy-ready test file (`test_gnl.txt`)

Copy the text below into `test_gnl.txt`. Each displayed line break is an actual newline, including the empty line between the second and fourth lines. The final line can be saved without a trailing newline to test EOF handling:

```text
Hello from get_next_line!
This is the second line.

Short.
A longer line follows to exceed a small BUFFER_SIZE and force multiple reads.
Last line without newline
```

## Algorithm and data structure

1. Save unread text between calls using a function-local static pointer (or a static array of pointers for the bonus).
2. Read up to `BUFFER_SIZE` bytes at a time until a newline appears or `read()` indicates EOF.
3. Allocate and return the next line, including `\n` when present.
4. Save everything following that line for the next call.
5. Free temporary buffers and handle allocation/read errors.

The source does not link with libft and does not use `lseek()` or global variables.

## Resources

- The 42 `get_next_line` subject, particularly the mandatory and bonus requirements.
- C/POSIX documentation for `read(2)`, `malloc(3)`, and `free(3)`.
- AI assistance (ChatGPT) was used to review the implementation, help debug memory ownership, prepare bonus build/test files, and draft this README. The underlying concepts and code should be reviewed and understood before evaluation.

## Notes

The sample `test_gnl.txt` is a convenience test file, not a required submission artifact. For school submission, follow the subject's prescribed source and header file names.
