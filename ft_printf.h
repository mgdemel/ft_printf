# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> //REMOVE!!!
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
#include "libft/libft.h"

typedef	struct	s_printf
{
	//flags
	int			hash; // For f flag, the output will always contain a decimal point even if the fractional part of the number is zero. For o, x, X flags: 0, 0x, 0X are added to the front of the number.
	int			zero; // When the 'width' is specified, adds the 'widths' amount of zeros in front of the number (operates only on numbers)
	int			minus; // Left-aligns the output (operates on all types)
	int			plus; // Adds a plus to the start of numbers when positive. (operates only on numeric types)
	int			space; // Adds a space to the start of numbers when positive... unless there is a plus! (operates only on numeric types)

	//width
	int			width; //The minimum number of characters to allocate for the output.
	int			asterisk; //The precision is specified in an integer argument to printf preceding the number to be formatted. (operates on all types)

	//precision - 
	int			precision; // The minimum number of characters to be output, padded on the left with 0’s if necessary.
	int			decimal; // For floats, specifies the maximum number of ints to output after a decimal point to the right of a number. The output is rounded.

	//length - Unlike flags, the length flag dosen't tell printf how to display the number, but more about the number itself.
	int			hh; // +d = signed char, +i = signed char, +o = unsigned char, +u = unsigned char, +x = unsigned char, +X = unsigned char
	int			h; //+d = signed short, +i = signed short, +o = unsigned short, +u = unsigned short, +x = unsigned short, +X = unsigned short
	int			l; // +d = long, +i = long, +o = unsigned long, +u = unsigned long, +x = unsigned long, +X = unsigned long
	int			ll; // +d = long long, +i = long long, +o = unsigned long long, +u = unsigned long long, +x = unsigned long long, +X = unsigned long long
	int			L;

	// //type specifier
	// int			c; // char ~ c
	// int			s; // char *str ~ example
	// int			p; // pointer address ~ bc080
	// int			d; // signed decimal int ~ –123
	// int			i; // signed decimal int ~ –123
	// int			o; // unsigned octal ~ 05670
	// int			u; // unsigned decimal int ~ 456
	// int			x; // unsigned hexadecimal (lowercase) ~ 89abc
	// int			X; // unsigned hexadecimal (uppercase) ~ 89ABC
	// int			f; // decimal floating point ~ 123.456
}				t_printf;

// ft_printf.c
int 		ft_printf(const char *restrict format, ...);
int		 	ft_preparser(char c, char *nformat, t_printf *data, va_list args);

// initialize.c
int			precision_len(char *nformat);
t_printf	*initialize(char *nformat);

// flags_to_struct.c
void 		length(char flag, t_printf *data);
void		precision_to_struct(char *nformat, t_printf *data);
void		width_to_struct(char *nformat, t_printf *data);
void		amplifiers(char flag, t_printf *data);
t_printf 	flags_to_struct(char c, char *nformat, t_printf *data);

// // types_to_struct.c
// void		types_to_struct(char c, t_printf *data);
// void		type_csp(char c, t_printf *data);
// void		type_diouxX(char c, t_printf *data);

// teststruct.c
void		teststruct(t_printf *data);

// output.c
int			output(char c, va_list args); //, t_printf *data,);

// types_cspdi.c
void		type_c(va_list args);
void		type_s(va_list args);
void		type_p(va_list args);
void		type_d(va_list args);
void		type_i(va_list args);

// types_ouxXf.c
void		type_o(va_list args);
void		type_u(va_list args);
void		type_x(va_list args);
void		type_X(va_list args);
void		type_f(va_list args);

#endif