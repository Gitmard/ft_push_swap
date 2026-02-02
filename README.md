*This project has been created as part of the 42 curriculum by smenard, vquetier*

# push_swap
> Because swap_push doesn't feel as natural

Push_swap is the first group project of the 42 Common Core. Its goal is to introduce the concept of algorithmic complexity.

## Description
This project is a C program that generates a set of instructions to sort a list of unique integers using only two stacks.

### Instruction Set

```
sa # "swap a" - Swap the first two elements at the top of stack a
sb # "swap b" - Swap the first two elements at the top of stack b
ss # Execute sa and sb simultaneously

pa # "push a" - Take the top element of b and put it at the top of a
pb # "push b" - Take the top element of a and put it at the top of b

ra # "rotate a" - Shift all elements of stack a up by one (first element becomes last)
rb # "rotate b" - Shift all elements of stack b up by one (first element becomes last)
rr # Execute ra and rb simultaneously

rra # "reverse rotate a" - Shift all elements of stack a down by one (last element becomes first)
rrb # "reverse rotate b" - Shift all elements of stack b down by one (last element becomes first)
rrr # Execute rra and rrb simultaneously
```

## Getting Started
Although this project will likely never suit a real use case, it can be fun to experiment with. To visualize the generated instruction set, we recommend using the excellent [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) created by o-reo.
> This visualizer was built for an older version of the push_swap project and does not fully support the multi-strategy version. To visualize a specific algorithm, modify the main function in the `push_swap.c` file located in the `src` folder and call either the simple, medium, or complex function.

### Compilation

This project uses make for compilation.

To compile the project into an executable called `push_swap`:

`make` or `make [all/push_swap]`

To delete all compiled files except the executable:

`make clean`

To delete all compiled files including the executable:

`make fclean`

To fully recompile the project:

`make re`
> `make re` is equivalent to `make fclean [all/push_swap]`

### Usage

The push_swap program takes a list of integers as arguments and writes the generated instructions to the standard output. Executing these instructions on a stack pair with stack a filled with the input integers will result in stack a containing the sorted numbers.

#### Additional Arguments
You can choose the sorting strategy using these dedicated flags:
```
--simple   # Simple strategy with O(n²) time complexity
--medium   # Medium strategy with O(n√n) time complexity
--complex  # Complex strategy with O(n log n) time complexity
--adaptive # Automatic strategy that selects the algorithm based on the input list's disorder
```
If no strategy flag is provided, the push_swap program will **default to adaptive mode**.

The push_swap project also features a benchmark mode that outputs performance metrics to stderr.

The benchmark is written to stderr to avoid interfering with programs reading the instructions from stdout.

The benchmark displays the following information:
- Total number of instructions generated
- Count of each instruction type in the generated set
- Strategy used and its time complexity class
- Computed disorder metric of the input list

Add the `--bench` flag to enable this feature.

#### Argument Rules

The parsing logic supports two input formats:
- Each number as a separate argument
- All numbers in a single argument, separated by spaces

All numbers must be **unique** and fit within the **32-bit signed integer range** (-2,147,483,648 to 2,147,483,647).

### Project Structure

If you explore the source code, you might find the structure somewhat over-engineered for such a seemingly straightforward project. However, upon closer inspection, you'll see that every line of code serves a purpose and that the structure follows a coherent vision. The different components of the project are organized into their own modules, sometimes containing sub-modules.

Here is the module structure to help you navigate the codebase:
```
── src
    ├── algo         # Algorithm module containing the different strategy implementations
    │   ├── complex
    │   ├── headers
    │   ├── medium
    │   └── simple
    ├── bench        # Benchmark feature sources
    ├── instructions # Instruction implementation sources
    ├── lib          # Internal library
    │   ├── hash_set      # Custom hash_set implementation, definitely worth a look
    │   ├── list          # Linked list utility functions
    │   ├── math          # Simple math functions (min, max, sqrt)
    │   ├── mem           # Memory utilities (calloc, memset)
    │   ├── printf        # Custom printf implementation
    │   ├── stack         # Stack utility functions
    │   ├── string        # String utility functions
    │   └── utils         # Generic utility functions
    └── parse        # Argument parsing sources
```

#### Custom Types
This project uses several C structures. Here are the most important ones:

```c
typedef struct s_list
{
        struct s_list   *next;
        struct s_list   *prev;
        int             value;
        uint32_t        target_index; // The index of the element after sorting
}                       t_list;
```

```c
typedef struct s_stack
{
        t_list    *head;
        t_list    *tail;
        size_t    size;
}                 t_stack;
```

```c
typedef struct s_stacks
{
        t_stack    *a;
        t_stack    *b;
        size_t     combined_sizes;
        t_op       op;    // Count of each instruction type
        int        flags; // Bitwise flags for strategy, bench mode, etc.
}                  t_stacks;
```

These structures are defined in `src/lib/headers/lib_defines.h`.

