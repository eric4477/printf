#include "main.h"

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
