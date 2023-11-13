#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
va_list args;

va_start(args, format);

int count = 0;

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
putchar(*format)
count++;
format++;
}
}

va_end(args);
return (count);
}
