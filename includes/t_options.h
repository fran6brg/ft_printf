/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_options.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 13:01:22 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/02 13:02:07 by bihattay         ###   ########.fr       */
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
	int				fpos; // position dans la string
	int				flen; // == nb of char, between % and the type, in format

	// ------------------------------ Flags --------------------------------------
	int				left_justify; // 1 if '-' is present inside flags
	int 			sign; // 1 if ('+' is present inside flags)
	int 			space; // 1 if (' ' is present inside flags && sign == 0)
	int 			hashtag; // 1 if ('#' is present inside flags ... pas encore compris le concept)
	/* Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero.
	Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow.
	By default, if no digits follow, no decimal point is written.
	Used with g or G the result is the same as with e or E but trailing zeros are not removed.*/

	// ------------------------------ Widths -------------------------------------
	int 			left_zeros; // 1 if ('0' is present inside flags)

	// ------------------------------ .precision ---------------------------------
	int				point;
	int 			number; // [0..9] if ('[0..9]' is present inside flags)

	// ------------------------------ length -------------------------------------
	int 			h; // 1 if ('h' is present inside flags && only applies to integer specifiers: i, d, o, u, x and X)
	int 			hh; // 1 if ('hh' is present inside flags && only applies to integer specifiers: i, d, o, u, x and X)
	int 			l; // 1 if ('l' is present inside flags)
	int 			ll; // 1 if ('ll' is present inside flags)
	/* The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X),
	and as a wide character or wide character string for specifiers c and s.*/
	int 			L; // 1 if ('L' is present inside flags)

	// ------------------------------ next bitch ---------------------------------
	struct s_options	*next;
}				t_options;

#endif
