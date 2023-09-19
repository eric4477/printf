#include "main.h"

static int char_print = 0; /* Declare it as a global variable*/
void print_char(char c, int *char_print);
void print_str(char *str, int *char_print);

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

/**
 * print_str - function to print string
 * @str: string to print
 * @char_print: print iterator
 * Return: void
 */
void print_str(char *str, int *char_print)
{
    while (*str)
    {
        print_char(*str, char_print);
        str++;
    }
}

/**
 * print_char - function to print character
 * @c: character to print
 * @char_print: print iterator
 * Return: 1 on success
 */
void print_char(char c, int *char_print)
{
    static int i = 0;
    static char buf[BUFF_SIZE];

    if (c != BUF_FLUSH)
    {
        if (i >= BUFF_SIZE)
        {
            write(1, buf, i);
            i = 0;
        }
        buf[i++] = c;
        (*char_print)++;
    }
    else if (i > 0)
    {
        write(1, buf, i);
        i = 0;
    }
}
