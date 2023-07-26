#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
* _printf - function that produces output according to a format
* @format: argument parameters
* Return: printed values
*/
int _printf(const char *format, ...)
{
	int k;
	char c;
	const char *str;
	va_list my_list_args;
va_start(my_list_args, format);
k = 0;
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
c = (char)va_arg(my_list_args, int);
k += _putchar(c);
break;
case 's':
str = va_arg(my_list_args, const char*);
while (*str)
{
k += _putchar(*str);
str++;
}
break;
case '%':
k += _putchar('%');
break;
default:
break;
}
}
else
{
k += _putchar(*format);
}
format++;
}
va_end(my_list_args);
return (k);
}
