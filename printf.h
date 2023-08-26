#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
/**
  * struct parameters - function
  *@unsign: int
  *@plus_flag: int
  *@space_flag: int
  *@hashtag_flag: ibt
  *@zero_flag:
  *@minus_flag: on
  *@width: width
  *@precision: field
  *@h_modifier: spec
  *@l_modifier:spec
  */
typedef struct parameters
{
	unsigned int unsign : 1;

	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;
/**
  * struct specifier - function
  *@specifier: spec
  *@f: function
  */
typedef struct specifier
{
	char *specifier;

	int (*f) (va_list, params_t*);
} specifier_t;

int _printf(const char *format, ...);

/* puts function */
int _puts(char *str);
int _putchar(int c);

/* printts function*/
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);

/* numbers */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier*/
int (*get_speicifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* conversion */

#endif /* PRINTF_H */
