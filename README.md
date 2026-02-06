# README.md - Push Swap Project

*This project has been created as part of the 42 curriculum by pcaudron, brouzaud.*

## Description

__Push_Swap__ is a program which permits to sort in ascending number a set of integer in the most optimal way using only two stacks, one containing a random amount of negative and/or positive numbers without any duplicate and the other stack is empty, and operations to manipulate the stacks. It can sort depending of the disorder of the set of integers. The disorder defines how much of the set is already sorted. Depending of the value of the disorder the sorting algorithm will change to optimize the number of operations required.

## Instructions

### Compilation

The project includes a **Makefile** with the following rules:

```
make       # Compiles the program
make all   # Same as above
make clean # Removes object files
make fclean # Removes all generated files
make re    # Recompiles the entire project from scratch
make gdb   # Compiles gdb with arguments
make val   # Same as above with valgrind
make run   # Run the program with the chosen flags and arguments
make shuf  # Compiles the program with a random set of number with a given size and flags
```

### Compilation Flags

All source files are compiled with:
- `-Wall -Wextra -Werror -ggdb` flags for strict error checking
- `cc` compiler
- `--simple --medium --complex --adaptive` flags to define which sorting algorithm to use
- `--bench` flag to display the benchmark 
- No relinking on subsequent builds

## Project Structure

We have lots of utils functions from the previous modules.

| Functions | Description |
| -------- |:------- |
| `complex_algo`  |**Uses the radix sort algorithm O(n log n). Sorts a set using keys. For example, for an integers set, the first key can be the units digit. It sorts the number based on the units digit. the second key will be the tens digits.  Here we play with the bits to define the keys. We don't use the digits but the bits and sort them untils we reach the bit max which is the bit of the highest index. After the last bits the list is sorted** |
| `medium_algo` | **Uses the bucket sort algorithm O(n√n). Sorts a set by partitioning in sub sets. Divide the set in √n sub-sets, sort in each sub-sets, and then extract the numbers from each sub-sets in the right order**. |
| `simple_algo` |**Uses the selection sort algorithm O(n2). Sorts by traveling through the set and search the minimal element and put it in first place. Then start again from the next index to seek the second minimal number in the set, and so on until the whole set is sorted.**. |
| `push` |**pa takes the number at the top of b and put it at the top of a. If b is empty nothing happens. The other way around with pb**. |
| `rotate` |**Shift up all elements of a stack by one, the first becomes the last**. |
| `reverse rotate` |**Acts in the same way as rotate but the shift is reversed, the last becomes the first**. |
| `swap` |**Swap the first two elements at the top of a stack, do nothing if there is only one or no elements**. |
| `disorder` |**Calculate the disorder, between 0 and 1, of the set given. It indicates how much it's sorted. 0 is sorted, 1 is the least sorted**. |
| `strategy_select` |**Determines which algorithm is going to be used depending on the flags used: --simple, --medium, --complex or --adaptive (which choose the optimal algorithm depending on the value of the disorder)**. |
| `bench` | **For the --bench flag; displays the computer disorder (in percent), the name of the strategy used and its theorical complexity class, the total number of operations, the count of each operation type (pa, pb, ra, rra, rb, rrb, ...)**. |
| `parsing`  |**Parse the given command to separate the flags and the integers, stocks the integers into a list and check for duplicates** |

## Resources

### Learning References

- **W3Schools C Reference** — Comprehensive documentation on C language fundamentals and standard functions
- **GeeksforGeeks C Tutorials** — Detailed articles on variadic functions
- **Official C Standard Library (man pages)** — Authoritative source for standard function behavior

### AI Usage Disclosure

AI wasn't used in this project.

## Notes

### Work distribution

brouzaud : medium algo, bench, parsing, push, rotate, reverse_rotate, swap, makefile.

pcaudron : simple algo, complex algo, sort_tools, strategy_select, disorder, readme.

### Explanation and Justification of Algorithm and Data Structure

We chose the different algorithms based on our competences and level. They seemed to be the most useful and efficient without being to difficult to understand and code.
