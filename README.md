# push_swap

*This project has been created as part of the 42 curriculum by **dkryvono** and **callwood**.*

A 42 School project for sorting integers using two stacks and a restricted set of operations. The repository contains the mandatory `push_swap` program and the bonus `checker` program.

## Description

### Mandatory: `push_swap`

`push_swap` takes distinct signed integers as arguments and places them in stack A, with the first argument at the top. Stack B starts empty. The program prints a sequence of stack instructions to standard output that sorts A in ascending order while leaving B empty.

### Bonus: `checker`

`checker` accepts the same integer arguments, reads instructions from standard input (file descriptor `0`), applies them without echoing them, and prints:

- `OK` if A is sorted in ascending order and B is empty;
- `KO` if the instructions are valid but the final stacks are not in the required state;
- `Error` to standard error if the input or an instruction is invalid.

## Instructions

### Available operations

| Operation | Action |
| --- | --- |
| `sa`, `sb` | Swap the first two elements of A or B |
| `ss` | Execute `sa` and `sb` |
| `pa` | Push the top element of B onto A |
| `pb` | Push the top element of A onto B |
| `ra`, `rb` | Rotate A or B upward: the first element becomes the last |
| `rr` | Execute `ra` and `rb` |
| `rra`, `rrb` | Reverse-rotate A or B: the last element becomes the first |
| `rrr` | Execute `rra` and `rrb` |

An operation on a stack with too few elements has no effect.

### Build

Run these commands from the repository root:

```sh
make          # Build ./push_swap
make bonus    # Build ./checker
make clean    # Remove object files and build artifacts
make fclean   # Remove all generated files and libraries
make re       # Rebuild the mandatory program
```

Compilation uses `cc -Wall -Wextra -Werror`. The project also uses its local `ft_printf/libft` library and `get_next_line` implementation.

### Mandatory: examples

```sh
./push_swap 2 1 3
./push_swap 3 2 1
./push_swap "4 67 3 87 23"
./push_swap -3 0 2147483647 -2147483648
./push_swap 9515 1875 3117 2085 2137
```

All values must be distinct, valid signed 32-bit integers and correctly separated.

### Bonus: examples

The output from `push_swap` can be passed directly to `checker`:

```sh
./push_swap 3 2 1 | ./checker 3 2 1
./push_swap 9515 1875 3117 2085 2137 | ./checker 9515 1875 3117 2085 2137
```

`checker` can also receive instructions directly:

```sh
printf 'sa\n' | ./checker 2 1         # OK
printf '' | ./checker 2 1             # KO
printf 'invalid\n' | ./checker 2 1    # Error (stderr)
```

### Strategy and benchmark options

| Flag | Meaning |
| --- | --- |
| `--adaptive` | Choose a sorting strategy automatically (the default) |
| `--simple` | Force the simple strategy |
| `--medium` | Force the medium strategy |
| `--complex` | Force the complex strategy |
| `--bench` | Print sorting metrics to standard error |

Examples:

```sh
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive --bench 3 2 1
./push_swap --bench 9515 1875 3117 2085 2137 | ./checker 9515 1875 3117 2085 2137
```

Sorting instructions go to **stdout** (`fd 1`). The `--bench` report goes to **stderr** (`fd 2`), so it does not interfere with a pipeline to `checker`. The bonus `checker` does not accept strategy or benchmark flags.

## Sorting algorithms and implementation choices

Each integer is stored in a linked-list node. Before sorting, the program assigns a rank (`index`) based on ascending numerical order, which provides a consistent way to compare elements.

### Simple — Insertion sort (current)

The current simple strategy is a **stack-based adaptation of insertion sort**. Rather than repeatedly scanning A for its minimum, the algorithm takes the current element from the top of A and inserts it into the appropriate position in B.

The intended invariant is that **B remains sorted in descending order, from top to bottom**, after each insertion. To insert a value, the algorithm:

1. Examines the value at the top of A.
2. Rotates B with `rb` until the insertion position is reached.
3. Moves that value from A to B using `pb`.
4. Uses `rrb` to restore B's orientation after the insertion.
5. Once A is empty, returns all elements to A using `pa`, producing ascending order.


### Bubble sort (previous implementation, retained as commented code)

The earlier simple strategy used **bubble sort**, and its implementation has been retained as commented-out code in `ft_simple_sort.c` for reference.

Bubble sort repeatedly compares neighboring elements and swaps them when they are out of order. The stack adaptation used `sa` to swap the two values at the top of A and `ra` to move through the stack. It repeated passes until no swaps were required. These repeated rotations could result in a high instruction count, even for relatively low-disorder inputs.

