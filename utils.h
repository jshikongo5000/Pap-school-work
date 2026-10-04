#ifndef UTILS_H
#define UTILS_H

void readLine(const char *prompt, char *buffer, int maxLength);

int readInt(const char *prompt);
int readPositiveInt(const char *prompt);
double readDouble(const char *prompt);
double readNonNegativeDouble(const char *prompt);

#endif
