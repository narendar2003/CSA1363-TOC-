#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
bool parseS(const char* str, int* index, int length);
bool parseA(const char* str, int* index, int length);

// Function to check if the string belongs to the CFG
bool isValidString(const char* str) {
    int index = 0;
    int length = strlen(str);
    bool result = parseS(str, &index, length);
    return result && index == length;
}

// Recursive function to parse S -> A00A
bool parseS(const char* str, int* index, int length) {
    // Parse A
    if (!parseA(str, index, length)) {
        return false;
    }
    // Match '0'
    if (*index < length && str[*index] == '0') {
        (*index)++;
    } else {
        return false;
    }
    // Match '0'
    if (*index < length && str[*index] == '0') {
        (*index)++;
    } else {
        return false;
    }
    // Parse A
    if (!parseA(str, index, length)) {
        return false;
    }
    return true;
}

// Recursive function to parse A -> 0A | 1A | e
bool parseA(const char* str, int* index, int length) {
    if (*index >= length) {
        // Reached the end of the string, this is a valid e production
        return true;
    }
    if (str[*index] == '0' || str[*index] == '1') {
        // Match '0' or '1'
        (*index)++;
        // Recursively parse A
        return parseA(str, index, length);
    }
    // If the current character is not '0' or '1', it should be e production
    return true;
}

int main() {
    const char* testStrings[] = {"000", "0100", "00100", "1100", "001000", "100100", "0000", "1001", "11001100"};
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
