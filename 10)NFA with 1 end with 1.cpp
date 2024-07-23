#include <stdio.h>
#include <string.h>
int simulateNFA(const char *input) {
    int len = strlen(input);
    if (len >= 2 && input[0] == '1' && input[len - 1] == '1') {
        return 1;
    }

    return 0; 
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }

    return 0;
}

