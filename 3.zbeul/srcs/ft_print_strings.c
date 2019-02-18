/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:42:57 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/14 09:49:47 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		ft_print_nstr_ret(char *str, int limit)
{
	int		ret;

	ret = limit;
	if (str)
		write(1, str, ret);
	return (ret);
}

int		ft_printf_string(t_options *option, va_list *args)
{
	char	*tmp;
	int		ret;
	int		len;

	if (!(tmp = ft_strdup(va_arg(*args, char*))))
		tmp = ft_strdup("(null)");
	len = (option->pad_max < ft_strlen(tmp)) && option->point ? option->pad_max : ft_strlen(tmp);
	ret = helper_print_str_padding(option, len, 0);
	ret += ft_print_nstr_ret(tmp, len);
	ret += helper_print_str_padding(option, len, 1);
	ft_strdel(&tmp);
	return (ret);
}
