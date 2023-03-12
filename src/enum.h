#ifndef THEORY
#define THEORY 0
#endif

#ifndef LAB
#define LAB 1
#endif

// Change this value to switch between theory and lab grammar
#ifndef CASE
#define CASE LAB
#endif

#ifndef SYMBOL_ENUM
#define SYMBOL_ENUM

enum ActionType
{
    SHIFT,
    REDUCE,
    ACCEPT,
    ERROR
};

// Define an enumeration type called Symbol, with values depending on the value of CASE macro
#if (CASE == THEORY)
enum Symbol
{
    S,
    E,
    PLUS,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    NUM,
    ACC,
};
#endif

// Define an enumeration type called Symbol_lab, with values depending on the value of CASE macro
#if (CASE == LAB)
enum Symbol_lab
{
    S,
    E,
    T,
    F,
    PLUS,
    MULT,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    NUM,
    ACC,
};
#endif

#endif
