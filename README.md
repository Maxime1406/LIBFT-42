*This project has been created as part of the 42 curriculum by mbardeau*

# Libft - 42 Project

## Description
**Libft** is the first project of the 42 school's common core. The main objective is to recode a set of functions from the standard C library (`libc`), as well as additional utility functions and linked list manipulation functions. This project helps build solid foundations in C programming, in memory management, and creates a static library (`libft.a`) that can be reused for future projects in the curriculum.

---

## Instructions

### Prerequisites

- A C compiler (`cc`)
- The compilation utility `make`
- A Unix / Linux or WSL environment

### Compilation and Makefile Rules
At the root of the project you can use the following commands:
* **`make`** : Compiles the source files and generates the static library **`libft.a`**.
* **`make clean`** : Deletes the objects files (`.o`).
* **`make fclean`** : Deletes the objects files and the `libft.a` library.
* **`make re`** : Performs an `fclean` followd by a `make` to recompile everything from scratch.

---

## Detailed Description of the Library

### 1. Part 1 : Libc Functions

#### Character classification (`<ctype.h>`)
* **`ft_isalpha`** : Verify if a character is alphabetic (a/A to z/Z).
* **`ft_isdigit`** : Verify if a character is a digit (0 through 9).
* **`ft_isalnum`** : Verify if a character is alphanumeric.
* **`ft_isascii`** : Verify if a character belongs to the ASCII table.
* **`ft_isprint`** : Verify if a character is printable.

#### Case conversion
* **`ft_toupper`** : Convert a lowercase character to an uppercase one.
* **`ft_tolower`** : Convert an uppercase character to a lowercase one.

#### String manipulation (`<string.h>`)
* **`ft_strlen`** : Calcul the length of a string of characters.
* **`ft_strchr`** : Search for the first occurence of a character in a string.
* **`ft_strrchr`** : Search the last occurence of a character in a string.
* **`ft_strncmp`** : Compare two strings of characters up to `n` bytes.
* **`ft_strnstr`** : Search for the first occurence of a substring in a string, up to a maximum length.
* **`ft_strlcpy`** : Copies a string of characters with a limited and secure size.
* **`ft_strlcat`** : Concatenates two strings of characters safely.
* **`ft_strdup`** : Duplicates a string of characters by allocatins the necessary memory.

#### Memory manipulation
* **`ft_memset`** : Fills the first bytes of a memory area with a constant value.
* **`ft_bzero`** : Sets the first bytes of a memory area to zero.
* **`ft_memcpy`** : Copies bytes from a source memory area to a destination memory area.
* **`ft_memmove`** : Copies bytes from a source to a destination, handling overlapping memory areas correctly.
* **`ft_memchr`** : Searches for the first occurrence of a byte in a memory area.
* **`ft_memcmp`** : Compares two memory areas.

#### Allocation and conversion
* **`ft_calloc`** : Allocates memory and initializes its bytes to zero.
* **`ft_atoi`** : Converts a string of characters to an integer (`int`).

---

### 2. Part 2 : Additionnal Functions
* **`ft_substr`** : Allocates (with `malloc()`) and returns a string of characters derived from the string `s`. This new string starts at index `start` and has a maximum size of `len`.
* **`ft_strjoin`** : Allocates (with `malloc()`) and returns a new string, result of the concatenation of `s1` and `s2`.
* **`ft_strtrim`** : Allocates (with `malloc()`) and returns a copy of the string `s1`, without the characters specified in `set` at the beginning and at the end of the string of characters.
* **`ft_split`** : Allocates (with `malloc()`) and returns an array of strings of characters obtained by separating `s` using the character `c`, used as delimiter. The array must be terminated by `NULL`. 
* **`ft_itoa`** : Allocates (with `malloc()`) and returns a string of characters representing the integer `n` received as argument. Negative numbers must be handled.
* **`ft_strmapi`** : Applies the function `f` to each character of the string of characters passed as argument to create a new string of characters (with `malloc()`) resulting from successive applications of `f`.
* **`ft_striteri`** : Applies the function `f` to each character of the string of characters transmitted as argument, and by passing its index as first argument. Each character is transmitted by address to `f` in order to be modified if necessary.
* **`ft_putchar_fd`** : Write the `c` character to the given file descriptor.
* **`ft_putstr_fd`** : Write the `s` string to the given file descriptor.
* **`ft_putendl_fd`** : Write the `s` string to the given file descriptor followed by a new line. 
* **`ft_putnbr_fd`** : Write the `n` int to	 the given file descriptor.

---

### 3. Part 3 : Linked list
* **`ft_lstnew`** : Allocates (with `malloc()`) and return a new element. The member variable `content` is initialized using the value of the parameter `content`. The variable `next` is initialized to `NULL`. 
* **`ft_lstadd_front`** : Adds the element `new` at the beginning of the list.
* **`ft_lstsize`** : Count the number of elements in the list.
* **`ft_lstlast`** : Returns the last element of the list.
* **`ft_lstadd_back`** : Adds the element `new` at the end of the list.
* **`ft_lstdelone`** : Frees the memory of the element passed as argument using the function `del` then with `free()`. The memory of `next` must not be freed.
* **`ft_lstclear`** : Deletes and frees the memory of the element passed as parameter, and of all the elements that follow, using `del` and `free()`. Finally, the initial pointer must be set to `NULL`.
* **`ft_lstiter`** : Iterates over the list `lst` and applies the function `f` to the content of each element.
* **`ft_lstmap`** : Iterates over the list `lst` and applies the function `f` to the content of each element. Creates a new list resulting from the successive applications of `f`. The function `del` is there to destroy the content of an element if necessary.

---

## Resources
* Official C documentation (`man`)
* Geeksforgeeks.org for Libc functions, hints for differences (malloc/calloc) and use examples.
* Official 42 Libft subject
* **AI Usage:** Artificial intelligence was used to learn/understand how linked lists work with some examples and create a special main to make more differents tests than my actual one.