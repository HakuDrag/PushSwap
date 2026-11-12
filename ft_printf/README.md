*This project has been created as part of the 42 curriculum by <dkryvono>, <callwood>.*

# ft_printf

## Description

This project is a partial reimplementation of the standard C `printf()` function.

It can print formatted text using a variable number of arguments and return the
number of characters written.

In addition to the mandatory conversions, the bonus part introduces a system of
formatting flags. These flags control how arguments appear in the output, such as
adding spaces, leading zeros, signs, hexadecimal prefixes or a minimum width.

The goal of the project is to learn how variadic functions work in C, how to
interpret a format string and how to keep track of the printed characters.

### Mandatory part

The library implements the following conversions:

- `%c` — a single character

- `%s` — a string

- `%p` — a pointer in hexadecimal

- `%d` and `%i` — signed decimal integers

- `%u` — unsigned decimal integers

- `%x` and `%X` — lowercase and uppercase hexadecimal

- `%%` — a literal percent sign

### Bonus part

The bonus version supports formatting flags, minimum field width, and precision.
The following rules describe the behavior of standard `printf` for the conversions
implemented in this project. They are also the intended behavior of the bonus version.

#### Format syntax

```c
%[flags][width][.precision]specifier
```

For example, `%+08d` prints a signed integer in a field at least eight characters
wide, including the sign, with leading zeros where needed.

#### Formatting flags

| Flag | Meaning | Applicable conversions | Not applicable / ignored |
| --- | --- | --- | --- |
| `-` | Left-align within the minimum field width; pad on the right with spaces. | `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` | No visible effect without extra width; overrides `0`. |
| `0` | Pad with leading zeros instead of spaces when right-aligned. | `d`, `i`, `u`, `x`, `X` (and pointer formatting where supported) | Ignored with `-`; ignored for integer conversions when precision is specified; not meaningful for `c` or `s`. |
| `.` | Introduce precision. For integers: minimum digit count. For strings: maximum bytes printed. | `s`, `d`, `i`, `u`, `x`, `X` | Not applicable to `c`; pointer precision is implementation-dependent and outside the project's guaranteed scope. |
| `#` | Use alternate hexadecimal form: `0x` for `x`, `0X` for `X` when the value is nonzero. | `x`, `X` | Not meaningful for `c`, `s`, `p`, `d`, `i`, `u`. |
| `+` | Always print a sign for signed decimal integers (`+` or `-`). | `d`, `i` | Not meaningful for `c`, `s`, `p`, `u`, `x`, `X`; overrides the space flag. |
| Space | Prefix positive signed decimal integers with one space when no sign is printed. | `d`, `i` | Not meaningful for `c`, `s`, `p`, `u`, `x`, `X`; ignored if `+` is present. |

`%%` is a literal percent conversion; flag, width and precision combinations
with it are outside the required scope of this project.

#### Minimum field width

Width is a number, not a flag. It specifies the **minimum** number of characters
in the formatted field. The output is padded with spaces by default, but a value
longer than the width is never truncated.

| Format | Argument | Output (brackets show boundaries) |
| --- | --- | --- |
| `%5d` | `42` | `[   42]` |
| `%-5d` | `42` | `[42   ]` |
| `%05d` | `42` | `[00042]` |
| `%8s` | `"Hi"` | `[      Hi]` |
| `%3s` | `"Hello"` | `[Hello]` |

#### Precision (`.`)

Precision has different meanings depending on the conversion:

- For `d`, `i`, `u`, `x`, and `X`, it specifies the minimum number of digits.
  For example, `%.5d` with `42` produces `00042`.
- For `s`, it limits the number of bytes written from the string.
  For example, `%.3s` with `"Hello"` produces `Hel`.
- A precision of zero with integer value zero produces no digits (for the
  integer conversions supported here).
- When integer precision is present, the `0` flag is ignored; field-width
  padding uses spaces.

#### Flag interactions

