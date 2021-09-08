# push_swap
Sorting algorithm that finds the most optimal (or optimal enough) way to sort an array.

This project has been tested to work on macOS and should work on linux aswell. The tester script probably will not work on other operating systems than macOS.

## Rules

related: https://en.wikipedia.org/wiki/Pushdown_automaton

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

## Checker
- A checker file will be compiled when the main program is compiled.
- Checker is run the same way as push_swap but then waits for the user to give moves that are supposed to result in a sorted array. Press enter after every move.
- After giving all the moves press CTRL + D. After this the checker program will tell you if the numbers were sorted or not.
- A tester script is also included. Run this by typing `sh tester.sh`. The tester script will take a little longer to print out the results because it tests with multiple different combinations. The amount of tests can ofcourse be changed from the script itself.
	- To change the amount of numbers in one of the tests, change the values in TESTS array.
	- To change the amount of tests done on a number, change the values in AMOUNTS array.
	- The result will give the largest amount of moves and the average.
