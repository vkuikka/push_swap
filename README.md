# push_swap
Sorting algorithm that finds the most optimal (or optimal enough) way to sort an array.

## Rules
 - The game is composed of two stacks.
 - Numbers can be moved between and inside the stacks with the following moves:
 	- Swap to numbers on top of either stack.
 	- Rotate either stack by moving first number to last or the reverse.
 	- Push a number from the top of either stack to the other.
- Moves will be represented with the following codes in the output:
	- sa (swap first numbers in stack A)
	- sb (swap first numbers in stack B)
	- ss (swap first numbers in both stacks)
	- pa (push first number from stack B to stack A)
	- pb (push first number from stack A to stack B)
	- ra (rotate first number from stack A to be the last number in stack A)
	- rb (rotate first number from stack B to be the last number in stack B)
	- rr (rotate both stacks)
	- rra (reverse of ra)
	- rrb (reverse of rb)
	- rrr (reverse of rr)
- As with all school projects this project has to follow the syntax rules of the school. For example the length of a function must not go over 25 lines.
	
## Installation
- Clone and open this repository.
- Run `make`. this should first compile libft library and then compile the project itself.

## Usage
- Give numbers that will be sorted as argument when running the program.
	- For example run `./push_swap 1 3 2`
- The program will give you the moves that will result in sorting the numbers.
