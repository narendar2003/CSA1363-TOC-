#include <stdio.h>
#include <string.h>
int parseA(const char *str, int *index);
int parseA(const char *str, int *index) {
    if (str[*index] == '\0') {
        return 1;
    }

    if (str[*index] == 'a' || str[*index] == 'b') {
        (*index)++;
        if (parseA(str, index)) {
            return 1;
        }
    }

    return 0;  
}

int main() {
    char input[100];
    int index = 0;

    printf("Enter a string: ");
    scanf("%s", input);

    if (parseA(input, &index) && input[index] == '\0') {
        printf("The string is accepted by the CFG.\n");
    } else {
        printf("The string is not accepted by the CFG.\n");
    }

    return 0;
}

