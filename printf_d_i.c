#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
int count = 0;
va_list args;

va_start(args, format);

while (*format != '\0')
{
if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
{
int value = va_arg(args, int);
printf("%d", value);
count++;
format += 2;
}
else
{
putchar(*format);
count++;
format++;
}
}

va_end(args);
return (count);
}
