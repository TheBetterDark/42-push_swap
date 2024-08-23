# 42-push_swap

## Description

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed we have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting. I chose to implement the [Turk Sort algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

## Usage

```bash
$> make
$> ./push_swap 4 67 3 87 23
```

## Rules

- The game is composed of 2 stacks named 'a' and 'b'.

- To start with:
  - 'a' contains a random number of either positive or negative numbers without any duplicates.
  - 'b' is empty.

- The goal is to sort in ascending order numbers into stack 'a'.

## Instructions

- sa: swap a - swap the first 2 elements at the top of stack 'a'.
- sb: swap b - swap the first 2 elements at the top of stack 'b'.
- ss: sa and sb at the same time.

- pa: push a - take the first element at the top of 'b' and put it at the top of 'a'.
- pb: push b - take the first element at the top of 'a' and put it at the top of 'b'.

- ra: rotate a - shift up all elements of stack 'a' by 1.
- rb: rotate b - shift up all elements of stack 'b' by 1.
- rr: ra and rb at the same time.

- rra: reverse rotate a - shift down all elements of stack 'a' by 1.
- rrb: reverse rotate b - shift down all elements of stack 'b' by 1.
- rrr: rra and rrb at the same time.

## Turk Sort Algorithm

1. Until there are 3 nodes left in stack 'a':
    - Push all nodes from stack 'a' to stack 'b'.
    - Sort stack 'b' in descending order during each push.

2. Push back to stack 'a':
    - Every 'b' node has a target 'a' node:
      - The "closest bigger" node.
      - If the "closest bigger" node is not found, the target node is the 'min' value.
    - The median:
      - If the target node is above, perform rotate_a().
      - If the target node is below, perform reverse_rotate_a().

3. Finally, the 'min' value is on top.
    - Rotate or reverse rotate according to the median.

4. Stack 'a' is sorted.
