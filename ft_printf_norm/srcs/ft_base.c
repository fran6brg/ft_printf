/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:31:13 by bihattay          #+#    #+#             */
/*   Updated: 2019/03/06 02:54:31 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		get_base(t_options *option)
{
	if (option->type == 'o')
		return (8);
	if (option->type == 'x' || option->type == 'X' || option->type == 'p')
		return (16);
	if (option->type == 'b')
		return (2);
	if (option->type == 'u' || option->type == 'U')
		return (10);
	return (0);
}

int		print_prefix_before(t_options *option)
{
	int		ret;

	ret = 0;
	if (((option->left_zeros || option->left_justify) && ((option->hashtag
						|| option->type == 'p' || option->type == 'b'))))
	{
		if (option->hashtag && option->type != 'b')
		{
			if (option->type == 'o')
				ret += ft_putchar_ret('0');
			else if (option->type == 'X')
				ret += ft_print_nstr_ret("0X", 2);
			else
				ret += ft_print_nstr_ret("0x", 2);
		}
		else
		{
			if (option->type == 'b')
				ret += ft_print_nstr_ret("0b", 2);
			else
				ret += ft_print_nstr_ret("0x", 2);
		}
	}
	return (ret);
}

int		ft_printf_base(t_options *option, va_list *args)
{
	unsigned long value;
	int				base;
	int				ret;
	int				len;

	ret = 0;
	base = get_base(option);
	value = (option->type == 'u' || option->type == 'U') ? get_utype(option, args) : get_type(option, args);
	len = ft_nbrlen(value, base);
	if (option->space && option->sign == 0)
		if (option->type != 'u' && option->type != 'U')
			ret += ft_putchar_ret(' ');
	if ((value == 0 && !option->pad_deux && option->point && option->type != 'p')
		|| (value == 0 && option->type == 'o' && option->hashtag))
		len = 0;
	ret += helper_print_nb_padding(option, len, 0, value);
	if (!(value == 0 && !option->pad_deux && option->point && (option->type != 'p')))
		if (!(value == 0 && option->type == 'o' && option->hashtag))
			ret += ft_putnbr_base(value, base, option->type);
	ret += helper_print_nb_padding(option, len, 1, value);
	return (ret);
}
