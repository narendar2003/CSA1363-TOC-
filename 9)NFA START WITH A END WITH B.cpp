#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isValidString(const char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; ++i) {
        if (str[i] != 'a') {
            return false; 
        }
    }
    return true; 
}

int main() {
    const char* testStrings[] = {"", "a", "aa", "aaa", "aaaa", "aab", "baa", "ab"};
    int numTests = sizeof(testStrings) / sizeof(testStrings[0]);

    for (int i = 0; i < numTests; ++i) {
        if (isValidString(testStrings[i])) {
            printf("The string \"%s\" is valid.\n", testStrings[i]);
        } else {
            printf("The string \"%s\" is not valid.\n", testStrings[i]);
        }
    }

    return 0;
}
