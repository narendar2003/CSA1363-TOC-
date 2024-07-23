#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 100


typedef struct {
    int transitions[256][MAX_STATES];  
    bool epsilon[MAX_STATES];          
    int num_states;                    
    int num_symbols;                  
} NFA;


void epsilon_closure(NFA *nfa, int state, bool *visited, bool *epsilon_closure_set) {
    if (visited[state]) return;
    
    visited[state] = true;
    epsilon_closure_set[state] = true;
    

    for (int i = 0; i < nfa->num_states; ++i) {
        if (nfa->epsilon[state] && !visited[i]) {
            epsilon_closure(nfa, i, visited, epsilon_closure_set);
        }
    }
}


void compute_epsilon_closures(NFA *nfa, int epsilon_closures[][MAX_STATES]) {
    bool visited[MAX_STATES];
    
    for (int i = 0; i < nfa->num_states; ++i) {
        memset(visited, false, sizeof(visited));
        memset(epsilon_closures[i], 0, sizeof(epsilon_closures[i]));
        
      
        epsilon_closure(nfa, i, visited, epsilon_closures[i]);
    }
}


void display_epsilon_closures(NFA *nfa, int epsilon_closures[][MAX_STATES]) {
    printf("Epsilon Closures:\n");
    
    for (int i = 0; i < nfa->num_states; ++i) {
        printf("e-closure(q%d) = {", i);
        bool first = true;
        
        for (int j = 0; j < nfa->num_states; ++j) {
            if (epsilon_closures[i][j]) {
                if (!first) printf(", ");
                printf("q%d", j);
                first = false;
            }
        }
        
        printf("}\n");
    }
}

int main() {
    
    NFA nfa;
    nfa.num_states = 3;
    nfa.num_symbols = 256;  
    
    
    memset(nfa.epsilon, false, sizeof(nfa.epsilon));
    nfa.epsilon[0] = true;  
    
    
    memset(nfa.transitions, -1, sizeof(nfa.transitions));
    nfa.transitions['a'][0] = 1;  
    nfa.transitions['b'][1] = 2;  
    
    int epsilon_closures[MAX_STATES][MAX_STATES];
    

    compute_epsilon_closures(&nfa, epsilon_closures);
    
    display_epsilon_closures(&nfa, epsilon_closures);
    
    return 0;
}

