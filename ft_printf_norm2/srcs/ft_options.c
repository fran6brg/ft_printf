/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:42:35 by bihattay          #+#    #+#             */
/*   Updated: 2019/03/10 06:38:03 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int			get_flags_numbers(t_options *new, int call, int i, int flen)
{
	int		j;
	int		sum;

	if (flen <= 1)
		return (0);
	j = 0;
	sum = 0;
	while (new->flags[++i])
	{
		if (new->flags[i] == '.' && i++ > -1 && (new->point = 1))
			break ;
		if (new->flags[i] == '0' && (i == 0
			|| (new->flags[i - 1] != '.' && !ft_isdigit(new->flags[i - 1]))))
			new->left_zeros = 1;
		else if (ft_isdigit(new->flags[i]))
		{
			while (new->flags[i] && ft_isdigit(new->flags[i + j]))
				sum = ((sum * 10) + ((int)new->flags[i + j++] - 48));
			i += (j - 1);
		}
	}
	new->pad_un = call == 0 ? sum : new->pad_un;
	new->pad_deux = call == 1 ? sum : new->pad_deux;
	return (i);
}

void		create_new_option_bis(const char *format, t_options *new)
{
	if (new->flen > 1)
		new->flags = ft_strsub(format, new->fpos + 1, (size_t)(new->flen - 1));
	new->left_justify = ft_strchr_modified(new->flags, '-', new->flen);
	new->sign = ft_strchr_modified(new->flags, '+', new->flen);
	if (new->flags)
		new->point = ft_strchr_modified(new->flags, '.', new->flen);
	if (!new->sign)
		new->space = ft_strchr_modified(new->flags, ' ', new->flen);
	new->hashtag = ft_strchr_modified(new->flags, '#', new->flen);
	if (ft_strstr_modified(new->flags, "hh", new->flen))
		new->hh = 1;
	else if (ft_strstr_modified(new->flags, "h", new->flen))
		new->h = 1;
	if (ft_strstr_modified(new->flags, "ll", new->flen))
		new->ll = 1;
	else if (ft_strchr_modified(new->flags, 'l', new->flen))
		new->l = 1;
	if (ft_strchr_modified(new->flags, 'L', new->flen))
		if (new->flen > 1 && ft_strstr_modified(new->flags, "ll", new->flen))
			new->ll = 1;
	new->j = ft_strchr_modified(new->flags, 'j', new->flen);
	new->z = ft_strchr_modified(new->flags, 'z', new->flen);
	new->sign_is_print = 0;
}

t_options	*create_new_option(const char *format, int i)
{
	t_options	*new;
	int			ret;

	if ((new = (t_options*)ft_memalloc(sizeof(t_options))) == NULL)
		return (NULL);
	new->index = i;
	if ((new->flen = compute_new_option_len_in_format(format, i)) == -1)
		return (NULL);
	new->type = (new->flen > 0 ? (format[i + new->flen]) : (char)NULL);
	new->fpos = i;
	create_new_option_bis(format, new);
	ret = get_flags_numbers(new, 0, -1, new->flen);
	get_flags_numbers(new, 1, ret - 1, new->flen);
	return (new);
}

void		push_back_new_option(t_options **latest_option, t_options *new)
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

int			extract_options(const char *format, t_options **options)
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
				return (-1);
			else
			{
				i += new->flen;
				push_back_new_option(options, new);
			}
		}
	}
	return (1);
}
