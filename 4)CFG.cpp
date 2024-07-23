#include <stdio.h>
#include <string.h>
int parseS(const char *str, int *index);
int parseS(const char *str, int *index) {
    int startIndex = *index;
    if (str[*index] == '\0') {
        return 1;
    }

    if (str[*index] == '0') {
        (*index)++;
        if (parseS(str, index) && str[*index] == '0') {
            (*index)++;
            return 1;
        }
        *index = startIndex; 
    }

    if (str[*index] == '1') {
        (*index)++;
        if (parseS(str, index) && str[*index] == '1') {
            (*index)++;
            return 1;
        }
        *index = startIndex; 
    }

    if (str[*index] == '0') {
        (*index)++;
        return 1;
    }
    if (str[*index] == '1') {
        (*index)++;
        return 1;
    }

    return 0; 
}

int main() {
    char input[100];
    int index = 0;

    printf("Enter a string: ");
    scanf("%s", input);

    if (parseS(input, &index) && input[index] == '\0') {
        printf("The string is accepted by the CFG.\n");
    } else {
        printf("The string is not accepted by the CFG.\n");
    }

    return 0;
}

