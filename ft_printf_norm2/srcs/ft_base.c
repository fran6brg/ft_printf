/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:31:13 by bihattay          #+#    #+#             */
/*   Updated: 2019/03/10 06:17:52 by fberger          ###   ########.fr       */
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

int		ft_printf_base(t_options *opt, va_list *args)
{
	unsigned long	value;
	int				base;
	int				ret;
	int				len;

	ret = 0;
	base = get_base(opt);
	if (opt->type == 'u' || opt->type == 'U')
		value = get_type(opt, args);
	else
		value = get_utype(opt, args);
	len = ft_nbrlen(value, base);
	if (opt->space && opt->sign == 0 && opt->type != 'u' && opt->type != 'U')
		ret += ft_putchar_ret(' ');
	if ((value == 0 && !opt->pad_deux && opt->point && opt->type != 'p')
		|| (value == 0 && opt->type == 'o' && opt->hashtag))
		len = 0;
	ret += helper_nb_pad(opt, len, 0, value);
	if (!(value == 0 && !opt->pad_deux && opt->point && (opt->type != 'p')))
		if (!(value == 0 && opt->type == 'o' && opt->hashtag))
			ret += ft_putnbr_base(value, base, opt->type);
	ret += helper_nb_pad(opt, len, 1, value);
	return (ret);
}
