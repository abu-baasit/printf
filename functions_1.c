#include <unistd.h>
#include <stdarg.h>

/**
* write_integer - Function to write an integer to the standard output
* @num : integer given
* Return:#include "main.h"
*/

void write_integer(int num)
{
char buffer[20];
int len = 0;
do {
buffer[len++] = '0' + (num % 10);
num /= 10;
}
while (num != 0)
{
while (len > 0)
{
len--;
write(1, &buffer[len], 1);
}
}
}

/**
* custom_printf - customer printf supporting d and i conversion specifier
* @format:parameter
* Return:return argument
*/

void custom_printf(const char *format, ...)
{
va_list list_args;
va_start(list_args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'd' || *format == 'i')
{
int number = va_arg(list_args, int);
write_integer(number);
}
else
{
write(1, format - 1, 1);
}
}
else
{
write(1, format, 1);
}
format++;
}
va_end(list_args);
}
