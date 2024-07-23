#include <stdio.h>
#include <stdbool.h>

bool accept_string(char *str) {
    int state = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (state == 0 && str[i] == 'b')
            state = 1;
        else if (state == 1 && str[i] == 'a')
            state = 2;
    }
    return state == 2;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf(accept_string(str) ? "Accepted\n" : "Rejected\n");
    return 0;
}

