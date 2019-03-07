/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_options.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 13:01:22 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/06 06:28:52 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OPTIONS_H
# define T_OPTIONS_H
# include <string.h>

typedef struct	s_options
{
	// ------------------------------ Must have ----------------------------------
	char			type; // = la position du % + option->flen
	char			*flags; // = ft_strsub de ce qu'il y a entre le % et le type
	//char			*minlen;
	//char			*maxlen;
	int				index;
	int				fpos; // position dans la string
	int				flen; // == nb of char, between % and the type, in format

	int				neg;
	// ------------------------------ Flags --------------------------------------
	int				left_justify; // 1 if '-' is present inside flags
	// Left-justify within the given field width; Right justification is the default (see width sub-specifier).

	int 			sign; // 1 if ('+' is present inside flags)
	// Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign.

	int 			space; // 1 if (' ' is present inside flags && sign == 0)
	// If no sign is going to be written, a blank space is inserted before the value.

	int 			hashtag; // 1 if ('#' is present inside flags)
	/* Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero.
	Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow.
	By default, if no digits follow, no decimal point is written.
	Used with g or G the result is the same as with e or E but trailing zeros are not removed.*/

	// ------------------------------ Widths -------------------------------------
	int 			left_zeros; // 1 if ('0' is present inside flags)

	// ------------------------------ .precision ---------------------------------
	int				point;

	int 			pad_un; // [0..9] if ('[0..9]' is present inside flags)
	// Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.

	// .number = for integer specifiers (d, i, o, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E and f specifiers − this is the number of digits to be printed after the decimal point. For g and G specifiers − This is the maximum number of significant digits to be printed. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed.

	int 			pad_deux; // [0..9] if ('[0..9]' is present inside flags)

	// ------------------------------ length -------------------------------------
	int 			h; // 1 if ('h' is present inside flags && only applies to integer specifiers: i, d, o, u, x and X)
	int 			hh; // 1 if ('hh' is present inside flags && only applies to integer specifiers: i, d, o, u, x and X)
	int 			l; // 1 if ('l' is present inside flags)
	int 			ll; // 1 if ('ll' is present inside flags)
	/* The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X),
	and as a wide character or wide character string for specifiers c and s.*/
	int 			L; // 1 if ('L' is present inside flags)
	int 			j; // https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2017
	int 			z; // https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2017

	// ---------------------------- other bitchz ---------------------------------
	int 			sign_is_print; // 1 if ('L' is present inside flags)

	// ------------------------------ next bitch ---------------------------------
	struct s_options	*next;
}				t_options;

#endif
