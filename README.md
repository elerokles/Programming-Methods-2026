# C Programming Language Exercises & Solutions
- **Student ID**: 2026XXXXX  <!-- TODO: fill in -->
- **Name**: YOUR NAME  <!-- TODO: fill in -->
- **Department**: Dept. of Game / International College, Dongseo University
- **Environment**: Windows 11, Visual Studio 2022 / MSVC Compiler

---

## 📂 Chapters Overview
- [x] **ch1**: Tutorial Introduction (Variables, for loops, symbolic constants, functions)
- [x] **ch2**: Types, Operators & Expressions (Data types, bitwise operators, type conversion)
- [x] **ch3**: Control Flow (if-else, switch, loops, break & continue)
- [x] **ch4**: Functions & Program Structure (External variables, scope rules, header files)
- [x] **ch5**: Pointers & Arrays (Pointer arithmetic, swap, line sort, CLI arguments)

File names start with a number (order in the chapter) and, for textbook
exercises, the exercise number (e.g. `ex1-13` = Exercise 1-13).

### ch1 – Tutorial Introduction
| File | Section / Exercise | What it does |
|------|--------------------|--------------|
| `01_ex1-1_hello_world.c` | 1.1, Ex 1-1 | Prints "hello, world" |
| `02_ex1-3_fahrenheit_celsius_table.c` | 1.2, Ex 1-3 | Fahrenheit→Celsius table with a heading |
| `03_ex1-4_celsius_fahrenheit_table.c` | 1.2, Ex 1-4 | Celsius→Fahrenheit table |
| `04_ex1-5_reverse_temperature_table.c` | 1.3–1.4, Ex 1-5 | Table from 300 down to 0 with `for` and `#define` |
| `05_word_count.c` | 1.5.4 | Counts lines, words, characters (state variable) |
| `06_ex1-8_count_blanks_tabs_newlines.c` | 1.5.3, Ex 1-8 | Counts blanks, tabs and newlines |
| `07_count_digits_whitespace_array.c` | 1.6 | Counts each digit, white space, others with an array |
| `08_ex1-13_word_length_histogram.c` | 1.6, Ex 1-13 | Horizontal and vertical histogram of word lengths |
| `09_power_function.c` | 1.7–1.8 | `power(m, n)` and call by value |
| `10_ex1-15_temperature_conversion_function.c` | 1.7, Ex 1-15 | Temperature table using a conversion function |
| `11_longest_line.c` | 1.9 | Prints the longest input line |
| `12_ex1-17_print_lines_over_80_chars.c` | 1.9, Ex 1-17 | Prints lines longer than 80 characters |
| `13_ex1-19_reverse_lines.c` | 1.9, Ex 1-19 | `reverse(s)`, reverses each input line |
| `14_ex1-20_detab.c` | 1.9, Ex 1-20 | Replaces tabs with blanks up to the next tab stop |
| `15_longest_line_extern.c` | 1.10 | Longest line using external (global) variables |

### ch2 – Types, Operators & Expressions
| File | Section / Exercise | What it does |
|------|--------------------|--------------|
| `01_ex2-1_type_ranges.c` | 2.2, Ex 2-1 | Ranges of char/short/int/long/float/double, from headers and computed |
| `02_leap_year.c` | 2.5–2.6 | Leap year test with `%`, `&&`, `\|\|` |
| `03_ex2-3_htoi.c` | 2.7, Ex 2-3 | `htoi(s)`: hex string (optional 0x) → integer |
| `04_ex2-4_squeeze.c` | 2.8, Ex 2-4 | `squeeze(s, c)` and `squeeze2(s1, s2)` |
| `05_ex2-5_any.c` | 2.8, Ex 2-5 | `any(s1, s2)`: first position of any char of s2 in s1 |
| `06_ex2-6_2-7_2-8_bit_operations.c` | 2.9, Ex 2-6/2-7/2-8 | `setbits`, `invert`, `rightrot` |

