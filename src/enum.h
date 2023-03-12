#ifndef SYMBOL_ENUM
#define SYMBOL_ENUM

enum ActionType
{
    SHIFT,
    REDUCE,
    ACCEPT,
    ERROR
};

//LAB
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

// THEORY
// enum Symbol_lab
// {
//     S,
//     E,
//     T,
//     F,
//     PLUS,
//     MULT,
//     LEFT_PARENTHESIS,
//     RIGHT_PARENTHESIS,
//     NUM,
// };

// production_rule *initProductions()
// {
//     production_rule productions_lab[7] = {{S, {E}, 1}, {E, {E, PLUS, T}, 3}, {E, {T}, 1}, {T, {T, MULT, F}, 3}, {T, {F}, 1}, {F, {LEFT_PARENTHESIS, E, RIGHT_PARENTHESIS}, 3}, {F, {NUM}, 1}};
// }

#endif
