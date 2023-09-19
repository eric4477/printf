#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Define flag constants*/
#define F_MINUS  (1 << 0)
#define F_PLUS   (1 << 1)
#define F_ZERO   (1 << 2)
#define F_HASH   (1 << 3)
#define F_SPACE  (1 << 4)

/* Define size constants*/
#define S_LONG   (1 << 0)
#define S_SHORT  (1 << 1)

typedef struct fmt {
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

int _printf(const char *format, ...);

int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/* Functions to print characters and strings*/
int print_char(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Functions to parse format specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

#endif /* MAIN_H */
