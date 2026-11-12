*This project has been created as part of the 42 curriculum by dkryvono.*

# Libft

## Description

Libft is my first C library project at 42. Its goal is to build a reusable collection of functions for working with input data, strings, memory and linked lists. These tools allow a program to inspect, modify, copy, compare, split, join, convert, allocate, release and output data.

The project is divided into three parts:

- **Part 1: Libc functions.** Reimplementations of familiar C library functions for character checks, string manipulation, memory operations, conversion and allocation.

- **Part 2: Additional functions.** Utilities for creating and transforming strings, splitting and joining data, applying callback functions and writing output to file descriptors.

- **Part 3: Linked lists.** Functions that create, traverse, modify and delete nodes in a singly linked list.

The functions are compiled into a static library named `libft.a`. Other C programs can link against this library instead of copying its source files.

## Instructions

Use a Unix-like environment with a C compiler (`cc`), `make` and `ar`.

```sh
make          # Build libft.a with all 43 functions
make all      # Same build
make clean    # Remove object files
make fclean   # Remove object files and libft.a
make re       # Rebuild all three parts
```

The Makefile compiles with `-Wall -Wextra -Werror` and creates `libft.a` in the repository root. Repeating `make` without changing dependencies does not rebuild the archive.

Include `libft.h` in a client program, then link the static library after the client source or object:

```sh
cc -Wall -Wextra -Werror -I. main.c libft.a -o test
./test
```

To check source formatting with the official Norminette installation:

```sh
norminette -R CheckForbiddenSourceHeader
```

### Part 1:

`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`.

### Part 2:

`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

### Part 3:

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Resources

- The Libft project subject provided by 42, for the required functions and project rules.
- I used ChatGPT as a coding tutor while learning C. My guiding prompt was:

  > You are a coding teacher. Your task is to give me advice and explain C programming topics that I do not understand. If I ask you to explain a piece of code or help me solve a task, do not simply give me the solution. Explain the reasoning from different perspectives so that I can understand how to approach it. Cover each topic thoroughly.

## Example test program

```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

static int g_passed;
static int g_total;

static void check(const char *name, int ok)
{
    g_total++;
    g_passed += (ok != 0);
    printf("%-19s %s\n", name, ok ? "GOOD" : "FAIL");
}

static char map_upper(unsigned int i, char c)
{
    (void)i;
    return ((char)ft_toupper(c));
}

static void iter_upper(unsigned int i, char *c)
{
    (void)i;
    *c = (char)ft_toupper(*c);
}

static void iter_list_upper(void *content)
{
    char *s = content;
    while (*s)
    {
        *s = (char)ft_toupper(*s);
        s++;
    }
}

static void *map_list_upper(void *content)
{
    char *copy;
    size_t i;

    copy = ft_strdup((char *)content);
    if (!copy)
        return (NULL);
    i = 0;
    while (copy[i])
    {
        copy[i] = (char)ft_toupper(copy[i]);
        i++;
    }
    return (copy);
}

static void test_part1(void)
{
    char a[32];
    char b[32];
    char overlap[16] = "abcdef";
    char *dup;
    void *p;

    puts("\nPART 1");
    check("ft_isalpha", ft_isalpha('A') && !ft_isalpha('7'));
    check("ft_isdigit", ft_isdigit('7') && !ft_isdigit('z'));
    check("ft_isalnum", ft_isalnum('a') && ft_isalnum('5') && !ft_isalnum('#'));
    check("ft_isascii", ft_isascii(127) && !ft_isascii(128));
    check("ft_isprint", ft_isprint(' ') && !ft_isprint('\n'));
    check("ft_strlen", ft_strlen("hello") == 5);
    ft_memset(a, 'x', 4);
    check("ft_memset", a[0] == 'x' && a[3] == 'x');
    ft_bzero(a, 4);
    check("ft_bzero", a[0] == 0 && a[3] == 0);
    ft_memcpy(a, "hello", 6);
    check("ft_memcpy", strcmp(a, "hello") == 0);
    ft_memmove(overlap + 2, overlap, 4);
    check("ft_memmove", strcmp(overlap, "ababcd") == 0);
    check("ft_strlcpy", ft_strlcpy(a, "hello", 4) == 5 && strcmp(a, "hel") == 0);
    ft_strlcpy(b, "hi", sizeof(b));
    check("ft_strlcat", ft_strlcat(b, "there", sizeof(b)) == 7 && strcmp(b, "hithere") == 0);
    check("ft_toupper", ft_toupper('a') == 'A');
    check("ft_tolower", ft_tolower('Z') == 'z');
    check("ft_strchr", ft_strchr("abc", 'b') && *ft_strchr("abc", 'b') == 'b');
    check("ft_strrchr", ft_strrchr("abca", 'a') && ft_strrchr("abca", 'a')[1] == '\0');
    check("ft_strncmp", ft_strncmp("abc", "abd", 2) == 0 && ft_strncmp("abc", "abd", 3) < 0);
    check("ft_memchr", ft_memchr("hello", 'l', 5) && *(char *)ft_memchr("hello", 'l', 5) == 'l');
    check("ft_memcmp", ft_memcmp("abc", "abc", 3) == 0 && ft_memcmp("abc", "abd", 3) < 0);
    check("ft_strnstr", ft_strnstr("hello world", "world", 11) && !ft_strnstr("hello world", "world", 8));
    check("ft_atoi", ft_atoi("  -42x") == -42);
    p = ft_calloc(3, sizeof(int));
    check("ft_calloc", p && ((int *)p)[0] == 0 && ((int *)p)[2] == 0);
    free(p);
    dup = ft_strdup("hello");
    check("ft_strdup", dup && strcmp(dup, "hello") == 0);
    free(dup);
}

