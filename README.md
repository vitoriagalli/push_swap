# PUSH_SWAP

![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-black)


## Introduction

#### Game rules

The game is composed of 2 stacks named A and B.
The goal is to sort in ascending order the stack A with the minimum possible number of operations.
To do this you have the following operations at your disposal

| operation | description |
| ------------ | ------------ |
| `sa` | swap a - swap the first 2 elements at the top of stack_a |
| `sb` | swap b - swap the first 2 elements at the top of stack_b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | push a - take the first element at the top of b and put it at the top of a |
| `pb` | push b - take the first element at the top of a and put it at the top of b |
| `ra` | rotate a - shift up all elements of stack_a by 1. The first element becomes the last one |
| `rb` | rotate b - shift up all elements of stack_b by 1. The first element becomes the last one |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate a - shift down all elements of stack_a by 1. The last element becomes the first one |
| `rrb` | reverse rotate b - shift down all elements of stack_b by 1. The last element becomes the first one |
| `rrr` | `rra` and `rrb` at the same time |


## Usage

#### Build Instructions

```bash
$ git clone https://github.com/vscabell/push_swap
$ cd push_swap
$ make
```

##### Mandatory

The `push_swap` program must display the smallest list of instructions possible to sort the stack A

```bash
$ make
...
$ ./push_swap 5 3 1
sa
rra
```

##### Bonus

The `checker` program will read instructions on the standard input, each instruction
will be followed by ’\n’. When EOF is triggered, the program will execute them and display if the resulting list is sorted

```bash
$ make bonus
...
$ ./checker 5 3 1
sa
rra
OK
```

checker is also available with the verbose `-v` flag

```bash
$ ./checker -v 5 3 1

size:   3       0
stack:  5
        3
        1
        _       _
        a       b
> sa

size:   3       0
stack:  3
        5
        1
        _       _
        a       b
> rra

size:   3       0
stack:  1
        3
        5
        _       _
        a       b
> OK
```

other commands

```bash
$ make test
```

for the 42 students

```bash
$ make norm
```

#### Algorithm

The implemented algorithm was inspired by the following [wiki](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm), which explain all the steps to sort the stack.

I executed simpler and less performative version, although faster since the markup mode is checked only by index. The step to find out if swap (sa) is necessary was not executed as well.

With this [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) you can follow the operations and the algorithm behavior.

<p align="center">
	<img alt="visualizer" src="https://user-images.githubusercontent.com/56961723/123333822-86bca580-d542-11eb-92cb-b606d9687f35.gif"/></br>
	sorting 100 random valid values
</p>
