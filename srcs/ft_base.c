/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:31:13 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/03 12:29:48 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int				get_base(t_options *option)
{
	if (option->type == 'o')
		return (8);
	if (option->type == 'x' || option->type == 'X' || option->type == 'p')
		return (16);
	if (option->type == 'b')
		return (2);
	return (0);
}

int		print_prefix(t_options *option, int moment)
{
	int		ret;

	ret = 0;
	if (!moment && ((option->left_zeros || option->left_justify) && ((option->hashtag
					|| option->type == 'p' || option->type == 'b'))))
	{
		if (option->hashtag)
		{
			if (option->type == 'o')
				ret += ft_putchar_ret('0');
			else if (option->type == 'x')
				ret += ft_print_str_ret("0x");
			else if (option->type == 'X')
				ret += ft_print_str_ret("0X");
		}
		else
		{
			if (option->type == 'b')
				ret += ft_print_str_ret("0b");
			else
				ret += ft_print_str_ret("0x");
		}
	}
	if (moment && (!option->left_zeros && !option->left_justify && (option->hashtag
			|| option->type == 'p' || option->type == 'b')))
		{
		if (option->hashtag)
		{
			if (option->type == 'o')
				ret += ft_putchar_ret('0');
			else if (option->type == 'x')
				ret += ft_print_str_ret("0x");
			else if (option->type == 'X')
				ret += ft_print_str_ret("0X");
		}
		else
		{
			if (option->type == 'b')
				ret += ft_print_str_ret("0b");
			else
				ret += ft_print_str_ret("0x");
		}
	}
	return (ret);
}

int				ft_printf_base(t_options *option, va_list *args)
{
	long long int	value;
	int				base;
	int				ret;

	ret = 0;
	base = get_base(option);
	value = get_type(option, args);
	ret += print_prefix(option, 0);
	ret += helper_print_nb_padding(option, ft_nbrlen(value, base) + ret, 0, value);
	ret += print_prefix(option, 1);
	if (option->type == 'p')
		ret += ft_print_str_ret("10");
	ret += ft_putnbr_base(value, base, option->type);
	ret += helper_print_nb_padding(option, ft_nbrlen(value, base), 1, value);
	return (ret);
}
