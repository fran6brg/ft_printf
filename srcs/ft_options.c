/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:42:35 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/03 10:47:37 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

static int	extract_number_in_flags(t_options *new)
{
	int		i;
	int		j;
	int		sum;

	i = 0;
	j = 0;
	sum = 0;

	while (new->flags[i])
	{
		if (new->flags[i] == '0')
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
	return (sum);
}

t_options		*create_new_option(const char *format, int i)
{
	t_options	*new;

	if ((new = (t_options*)ft_memalloc(sizeof(t_options))) == NULL)
		return (NULL);
	//ft_bzero(new, sizeof(t_options)); kc

	// 0. idx 
		new->index = i;
	// 1. flen
	if ((new->flen = compute_new_option_len_in_format(format, i)) == -1)
		return (NULL);

	// 2. type
	new->type = (new->flen > 0 ? (format[i + new->flen]) : (char)NULL);

	// 3. flags
	if (new->flen > 1)
		new->flags = ft_strsub(format, i + 1, (size_t)(new->flen - 1));

	// 4. fpos dans format
	new->fpos = i;

	// 5. left_justify
	if (new->flen > 1 && ft_strchr_modified(new->flags, '-'))
		new->left_justify = 1;

	// 6. sign =
	if (new->flen > 1 && ft_strchr_modified(new->flags, '+'))
		new->sign = 1;

	if (new->flags && new->flen > 1)
		new->point = ft_strchr_modified(new->flags, '.') ? 1 : 0;
	// 7. space
	if (new->flen > 1 && new->sign != 1 && ft_strchr_modified(new->flags, ' '))
		new->space = 1;

	// 8. #
	if (new->flen > 1 && ft_strchr_modified(new->flags, '#'))
		new->hashtag = 1;

	// 9. 0 -> géré dans le 10. number
	// if (new->flen > 1 && ft_strchr_modified(new->flags, '0'))
	//		new->left_zeros = 1;

	// print_t_option(&new);
	// 10. number
	if (new->flen > 1)
		new->number = extract_number_in_flags(new);
	//printf("flags = %s || ft_atoi flags = %i\n", new->flags, ft_atoi(new->flags));
	// print_t_option(&new);
	//11. et 12 h / hh
	if (new->flen > 1 && ft_strstr_modified(new->flags, "h"))
		new->h = 1;
	//	else if (new->flen > 1 && ft_strchr_modified(new->flags, "hh"))
	//		new->hh = 1;

	// 13. et 14 ll / l
	if (new->flen > 1 && ft_strstr_modified(new->flags, "ll"))
		new->ll = 1;
	else if (new->flen > 1 && ft_strchr_modified(new->flags, 'l'))
		new->l = 1;
	if (new->flen > 1 && ft_strchr_modified(new->flags, 'L'))

		// 15. L
		if (new->flen > 1 && ft_strstr_modified(new->flags, "ll"))
			new->ll = 1;

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

int		extract_options(const char *format, t_options **options)
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