## Resources
Very few external resources were used for this project. Although we did not invent custom algorithms, we implemented well-known algorithms on our own.

## AI Use
AI was used through Copilot during code reviews and for the creation of this README.

## Algorithmic Strategies
The push_swap project implements three different algorithmic strategies. We adapted popular sorting algorithms to work within the push_swap constraints.

### Simple Strategy - Greedy Insertion Sort

The simple strategy uses a **greedy cost-based approach** to progressively build a sorted stack.
The algorithm begins by pushing all elements from stack **A** to stack **B**. Then, it iteratively reinserts elements from B back into A at their correct sorted position.

For each iteration:
- The algorithm evaluates every element in stack B
- For each element, it calculates the cost to insert it into its correct position in stack A
- The cost includes: rotations needed in stack B to bring the element to the top, rotations needed in stack A to position it correctly, and optimizations from combined rotations (`rr`/`rrr`)
- The element with the lowest total cost is selected and pushed to stack A

The correct position in A is determined by finding the slot where the element fits between its predecessor and successor values. Edge cases (minimum/maximum values) are handled specially to maintain circular ordering.

Once all elements are back in stack A, a final reordering step rotates the stack to place the minimum value at the top.

This greedy approach results in an average complexity of **O(n²)**, as each element may require evaluating and rotating through the entire stack.

#### Why This Strategy?

The greedy insertion sort is particularly well-suited for the push_swap constraints. A naive insertion sort implementation would generate **O(n³) instructions**: for each of the n elements, finding the insertion position requires O(n) comparisons, and each insertion requires O(n) rotations.

By leveraging the cost-based greedy selection and the dual-rotation optimizations (`rr`/`rrr`), our implementation reduces this to **O(n²) instructions**. The key insight is that we can minimize the total number of moves by always choosing the cheapest element to insert next, rather than processing elements in a fixed order.

This makes it an excellent baseline strategy for small to medium-sized inputs where the overhead of more complex algorithms outweighs their theoretical advantages.

### Medium Strategy - Bucket Sort

The medium strategy uses a **bucket-based approach** relying on each element's `target_index`.
The idea is to split the index range into sliding windows of size √n and progressively move elements from stack **A** to stack **B**.

For each window:
- The algorithm locates the closest element in stack A whose `target_index` is inside the current window
- It rotates in the optimal direction (`ra` or `rra`) to bring that element to the top
- The element is pushed to stack B
- Elements in the lower half of the window are rotated inside B to partially maintain order

Once all elements are pushed into B, they are reinserted into A in decreasing `target_index` order by rotating B in the shortest direction and using `pa`.

This approach significantly reduces unnecessary rotations compared to the simple strategy and achieves an average complexity of **O(n√n)**.

#### Why This Strategy?

The bucket sort approach strikes a balance between simplicity and efficiency. By processing elements in windows of size √n, we reduce the number of full stack traversals while maintaining predictable performance. This strategy is ideal for medium-sized inputs (roughly 100-500 elements) where the simple strategy becomes too costly, but the overhead of radix sort is not yet justified.

### Complex Strategy - Radix Sort

The complex strategy is based on a **binary radix sort** applied to the `target_index` of each element.
The algorithm processes the stack **bit by bit**, starting from the least significant bit.

For each bit position:
- Elements in stack A are inspected
- If the current bit is `0`, the element is pushed to stack B
- If the bit is `1`, stack A is rotated
- The number of pushes is precomputed to avoid unnecessary full passes

After processing one bit:
- Stack A is realigned to cancel extra rotations
- Elements are pushed back from B to A
- During reinsertion, elements are optionally rotated in B based on the next bit to improve locality

The number of iterations is bounded by the number of bits needed to represent the largest index.
This results in a stable and efficient sorting process with a time complexity of **O(n log n)**, well suited for large input sizes.

#### Why This Strategy?

Radix sort is the most efficient strategy for large inputs, providing optimal O(n log n) performance. By working with the binary representation of `target_index` values, we ensure predictable and consistent performance regardless of the initial ordering of elements. This strategy excels when dealing with inputs of 500+ elements where its logarithmic complexity provides significant advantages over simpler approaches.


## Checker
The checker is a bonus program that takes the same arguments as push_swap, reads instructions from standard input, and verifies that their execution results in a sorted list in stack a. It is intended to be used as follows:
```
./push_swap $(echo $ARGS) | ./checker $(echo $ARGS)
```
To compile the checker, use the bonus rule: `make bonus`

## Feature Credits
| Feature                                          | Credit   |
|--------------------------------------------------|----------|
| Library                                          | smenard  |
| Instructions                                     | smenard  |
| Simple strategy                                  | smenard  |
| Git management (CI/CD, Pull Request reviews)     | smenard  |
| Parsing                                          | vquetier |
| Medium strategy                                  | vquetier |
| Complex strategy                                 | vquetier |
| Benchmark                                        | vquetier |
| Checker                                          | vquetier |