| Combination | Rule | Example output |
| --- | --- | --- |
| `-` and `0` | `-` takes priority. | `%-05d`, `42` → `[42   ]` |
| `+` and space | `+` takes priority. | `%+ d`, `42` → `[+42]` |
| `0` and integer precision | Precision takes priority over zero padding. | `%08.5d`, `42` → `[   00042]` |
| `#` and `x` | Prefix nonzero hexadecimal values with `0x`. | `%#x`, `42` → `[0x2a]` |
| `#` and `X` | Prefix nonzero hexadecimal values with `0X`. | `%#X`, `42` → `[0X2A]` |
| `#` and zero | No hexadecimal prefix for zero. | `%#x`, `0` → `[0]` |
| `+` and `0` | Sign comes before zero padding. | `%+05d`, `42` → `[+0042]` |

**Scope note:** The compatibility rules above describe the supported conversions,
not all standard C `printf` features. Other conversion specifiers and length
modifiers are not part of this project. The README does not by itself verify
that every combination has been implemented correctly; test the bonus library
against the reference `printf` for supported, defined cases.

Both builds produce the same static library: `libftprintf.a`.

## Instructions

The project is designed for a Unix-like environment with `cc`, `make` and `ar`.

It uses the local `libft/` library.

```sh

make          # Build the mandatory version

make bonus    # Build the version with formatting flags

make clean    # Remove object files

make fclean   # Remove object files and the archive

make re       # Rebuild the mandatory version

```

The Makefile uses `-Wall -Wextra -Werror`. The resulting
`libftprintf.a` is created at the root of the project.

To use the library in another program:

```c

#include "ft_printf.h"

int main(void)

{

    int printed;

    printed = ft_printf("Hello, %s! Number: %d\n", "42", 42);

    ft_printf("Printed %d characters.\n", printed);

    return (0);

}

```

Compile this example as `main.c`:

```sh

make

cc -Wall -Wextra -Werror main.c libftprintf.a -o program

./program

```

### Testing

The examples below are two **independent** test programs. Copy the first
block into a temporary `main.c` for mandatory tests, or the second block
into a temporary `main.c` for bonus tests. Do not commit `main.c` to
the submitted project.

Each test prints the output of the system `printf` and `ft_printf`,
followed by a `GOOD` / `FAIL` comparison of their return values.
Also compare the two output lines: equal return values do not guarantee
identical text.

#### Mandatory `main.c`

```c
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static void	check(const char *name, int expected, int actual)
{
	printf("%-22s %s (%d / %d)\n", name,
		expected == actual ? "GOOD" : "FAIL", expected, actual);
}

int	main(void)
{
	int		value;
	char	*null_str;
	void	*ptr;

	value = 42;
	null_str = NULL;
	ptr = &value;
	setvbuf(stdout, NULL, _IONBF, 0);
	check("character", printf("[%c]\n", 'A'), ft_printf("[%c]\n", 'A'));
	check("NUL character", printf("[%c]\n", 0), ft_printf("[%c]\n", 0));
	check("string", printf("[%s]\n", "Hello"), ft_printf("[%s]\n", "Hello"));
	check("NULL string", printf("[%s]\n", null_str),
		ft_printf("[%s]\n", null_str));
	check("pointer", printf("[%p]\n", ptr), ft_printf("[%p]\n", ptr));
	check("NULL pointer", printf("[%p]\n", (void *)0),
		ft_printf("[%p]\n", (void *)0));
	check("signed", printf("[%d]\n", INT_MIN),
		ft_printf("[%d]\n", INT_MIN));
	check("integer", printf("[%i]\n", -42), ft_printf("[%i]\n", -42));
	check("unsigned", printf("[%u]\n", UINT_MAX),
		ft_printf("[%u]\n", UINT_MAX));
	check("hex lower", printf("[%x]\n", 255u), ft_printf("[%x]\n", 255u));
	check("hex upper", printf("[%X]\n", 255u), ft_printf("[%X]\n", 255u));
	check("percent", printf("[%%]\n"), ft_printf("[%%]\n"));
	check("multiple", printf("%d %s %x\n", 42, "ok", 255u),
		ft_printf("%d %s %x\n", 42, "ok", 255u));
	return (0);
}
```

Compile and run:

