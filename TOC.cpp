#include <stdio.h>
#include <string.h>
typedef enum {
    START,  
    A,      
    B,      
    INVALID 
} State;
int simulateDFA(const char *input) {
    State currentState = START;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        char currentChar = input[i];

        switch (currentState) {
            case START:
                if (currentChar == 'a') {
                    currentState = A;
                } else {
                    currentState = INVALID;
                }
                break;
            case A:
                if (currentChar == 'a') {
                    currentState = A;
                } else {
                    currentState = B;
                }
                break;
            case B:
                if (currentChar == 'a') {
                    currentState = A;
                } else {
                    currentState = B;
                }
                break;
            case INVALID:
                return 0; 
        }
    }
    return currentState == A;
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

