#include "main.h"

/**
 * get_size - Calculates the size specifier based on the format string.
 * @format: Formatted string.
 * @i: Pointer to the current position in `format`.
 *
 * Return: Size specifier.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    /* Check for size specifiers 'l' (long) and 'h' (short) */
    if (format[curr_i] == 'l') {
        size = S_LONG;
    } else if (format[curr_i] == 'h') {
        size = S_SHORT;
    }

    /* Update the current position pointer based on the found size specifier */
    if (size == 0) {
        *i = curr_i - 1; /* No size specifier found, so revert to the previous position */
    } else {
        *i = curr_i; /* Update the pointer to the current position */
    }

    return size;
}
