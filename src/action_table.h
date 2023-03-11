#define NUM_SYMBOLS 6
#define NUM_STATES 20

enum ActionType {
    SHIFT,
    REDUCE,
    ACCEPT,
    ERROR
};

typedef struct {
    enum ActionType type;
    int state_or_production;
} Action;

Action action_table[NUM_STATES][NUM_SYMBOLS];

void init_action_table() {
    // initialize the action table
    for (int i = 0; i < NUM_STATES; i++) {
        for (int j = 0; j < NUM_SYMBOLS; j++) {
            action_table[i][j].type = ERROR;
            action_table[i][j].state_or_production = -1;
        }
    }
    // to complete
    //state 0
}

void set_shift_action(int state, int symbol, int next_state) {
    action_table[state][symbol].type = SHIFT;
    action_table[state][symbol].state_or_production = next_state;
}

void set_reduce_action(int state, int symbol, int production) {
    action_table[state][symbol].type = REDUCE;
    action_table[state][symbol].state_or_production = production;
}

void set_accept_action(int state, int symbol) {
    action_table[state][symbol].type = ACCEPT;
}

void set_error_action(int state, int symbol) {
    action_table[state][symbol].type = ERROR;
}