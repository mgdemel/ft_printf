# ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	int			len; //The minimum number of characters to allocate for the output.
	int			asterisk; //The precision is specified in an integer argument to printf preceding the number to be formatted. (operates on all types)

	//precision - 
	int			percision; // The minimum number of characters to be output, padded on the left with 0’s if necessary.
	int			decimal; // For floats, specifies the maximum number of ints to output after a decimal point to the right of a number. The output is rounded.

	//length - Unlike flags, the length flag dosen't tell printf how to display the number, but more about the number itself.
	int			hh; // +d = signed char, +i = signed char, +o = unsigned char, +u = unsigned char, +x = unsigned char, +X = unsigned char
	int			h; //+d = signed short, +i = signed short, +o = unsigned short, +u = unsigned short, +x = unsigned short, +X = unsigned short
	int			l; // +d = long, +i = long, +o = unsigned long, +u = unsigned long, +x = unsigned long, +X = unsigned long
	int			ll; // +d = long long, +i = long long, +o = unsigned long long, +u = unsigned long long, +x = unsigned long long, +X = unsigned long long
	int			L;

	//conversions
	int			c;
	int			s;
	int			p;
	char		*ptr;
	int			d;
	int			i;
	int			o;
	int			u;
	int			x;
	int			X;
	int			f;
	int			percent;	
}				t_printf;

int 		ft_printf(const char *restrict format, ...);
t_printf	*initialize(char *ptr);
void 		length(char *next, t_printf *data);
void 		format_parser(char next, t_printf *data);
void		conversion_parser(char next, t_printf *data);
void		output(t_printf *data, va_list args);

#endif