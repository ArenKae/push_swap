# push_swap

<p align="center">
  <img src="https://github.com/ArenKae/ArenKae/blob/main/42%20badges/push_swape.png" alt="Push_swap 42 project badge"/>
</p>

Push_swap is an algorithm project where we must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

## Status
✅ Completed on: 19/05/2023
</br>
🏆 Grade: 86/100

## Usage

Git clone the repository and cd into it. Then use ```make``` to compile.

Then run it with :

```shell
./push_swap <nbr 1> <nbr 2> <nbr 3> ... <nbr n>
```
or
```shell
./push_swap "<nbr 1> <nbr 2> <nbr 3> ... <nbr n>"
```

- The numbers provided can be positive or negative integers. There must not be any duplicates.

- If the arguments are valid, the program will output the most efficient list of actions to sort the list.

- The program can be checked with the provided checker, like this :

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```
> [!NOTE]
> You might need to make the checker executable for it to work. Use ```sudo chmod +x checker```

> [!TIP]
> You can also simply use ```make test``` to quickly test the program with a large number of random values to sort. The "NBR" value can be edited in the Makefile to change the number of generated values in this test.

You can visualize this push_swap algorithm in action with [O-reo's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer ):

## Push_Swap Rules and Grading

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

When sorting the argmuent numbers, the program will output the actions performed on the stacks. The possible actions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

The grade depends on how efficient the program's sorting process is.
 
* Sorting 3 values: no more than 3 actions.
* Sorting 5 values: no more than 12 actions.
* Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 700 actions
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500
* Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 5500 actions
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500

  Validating the project requires at least 80/100.
