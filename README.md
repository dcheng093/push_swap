*This project has been created as part of the 42 curriculum by dcheng.*
<img width="2780" height="806" alt="image" src="https://github.com/user-attachments/assets/6984b9da-3ad1-428b-bc33-e083e3014f95" />

---

Table of contents
- [Description](#description)
- [Instructions](#instructions)
- [Execution](#execution)
- [Resources](#resources)


## Description
Push_swap is a project where the goal is to write a program that calculates and prints the most efficient sequence of instructions to sort a list of integers. The program uses only a limited set of stack operations (push, swap, rotate, reverse rotate) to achieve this. A benchmark for how efficient the program is sorting x amount of numbers under y amount of operations, as shown below:

* For maximum project validation (100%) and eligibility for bonuses, you must:
  - Sort 100 random numbers in fewer than 700 operations.
  - Sort 500 random numbers in no more than 5500 operations.
* For minimal project validation (which implies a minimum grade of 80%), you can succeed with different averages:
  - 100 numbers in under 1100 operations and 500 numbers in under 8500 operations
  - 100 numbers in under 700 operations and 500 numbers in under 11500 operations
  - 100 numbers in under 1300 operations and 500 numbers in under 5500 operations

---

## Instructions

### Compilation

Compile the project using `make`:

```bash
make
```

This will generate the executable:

```bash
./push_swap
```

### Execution

Run the program with a list of integers as arguments to get the list of operations needed to sort it:

```bash
./push_swap 3 2 1
```

Run the program with the checker from the resources of the Push_swap project page.

```bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```
<img width="1422" height="258" alt="image" src="https://github.com/user-attachments/assets/e3a1afb3-24cc-4a3d-904e-75d6097db95d" />
<img width="1422" height="258" alt="image" src="https://github.com/user-attachments/assets/f7cf93a3-105d-446b-9fcc-cb89bf001cc8" />

---

## Allowed Operations

* `pa`, `pb` — push the top element from one stack to the other
* `ra`, `rb`, `rr` — rotate a stack upward
* `rra`, `rrb`, `rrr` — rotate a stack downward

## Resources

- Turk Sort Algorithm: https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
- Gitbook: https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
- Referring to other people's implementations of push_swap on github

### Use of AI

AI was used to help debug my code and adjust it to comply with norminette's style.
