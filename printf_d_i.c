#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 * Return: Number of characters printed (excluding null byte)
 */
int printf_d_i(const char *format, ...)
{
va_list args;

int count = 0;

const char *ptr;

va_start(args, format);

for (ptr = format; *ptr != '\0'; ++ptr)
{
if (*ptr == '%' && (*(ptr + 1) == 'd' || *(ptr + 1) == 'i'))
{
int num = va_arg(args, int);
char buffer[12];

sprintf(buffer, "%d", num);

count += write(1, buffer, strlen(buffer));

++ptr;
}
else if (*ptr == '%' && *(ptr + 1) == '%')
{
count += write(1, "%", 1);
++ptr;
}
else
{
count += write(1, ptr, 1);
}
}

va_end(args);
return (count);
}

