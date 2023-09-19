#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function.
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list list;
    va_start(list, format);

    int printed_chars = 0;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
                printed_chars += buff_ind;
            }
            else
            {
                printed_chars++;
            }
        }
        else
        {
            print_buffer(buffer, &buff_ind);

            int flags = get_flags(format, &i);
            int width = get_width(format, &i, list);
            int precision = get_precision(format, &i, list);
            int size = get_size(format, &i);
            i++;

            int printed = handle_print(format, &i, list, buffer, flags, width, precision, size);

            if (printed == -1)
            {
                va_end(list);
                return (-1);
            }

            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(list);

    return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer.
 * @buffer: Array of characters.
 * @buff_ind: Index at which to add the next character.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}
