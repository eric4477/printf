#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    if (format == NULL)
        return (-1);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                return (-1);

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                print_buffer(c);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    print_buffer(*str);
                    str++;
                    count++;
                }
            }
            else if (*format == '%')
            {
                print_buffer('%');
                count++;
            }
            else
            {
                print_buffer('%');
                print_buffer(*format);
                count += 2;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return (count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

