## 1. Deriving the Shift/Reduce Automaton

The first task of this assignment is to derive the Shift/Reduce Automaton for a given language. This involves the following steps:

1. Constructing the state diagram with the closures inside the states and indicating the reductions at the states it applies.
2. Renaming the states with numerical values 1, 2, and so on.
3. Providing the table for the Shift/Reduce Automaton.

The next step is to implement the automaton in C. The language may change with changes in the table, but the engine remains the same.

## 2.1 Data Structure

In this section, you must explain the detailed data structure used in the program, including:

1. The definition of the data structure with the name and fields used in the program.
2. A diagram that shows the data structure and its fields and relationships.
3. An explanation of each field and structure.

## 2.2 Block Diagram Considerations

The code should be divided into short functions, with a diagram of the overall application that represents its functionalities and relationships. Functions should be created for well-known operations, such as those for a stack, adapted to the context of the program. The program diagram should include all functions defined in the code and provide a graphical representation of the program's structure. Each function should have a comment that explains its role in the context of the overall diagram.

## 3. Input

The parser should be able to recognize an expression as part of the language or indicate that it is not. The input to the parser will be the output file of the scanner, which should be loaded into a list of tokens in memory. This should be done as a library that can be called by both the parser and the scanner. The data structure section of the report should explain how the list of tokens was implemented.

## 4. Output

The output should be useful for debugging and should be similar to the information in the Shift/Reduce Automaton tables. Every time there is a change in state or stack, it should be written to the output file. The output should indicate at least:

- The operation (shift or reduce)
- The current input position
- The current and previous state
- The contents of the stack
- Other relevant variables
- The report should explain the format of the sentences written to the output file so that it can be interpreted. The output file should have the same name as the input file with the suffix `_p3dbg` and the extension `.txt`.

## 5. Error Handling

Error handling is not required in this assignment.

## 6. Usage of the Program

The report should include a usage section that explains how to use the program.

## 8. Submission Instructions

The following items must be submitted:

C code (.c and .h files) and a make file to compile it.
At least one sample input with the corresponding output file. The tests and their results should be clearly explained and related to the specific file names in the report.
A report file including the design specification and all required documentation.

## 9. Evaluation Criteria

The assignment will be evaluated based on the following criteria:

| Design and Documentation                | 35% |
| --------------------------------------- | --- |
| Shift/reduce automaton                  |     |
| Data structure diagram and explanations |     |
| Block diagram and explanations          |     |
| Output format                           |     |
| Input-output manual example/s           |     |
| Usage of the program                    |     |

<br>

| Code                                    | 35% |
| --------------------------------------- | --- |
| Comments in the code                    |     |
| Division of the code in functionalities |     |
| Understanding of the code               |     |

<br>

| Implementation                   | 30% |
| -------------------------------- | --- |
| Initialization of the automaton  |     |
| Read in tokens                   |     |
| Operations of list of tokens     |     |
| Stack and operations             |     |
| Shift/reduce automaton           |     |
| Generation of the output         |     |
| Test examples (and explanations) |     |
