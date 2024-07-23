#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool parseS(const char* str, int* index, int length);
bool isValidString(const char* str) {
    int index = 0;
    int length = strlen(str);
    bool result = parseS(str, &index, length);
    return result && index == length;
}
bool parseS(const char* str, int* index, int length) {
    if (*index >= length) {
        
        return true;
    }
    if (str[*index] == '0') {
        
        (*index)++;
        
        if (parseS(str, index, length)) {
            
            if (*index < length && str[*index] == '1') {
                (*index)++;
                return true;
            }
        }
        return false;
    }
    return true;
}

int main() {
    const char* testStrings[] = {"0", "01", "0011", "000111", "00001111", "0101", "001011"};
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
