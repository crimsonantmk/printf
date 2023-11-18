#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int binary(int num);
int octal(int num);
int _printf(const char *format, ...);
int putchr(char c);
int putss(char *c);

#endif /* MAIN_H */
