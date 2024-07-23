#include <stdio.h>
#include <stdbool.h>


bool accept_string(char *str) {
    int state = 0;  
    
    for (int i = 0; str[i] != '\0'; ++i) {
        if (state == 0 && str[i] == 'b')
            state = 1;  
        else if (state == 1 && str[i] == 'b')
            state = 2;  
        else
            return false;  
    }
    
    return state == 2; 
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (accept_string(str))
        printf("Accepted\n");
    else
        printf("Rejected\n");
    
    return 0;
}

