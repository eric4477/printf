#include "main.h"

static int char_print = 0; /* Declare it as a global variable*/
/**
 * _printf - function that produces output
 * @format: a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list list_of_args;
    va_start(list_of_args, format);

    while (*format)
    {
        if (*format != '%')
        {
            print_char(*format, &char_print);
        }
        else
        {
            format++;
            if (*format == '%')
            {
                print_char('%', &char_print);
            }
            else if (*format == 'c')
            {
                char c = va_arg(list_of_args, int);
                print_char(c, &char_print);
            }
            else if (*format == 's')
            {
                char *str = va_arg(list_of_args, char *);
                print_str(str, &char_print);
            }
        }
        format++;
    }

    va_end(list_of_args);
    return char_print;
}