```sh
make re
cc -Wall -Wextra -Werror -I. main.c libftprintf.a -o test
./test
```

#### Bonus `main.c`

```c
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static void	check(const char *name, int expected, int actual)
{
	printf("%-22s %s (%d / %d)\n", name,
		expected == actual ? "GOOD" : "FAIL", expected, actual);
}

int	main(void)
{
	int		value;
	void	*ptr;

	value = 42;
	ptr = &value;
	setvbuf(stdout, NULL, _IONBF, 0);
	check("left align", printf("[%-10d]\n", 42),
		ft_printf("[%-10d]\n", 42));
	check("zero padding", printf("[%010d]\n", -42),
		ft_printf("[%010d]\n", -42));
	check("plus", printf("[%+d]\n", 42), ft_printf("[%+d]\n", 42));
	check("space", printf("[% d]\n", 42), ft_printf("[% d]\n", 42));
	check("precision", printf("[%.5d]\n", 42),
		ft_printf("[%.5d]\n", 42));
	check("width precision", printf("[%10.5d]\n", 42),
		ft_printf("[%10.5d]\n", 42));
	check("zero precision", printf("[%.0d]\n", 0),
		ft_printf("[%.0d]\n", 0));
	check("hex prefix", printf("[%#08x]\n", 42u),
		ft_printf("[%#08x]\n", 42u));
	check("HEX prefix", printf("[%#10X]\n", 42u),
		ft_printf("[%#10X]\n", 42u));
	check("string precision", printf("[%-10.3s]\n", "Hello"),
		ft_printf("[%-10.3s]\n", "Hello"));
	check("char width", printf("[%5c]\n", 'A'),
		ft_printf("[%5c]\n", 'A'));
	check("INT_MIN", printf("[%+12d]\n", INT_MIN),
		ft_printf("[%+12d]\n", INT_MIN));
	check("pointer width", printf("[%20p]\n", ptr),
		ft_printf("[%20p]\n", ptr));
	check("pointer left", printf("[%-20p]\n", ptr),
		ft_printf("[%-20p]\n", ptr));
	check("NULL pointer width", printf("[%20p]\n", (void *)0),
		ft_printf("[%20p]\n", (void *)0));
	return (0);
}
```

Compile and run:

```sh
make fclean
make bonus
cc -Wall -Wextra -Werror -I. main.c libftprintf.a -o test
./test
```

## Algorithm and data structure

The main idea is to read the format string one character at a time.

1\. Normal characters are written directly and added to the output count.

2\. When the code encounters `%`, it reads the conversion specifier.

3\. A `va_list` is used to retrieve the next argument of the correct type.

4\. The appropriate printing function handles the argument.

5\. The total number of written characters is returned by `ft_printf()`.

Numbers are printed using a reusable base-conversion function. For instance,
decimal uses `0123456789`, while hexadecimal uses the corresponding set
of sixteen characters `0123456789ABCDEF`. This avoids writing separate conversion algorithms for
each numerical specifier.

In the bonus version, the format parser fills a `t_format` structure. It
stores the minimum width, precision, left alignment, zero padding, alternate
hexadecimal form, plus sign, space sign, calculated padding, selected sign and
specifier.

The bonus printing functions use these values to determine the number of
spaces or zeros required, then write the sign, optional prefix and value in
the correct order. Keeping the information in one structure makes it easier
to pass the selected formatting options between the parser and the printer.

The mandatory and bonus implementations share the basic output helpers and
the Libft functions. Their separate source files allow the Makefile to select
the required version without including both `ft_printf()` definitions in
the same archive.

## Resources

- The official 42 ****ft_printf**** subject, for required conversions, bonus flags

  and project rules.

- `man 3 printf` — format strings, conversions and return values.

- `man 3 stdarg` — variadic arguments (`va_list`, `va_start`, `va_arg`,

  `va_end`).

- My Libft project, for string and character output helpers.

### Use of AI

I used ChatGPT as a programming assistant for reviewing parts of the C code,
discussing formatting rules and character counting,organazing main.c file, and preparing an initial test program and README draft.
