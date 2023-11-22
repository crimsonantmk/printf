#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return write(1, &c, 1);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)

{
va_list args;
int count = 0;
int i = 0;

va_start(args, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);

while (format[i])
{
if (format[i] == '%')
{
i++;
while (format[i] == ' ')
i++;
if (format[i] == '\0')
return (-1);
if (format[i] == '%')
count += _putchar('%');
else if (format[i] == 'c')
count += _putchar(va_arg(args, int));
else if (format[i] == 's')
count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
else
count += _putchar('%') + _putchar(format[i]);
}
else
count += _putchar(format[i]);
i++;
}

va_end(args);
return (count);
}



