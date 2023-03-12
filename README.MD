# Bottom-up Parsing App

## Description

This program implements a Bottom-up Parsing algorithm in C for a given language. It uses a state diagram and a table to parse expressions in the language and determine if they are part of the language. The output of the program is useful for debugging and provides information about the operations performed, the current input position, the current and previous state, the contents of the stack, and any other relevant variables.

## Installation

To install the program, navigate to the directory where the files are located and run the command `make`. This will compile the source code and create the executable.

To clean the executable generated during the compilation and compile it again, run the command `make all`.

## Usage

To use the program, navigate to the directory where the files are located and run the command `./bottom-up-parsing [input_file]`. Replace "[input_file]" with the name of the file you want to parse.

After running the command, the program will generate an output file called `[input_file]\_p3dbg.txt` in the test directory. This file will contain the parsed information.

For example, to parse a file called "expression.txt", you would run the command `./bottom-up-parsing expression.txt`.
