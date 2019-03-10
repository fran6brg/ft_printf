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
	char			type;
	char			*flags;
	int				index;
	int				fpos;
	int				flen;
	int				neg;
	int				left_justify;
	int 			sign;
	int 			space;
	int 			hashtag;
	int 			left_zeros;
	int				point;
	int 			pad_un;
	int 			pad_deux;
	int 			h;
	int 			hh;
	int 			l;
	int 			ll;
	int 			L;
	int 			j;
	int 			z;
	int 			sign_is_print;
	struct s_options	*next;
}				t_options;

#endif
