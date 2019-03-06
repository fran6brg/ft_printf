/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:48:27 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/03 12:45:31 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

static int		is_accepted_options(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%'
			|| c == 'b');
}

static int		is_accepted_flags(char c)
{
	// a reflechir si le vrai printf accepte des options chelou
	return (c == ' ' || c == '.' || c == '#' || c == '0' || c == '+' || c == '-'
			|| ft_isdigit(c) || c == 'h' || c == 'l' || c == 'L' /* juste pour testet alelievre */ || c == 'z'  || c == 'j');
}

int				compute_new_option_len_in_format(const char *format, int i)
{
	int		len;

	len = 1;
	while (is_accepted_flags(format[i + len]))
		len++;
	if (is_accepted_options(format[i + len]))
		return (len);
	else
		return (-1);
}

int				ft_strchr_modified(const char *s, int c)
{
	int		i;
	char	*sptr;

	i = -1;
	sptr = (char *)s;
	while (sptr[++i] != '\0')
	{
		if (sptr[i] == (char)c)
			return (1);
	}
	if ('\0' == (char)c)
		return (1);
	return (0);
}

int				ft_strstr_modified(const char *m, const char *a)
{
	int		i;
	int		j;

	i = -1;
	if (ft_strlen(a) == 0)
		return (0);
	while (m[++i])
	{
		j = 0;
		while (a[j] == m[i + j] && m[i + j])
			j++;
		if (a[j] == '\0')
			return (1);
	}
	return (0);
}
