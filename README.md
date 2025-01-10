# push_swap 🔄

## Overview 📝

`push_swap` is a C project that implements a sorting algorithm using stacks. The goal of the project is to sort a list of integers using a limited set of operations, all while minimizing the number of operations performed. The main challenge is to efficiently sort the numbers while adhering to the constraints imposed by the problem.

The project is part of the 42 coding school curriculum and focuses on algorithm optimization, stack manipulation, and efficient problem-solving using a small set of operations.

## Features 🌟

- Implements a sorting algorithm using two stacks (`a` and `b`).
- Performs sorting using only a few allowed operations:
  - `sa` – Swap the first 2 elements of stack `a`.
  - `sb` – Swap the first 2 elements of stack `b`.
  - `ss` – Swap the first 2 elements of both stacks `a` and `b`.
  - `pa` – Push the top element of stack `b` to stack `a`.
  - `pb` – Push the top element of stack `a` to stack `b`.
  - `ra` – Rotate stack `a` (move the first element to the last position).
  - `rb` – Rotate stack `b` (move the first element to the last position).
  - `rr` – Rotate both stacks `a` and `b`.
  - `rra` – Reverse rotate stack `a` (move the last element to the first position).
  - `rrb` – Reverse rotate stack `b` (move the last element to the first position).
  - `rrr` – Reverse rotate both stacks `a` and `b`.
- Sorts a list of integers with minimal moves and within an acceptable time frame.
- Focuses on algorithmic efficiency and problem-solving.
