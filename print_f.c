#include "main.h"

int _printf(const char *format, ...)

{
	int chara_print = 0;
	va_list l ist_of_args;

	if(format == NULL)
		return -1;
	
          
	va_start(list_of_arg, format);

	while(*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else
	       	{
			format++;
			if (*format == '\0')
				break;
		

		if(*format == 'c')
		{
			char c = va_arg(list_of_args, int);
			write(1, &c, 1)
			chara_print++;
		}
		else if(*format == 's')
		{
			char *str = va_arg(list_of_args, char*);
			int str_len = 0;

			while(str[str_len] != '\0')
				str_len++;
		}
		
		else if(*format = '%')
		{
			write(1, format, 1);
			chara_print++;
			
			write(1, str, str_len);
			chara_print += str_len;
		
		}
		}
		format++;
	}

	va_arg(list_of_arg);

	return chara_print;
}	
