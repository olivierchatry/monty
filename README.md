# monty : stack / queue based langage
## Goal
This project implements `monty` langage school designed by the **awesome** teachers @ **Holberton school**. It is used to help students in their learning of **stack** and **queue** storage. The project must be written in **C** and must not **leak any memory**.
`stack` is [**LIFO** (last in first out)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) while a `queue` is [**FIFO** (first in first out)](https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)).

## Build
Just type `make` at the root of the repository. This will build a `monty` executable, which will be placed in the same folder. The build process will also create a `build` folder which will contains all the intermediate files ( obj and dependency ).

You can also `clean` the build process by using the command `make clean`.

## Command line argument
```
monty [file_name]
``` 
`monty` only accept one argument, a file name, which contains a list of commands to be executed. 

## monty langage definition
### grammar
* Each instruction should be on a separate line. 
* Each argument, if any, should be separated by a space or a tab. 
* Each line can contains any amount of space between command and argument
* All text typed after the last argument of an instruction will be treated as comment.
* You can use `#` to comment a line.
* Line cam be empty
* monty is only working on `integer` and **does not** check for overflow.

### instructions
#### stack
Set `monty` store **mode** to `LIFO`. 
> This is the **default** mode.

#### queue
Set `monty` store **mode** to `FIFO`  

#### push
The opcode `push` pushes an element to the stack.

* Usage: push `<int>`
* where `<int>` is an integer
* if `<int>` is not an integer or if there is no argument to push, print the message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE` 

#### pall
The opcode `pall` prints all the values on the stack, starting from the top of the stack.

* Usage `pall`
* If the stack is empty, don't print anything

#### pint 
The opcode `pint` prints the value at the top of the stack, followed by a new line.

* Usage: `pint`
* If the stack is empty, print `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### pop
The opcode `pop` removes the top element of the stack.

* Usage: `pop`
* if the stack is empty, print `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### swap
The opcode `swap` swaps the top two elements of the stack.

* Usage: `swap`
* If the stack is less than two element long, print `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### add
The opcode `add` adds the top two elements of the stack.

* Usage: `add` 
* If the stack is less than two element long, print `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* the top element of the stack contains the result
	* the stack is one element shorter

#### nop
The opcode `nop` doesn't do anything.

Usage: `nop`

#### sub
The opcode `sub` subtracts the top element of the stack from the second top element of the stack.

Usage: `sub`
* If the stack is less than two element long, print `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* the top element of the stack contains the result
	* the stack is one element shorter

#### div
The opcode `div` divides the second top element of the stack by the top element of the stack.

Usage: `div`
* If the stack is less than two element long, print `L<line_number>: can't div, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* the top element of the stack contains the result
	* the stack is one element shorter
* If the top element of the stack is `0`, print `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### mul
The opcode `mul` multiplies the second top element of the stack with the top element of the stack.

Usage: `mul`
* If the stack is less than two element long, print `L<line_number>: can't mul, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* the top element of the stack contains the result
	* the stack is one element shorter

#### mod
The opcode `mod` computes the rest of the division of the second top element of the stack by the top element of the stack.

Usage: `mod`
* If the stack is less than two element long, print `L<line_number>: can't mod, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* the top element of the stack contains the result
	* the stack is one element shorter
* If the top element of the stack is `0`, print `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### pchar 
The opcode `pchar` prints the char at the top of the stack, followed by a new line.

Usage: `pchar`
* The integer stored at the top of the stack is treated as the ascii value of the character to be printed
* If the value is not in the ascii table (man ascii) print `L<line_number>: can't pchar, value out of range`, followed by a new line, and exit with the status `EXIT_FAILURE`
* If the stack is empty, print `L<line_number>: can't pchar, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### pstr
The opcode `pstr` prints the string starting at the top of the stack, followed by a new line.

Usage: `pstr`
* The integer stored in each element of the stack is treated as the ascii value of the character to be printed
* The string stops where:
	* the stack is over
	* the value of the element is 0
	* the value of the element is not in the ascii table
* If the stack is empty, print only a new line

#### rotl
The opcode `rotl` rotates the stack to the top.

Usage: `rotl`
The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
rotl never fails

#### rotr
The opcode `rotr` rotates the stack to the bottom.

Usage: `rotr`
The last element of the stack becomes the top element of the stack
rotr never fails

