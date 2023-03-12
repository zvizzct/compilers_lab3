#ifndef THEORY
#define THEORY 0
#endif

#ifndef LAB
#define LAB 1
#endif

#ifndef CASE
#define CASE THEORY
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

//THEORY
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

//LAB
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
};
#endif

#endif
