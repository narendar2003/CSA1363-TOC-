#include <stdio.h>
#include <string.h>
typedef enum {
    START,  
    S0,     
    S1,     
    ACCEPT, 
    INVALID 
} State;
int simulateDFA(const char *input) {
    State currentState = START;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        char currentChar = input[i];
        switch (currentState) {
            case START:
                if (currentChar == '0') {
                    currentState = S0;
                } else {
                    currentState = INVALID;
                }
                break;
            case S0:
                if (currentChar == '1') {
                    currentState = ACCEPT;
                } else if (currentChar == '0') {
                    currentState = S0;
                } else {
                    currentState = S1;
                }
                break;
            case S1:
                if (currentChar == '1') {
                    currentState = ACCEPT;
                } else {
                    currentState = S1;
                }
                break;
            case ACCEPT:
                if (currentChar == '1') {
                    currentState = ACCEPT;
                } else {
                    currentState = S1;
                }
                break;
            case INVALID:
                return 0; 
        }
    }
    return currentState == ACCEPT;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateDFA(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is not accepted by the DFA.\n");
    }
    return 0;
}

