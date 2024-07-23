#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool parseS(const char* str, int* index, int length);

// Function to check if the string belongs to the CFG
bool isValidString(const char* str) {
    int index = 0;
    int length = strlen(str);
    bool result = parseS(str, &index, length);
    return result && index == length;
}

// Recursive function to parse S -> 0S1 | e
bool parseS(const char* str, int* index, int length) {
    if (*index >= length) {
        // Reached the end of the string, this is a valid e production
        return true;
    }
    if (str[*index] == '0') {
        // Match '0'
        (*index)++;
        // Recursively parse S
        if (parseS(str, index, length)) {
            // Match '1'
            if (*index < length && str[*index] == '1') {
                (*index)++;
                return true;
            }
        }
        return false;
    }
    // If the current character is not '0', it should be e production
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