### ch3 – Control Flow
| File | Section / Exercise | What it does |
|------|--------------------|--------------|
| `01_binary_search.c` | 3.3 | Binary search with else-if |
| `02_count_digits_switch.c` | 3.4 | Digit / white space counting with `switch` |
| `03_ex3-2_escape_unescape.c` | 3.4, Ex 3-2 | `escape` / `unescape` for `\n` and `\t` |
| `04_itoa_do_while.c` | 3.6 | `itoa(n, s)` with do-while and `reverse` |
| `05_trim_break_continue.c` | 3.7 | `trim` with `break`, summing with `continue` |
| `06_goto_nested_loops.c` | 3.8 | `goto` to leave two nested loops |

### ch4 – Functions & Program Structure
| File | Section / Exercise | What it does |
|------|--------------------|--------------|
| `01_pattern_search_ould.c` | 4.1 | Prints input lines containing "ould" (`strindex`) |
| `02_ex4-1_strrindex.c` | 4.1, Ex 4-1 | `strrindex(s, t)`: rightmost occurrence (answer 7) |
| `03_rpn_calculator.c` | 4.3 | Reverse Polish calculator in one file |
| `04_rpn_calculator_negative_numbers.c` | 4.3 | Calculator that also reads negative numbers |
| `05_ex4-5_calculator_math_functions/` | 4.4–4.5, Ex 4-5 | Calculator split into `main.c`, `stack.c`, `getop.c`, `getch.c`, `calc.h`; adds `sin`, `cos`, `exp`, `pow` |
| `06_preprocessor_macros.c` | 4.11 | `#define` macros, `#ifdef DEBUG`, `#if/#elif/#else` |

### ch5 – Pointers & Arrays
| File | Section / Exercise | What it does |
|------|--------------------|--------------|
| `01_pointer_basics.c` | 5.1 | `&` and `*`, and the trace exercise from the slides |
| `02_swap_call_by_reference.c` | 5.2 | Wrong swap (call by value) vs. `swap(&a, &b)` |
| `03_getint.c` | 5.2 | `getint(&n)`: reads integers from input through a pointer |
| `04_pointers_and_arrays.c` | 5.3 | `a[i]` vs. `*(pa+i)`, pointer version of strlen |
| `05_string_copy_compare.c` | 5.4 | Array vs. pointer strings, pointer `strcpy` and `strcmp` |
| `06_ex5-3_strcat.c` | 5.4, Ex 5-3 | Pointer version of `strcat(s, t)` |
| `07_ex5-4_strend.c` | 5.4, Ex 5-4 | `strend(s, t)`: 1 if t is at the end of s |
| `08_ex5-5_strncpy_strncat_strncmp.c` | 5.4, Ex 5-5 | Own versions of `strncpy`, `strncat`, `strncmp` |
| `09_ex5-6_pointer_versions.c` | 5.4, Ex 5-6 | getline, atoi, itoa, reverse, strindex rewritten with pointers |
| `10_sort_lines_alloc.c` | 5.6 | Sorts input lines with a pointer array, quicksort and `alloc` |
| `11_ex5-7_sort_lines_linestor.c` | 5.6, Ex 5-7 | Same, storing lines in `linestor[]` supplied by main |
| `12_malloc_calloc.c` | Dynamic memory | `malloc`, `calloc`, `free` |
| `13_ex5-8_day_of_year_error_check.c` | 5.7, Ex 5-8 | `day_of_year` / `month_day` with a 2D array and error checking |
| `14_month_name_pointer_array.c` | 5.8–5.9 | `month_name(n)`, pointer array vs. 2D array |
| `15_echo_command_line_args.c` | 5.10 | `echo`: prints `argv` |
| `16_find_pattern_args.c` | 5.10 | `find -x -n pattern` using `argc`/`argv` and `strstr` |

---

## 🛠 How to Compile & Run
Add a file to an empty Visual Studio 2022 project and press Ctrl+F5, or compile from the Developer Command Prompt:
```cmd
cl ch1\01_ex1-1_hello_world.c
01_ex1-1_hello_world.exe
```
Multi-file program (ch4 Ex 4-5):
```cmd
cl /Fe:calc.exe ch4\05_ex4-5_calculator_math_functions\*.c
calc.exe
```
Programs with command-line arguments (ch5):
```cmd
cl ch5\16_find_pattern_args.c
16_find_pattern_args.exe -n ould < input.txt
```
Programs that read input stop at end-of-file: press **Ctrl+Z** then **Enter** on Windows.