static void test_part2(void)
{
    char *s;
    char **words;
    char text[] = "hello";
    int ok;

    puts("\nPART 2");
    s = ft_substr("hello", 1, 3);
    check("ft_substr", s && strcmp(s, "ell") == 0);
    free(s);
    s = ft_strjoin("hello", " world");
    check("ft_strjoin", s && strcmp(s, "hello world") == 0);
    free(s);
    s = ft_strtrim("  hello  ", " ");
    check("ft_strtrim", s && strcmp(s, "hello") == 0);
    free(s);
    words = ft_split("one,,two,three", ',');
    ok = words && words[0] && words[1] && words[2] && !words[3];
    if (ok)
        ok = !strcmp(words[0], "one") && !strcmp(words[1], "two") && !strcmp(words[2], "three");
    check("ft_split", ok);
    if (words)
    {
        int i;

        i = 0;
        while (words[i])
        {
            free(words[i]);
            i++;
        }
        free(words);
    }
    s = ft_itoa(INT_MIN);
    check("ft_itoa", s && strcmp(s, "-2147483648") == 0);
    free(s);
    s = ft_strmapi("hello", map_upper);
    check("ft_strmapi", s && strcmp(s, "HELLO") == 0);
    free(s);
    ft_striteri(text, iter_upper);
    check("ft_striteri", strcmp(text, "HELLO") == 0);
    puts("The next four functions print output to stdout:");
    printf("ft_putchar_fd: "); ft_putchar_fd('X', 1); ft_putchar_fd('\n', 1);
    printf("ft_putstr_fd: "); ft_putstr_fd("Hello\n", 1);
    printf("ft_putendl_fd: "); ft_putendl_fd("Hello", 1);
    printf("ft_putnbr_fd: "); ft_putnbr_fd(-42, 1); ft_putchar_fd('\n', 1);
    puts("Inspect the four output lines above manually.");
}

static void test_part3(void)
{
    t_list *list;
    t_list *node;
    t_list *mapped;
    int ok;

    puts("\nPART 3");
    list = ft_lstnew(ft_strdup("two"));
    check("ft_lstnew", list && list->content && !list->next);
    if (!list)
        return ;
    node = ft_lstnew(ft_strdup("one"));
    if (node)
        ft_lstadd_front(&list, node);
    check("ft_lstadd_front", node && list == node && list->next != NULL);
    check("ft_lstsize", ft_lstsize(list) == (node ? 2U : 1U));
    check("ft_lstlast", ft_lstlast(list) && strcmp(ft_lstlast(list)->content, "two") == 0);
    node = ft_lstnew(ft_strdup("three"));
    if (node)
        ft_lstadd_back(&list, node);
    check("ft_lstadd_back", node && ft_lstlast(list) == node);
    node = ft_lstnew(ft_strdup("delete"));
    ok = node && node->content;
    if (node)
        ft_lstdelone(node, free);
    check("ft_lstdelone", ok);
    ft_lstiter(list, iter_list_upper);
    check("ft_lstiter", list->content && strcmp(list->content, "ONE") == 0);
    mapped = ft_lstmap(list, map_list_upper, free);
    ok = mapped && mapped->content && strcmp(mapped->content, "ONE") == 0;
    check("ft_lstmap", ok);
    ft_lstclear(&mapped, free);
    check("ft_lstclear", mapped == NULL);
    ft_lstclear(&list, free);
}

int main(void)
{
    test_part1();
    test_part2();
    test_part3();
    printf("\nSummary: %d/%d automatic checks passed.\n", g_passed, g_total);
    return (g_passed == g_total ? 0 : 1);
}
```
