#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


void readLine(const char *prompt, char *buffer, int maxLength) {
    printf("%s", prompt);
    if (fgets(buffer, (size_t)maxLength, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}


double readDouble(const char *prompt) {
    char line[64];
    char *end;
    double value;
    int valid;
    do {
        valid = 1;
        readLine(prompt, line, sizeof(line));
        value = strtod(line, &end);
        if (end == line || *end != '\0') {       
            printf("Invalid number. Try again.\n");
            valid = 0;
        }
    } while (!valid);
    return value;
}

double readNonNegativeDouble(const char *prompt) {
    double value;
    do {
        value = readDouble(prompt);
        if (value < 0) {
            printf("Value cannot be negative. Try again.\n");
        }
    } while (value < 0);
    return value;
}

int readInt(const char *prompt) {
    char line[64];
    char *end;
    long value;
    int valid;
    do {
        valid = 1;
        readLine(prompt, line, sizeof(line));
        value = strtol(line, &end, 10);
        if (end == line || *end != '\0') {
            printf("Invalid number. Try again.\n");
            valid = 0;
        }
    } while (!valid);
    return (int)value;
}

int readPositiveInt(const char *prompt) {
    int value;
    do {
        value = readInt(prompt);
        if (value <= 0) {
            printf("Value must be positive. Try again.\n");
        }
    } while (value <= 0);
    return value;
}
