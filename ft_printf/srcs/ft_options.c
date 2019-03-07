/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:42:35 by bihattay          #+#    #+#             */
/*   Updated: 2019/03/06 05:26:52 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

static int		extract_number_in_flags(t_options *new, int first, int start)
{
	int		i;
	int		j;
	int		sum;

	// printf("\nnew->flags[%i] = %s\n", start, new->flags + start);
	i = start;
	j = 0;
	sum = 0;
	while (new->flags[i]) // si 1 chiffre = min sinon [max.min]
	{
		if (new->flags[i] == '.')
		{
				new->point = 1;
				i++;
				break;
		}
		if (new->flags[i] == '0' && (i == 0
				|| (new->pad_min && i > 0 && new->flags[i - 1] != '.') /*	10.0 n'est pas left_zeros */
				|| (new->flags[i + 1]
					&& !ft_isdigit(new->flags[i + 1]) && new->flags[i + 1] != '.'))) /* +010. n'est pas left_zeros */
			new->left_zeros = 1;
		else if (ft_isdigit(new->flags[i]))
		{
			while (new->flags[i] && ft_isdigit(new->flags[i + j]))
				sum = ((sum * 10) + ((int)new->flags[i + j++] - 48));
			i += (j - 1);
		}
		else
			;
		i++;
	}
	if (first == 0) // si 1 chiffre = min sinon [max.min]
	{
		new->pad_min = sum;
		//printf("\nsum0 = %i\n", sum);
	}
	else
	{
		//printf("\nsum1 = %i\n", sum);
		new->pad_max = sum;
	}
	return (i);
}

t_options		*create_new_option(const char *format, int i)
{
	t_options	*new;
	int 			ret;

	if ((new = (t_options*)ft_memalloc(sizeof(t_options))) == NULL)
		return (NULL);
	new->index = i;
	if ((new->flen = compute_new_option_len_in_format(format, i)) == -1)
		return (NULL);
	new->type = (new->flen > 0 ? (format[i + new->flen]) : (char)NULL);
	if (new->flen > 1)
		new->flags = ft_strsub(format, i + 1, (size_t)(new->flen - 1));
	new->fpos = i;
	if (new->flen > 1 && ft_strchr_modified(new->flags, '-'))
		new->left_justify = 1;
	if (new->flen > 1 && ft_strchr_modified(new->flags, '+'))
		new->sign = 1;
	if (new->flags && new->flen > 1)
		new->point = ft_strchr_modified(new->flags, '.') ? 1 : 0;
	if (new->flen > 1 && new->sign != 1 && ft_strchr_modified(new->flags, ' '))
		new->space = 1;
	if (new->flen > 1 && ft_strchr_modified(new->flags, '#'))
		new->hashtag = 1;
	if (new->flen > 1)
		ret = extract_number_in_flags(new, 0, 0);
	if (new->flen > 1)
		extract_number_in_flags(new, 1, ret);
	if (new->flen > 1 && ft_strstr_modified(new->flags, "hh"))
		new->hh = 1;
	else if (new->flen > 1 && ft_strstr_modified(new->flags, "h"))
		new->h = 1;
	if (new->flen > 1 && ft_strstr_modified(new->flags, "ll"))
		new->ll = 1;
	else if (new->flen > 1 && ft_strchr_modified(new->flags, 'l'))
		new->l = 1;
	if (new->flen > 1 && ft_strchr_modified(new->flags, 'L'))
		if (new->flen > 1 && ft_strstr_modified(new->flags, "ll"))
			new->ll = 1;
	if (new->flen > 1 && ft_strchr_modified(new->flags, 'j'))
		new->j = 1;
	if (new->flen > 1 && ft_strchr_modified(new->flags, 'z'))
		new->z = 1;
	new->sign_is_print = 0;
	return (new);
}

void			push_back_new_option(t_options **latest_option, t_options *new)
{
	t_options	*latest;

	if (latest_option == NULL)
		return ;
	if (*latest_option == NULL)
		*latest_option = new;
	else
	{
		latest = *latest_option;
		while (latest->next != NULL)
			latest = latest->next;
		latest->next = new;
	}
}

int				extract_options(const char *format, t_options **options)
{
	int			i;
	int			format_len;
	t_options	*new;

	i = -1;
	format_len = ft_strlen(format);
	new = NULL;
	while (++i < format_len)
	{
		if (format[i] == '%')
		{
			if ((new = (create_new_option(format, i))) == NULL)
			{
				printf("RET -1 = unvalid option\n");
				return (-1);
			}
			else
			{
				i += new->flen;
				push_back_new_option(options, new);
			}
		}
	}
	return (1);
}