Its average and worst-case complexity is **O(n²)**. The implementation remains a reference only and is **not the active simple strategy**.


### Medium — Chunk sort

The medium strategy sorts values in groups based on their assigned ranks. It transfers elements belonging to selected index ranges into B, then locates the highest remaining index in B, brings it to the top with rotations and pushes it back to A.

This is a **custom chunk-based strategy**, not a textbook bucket sort implementation. Its intended operation count is roughly **O(n√n)** with suitable chunk sizes, but this is a heuristic rather than a proven worst-case guarantee. For background on grouping-based algorithms.

### Complex — Quicksort (stack-based adaptation)

The complex strategy selects pivot values and partitions elements into smaller and larger groups, using push and rotate operations on A and B. It recursively processes the partitions, adapting the idea of quicksort to the restricted stack operations.

Conventional quicksort has average complexity **O(n log n)** and worst-case complexity **O(n²)**. These bounds do not directly guarantee the instruction count for this stack-based implementation.

### Adaptive — Strategy selection

The adaptive mode estimates the input's disorder and selects a strategy according to the implementation's thresholds:

| Disorder | Strategy |
| --- | --- |
| `0` | Already sorted; no operations needed |
| Greater than `0`, below `0.2` | Simple |
| `0.2` to below `0.5` | Medium |
| `0.5` and above | Complex |

Explicit `--simple`, `--medium` and `--complex` flags override adaptive selection.

### Disorder calculation

**Disorder** is the fraction of inversions in the input relative to the maximum possible number of pairs. An inversion occurs when an earlier element is greater than a later element.

For `n` distinct elements:

```text
total_pairs = n * (n - 1) / 2
disorder = inversions / total_pairs
```

For example, in `3 1 2`, two of the three pairs are inversions: `(3, 1)` and `(3, 2)`. Therefore, `disorder = 2 / 3 ≈ 0.667`. An ascending input has disorder `0`; a descending input has disorder `1`. For fewer than two elements, the implementation returns `0` to avoid division by zero.

With `--bench`, the program reports the initial disorder, selected strategy and counts of individual stack operations to stderr.

## Bonus checker implementation

The bonus program initializes A with the input integers and B as empty, then reads one operation per line using `get_next_line(0)`.

Its instruction dispatcher recognizes the full supported operation names and executes the corresponding silent internal stack functions. An invalid instruction produces `Error` on stderr. At end of input, it prints `OK` only if B is empty and A is sorted; otherwise, it prints `KO`.

Unlike the mandatory program, the checker neither chooses a sorting strategy nor allocates benchmark options.

## Project structure

| Path | Purpose |
| --- | --- |
| `main.c`, `ft_push_swap.c` | Mandatory entry point, setup and benchmark output |
| `ft_allocate.c`, `ft_parse_number.c`, `ft_support.c` | Argument parsing, allocation and shared helpers |
| `ft_sort.c`, `ft_simple_sort.c` | Strategy dispatch and simple sorting algorithm |
| `ft_medium_sort.c`, `ft_complex_sort.c`, `ft_complex_partition.c` | Medium and complex sorting strategies |
| `ft_swap.c`, `ft_push.c`, `ft_rotate.c`, `ft_reverse_rotate.c` | Stack operations shared with the checker |
| `fd_push_swap_bonus.c`, `fd_push_swap_bonus.h` | Bonus entry point and result check |
| `ft_checker_init_bonus.c`, `ft_checker_execute_bonus.c`, `ft_checker_ops_bonus.c` | Bonus initialization and instruction execution |
| `ft_printf/`, `get_next_line/` | Local support libraries |
| `Makefile` | Separate mandatory and bonus build targets |

## Resources

- [42 School push_swap subject](https://github.com/42School) — project requirements (this project uses subject version 1.2).
- [Insertion sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort).
- [Bubble sort — Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort).
- [Quicksort — Wikipedia](https://en.wikipedia.org/wiki/Quicksort).
- 42 School **Norminette** coding convention.

**AI usage:** ChatGPT was used to review code, discuss algorithmic choices and debugging, and help draft and format this README. Code and explanations must be reviewed and understood by the project authors.

## Project Distribution

`callwood`

-   sorting rules (sa, sb, ss, pa, pb , ...)
-   header with the linked list struct
-   medium sorting
-   make file
-   filing the stack

`dkryvono`

-   parsing 
-   bonus
-   bench flag
-   simple sorting
-   complex sorting
-   filing the stack

## Authors

- `dkryvono`
- `callwood`
