/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:52:38 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/06 07:08:39 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		helper_floats(t_options *option, int len, int after, int neg)
{
	int		ret;
	int		i;

	i = -1;
	ret = 0;
	if ((!after && option->left_justify) || (after && !option->left_justify))
		return (0);
	if (option->left_zeros && !option->left_justify)
		if (option->sign || neg == 1)
			ret += ft_putchar_ret(neg == 1 ? '-' : '+');
	while (++i < option->pad_un - (len + neg))
	{
		if (option->left_zeros && !option->left_justify)
			ret += ft_putchar_ret('0');
		else
			ret += ft_putchar_ret(' ');
	}
	if (!option->left_zeros)
		if (option->sign || neg == 1)
			ret += ft_putchar_ret(neg == 1 ? '-' : '+');
	return (ret);
}

int 	helper_precision(long double nbr, int precision, int ret)
{
	int i;

	i = -1;
	while (++i < precision)
	{
		nbr *= 10;
		if (!((precision - i) == 1))
		{
			ret += ft_putchar_ret((int)nbr + '0');
			nbr -= (int)nbr;
		}
	}
	return (ret);
}

int		ft_printf_floats(t_options *opt, va_list *args)
{
	long double		nbr;
	int				precision;
	int				nbri;
	int				i;
	int				ret;

	precision = (opt->pad_deux ? opt->pad_deux : 6);
	nbr = va_arg(*args, double);
	opt->neg = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? -nbr : nbr;
	nbri = (int)nbr;
	ret = helper_floats(opt, precision + ft_nbrlen(nbri, 10) + 1, 0, opt->neg);
	ret += ft_putnbr_base(nbri, 10, 'f');
	ret += ft_putchar_ret('.');
	nbr -= (long double)nbri;
	ret = helper_precision(nbr, precision, ret);
	ret += ft_putchar_ret(nbr + 0.5 + '0');
	ret += helper_floats(opt, precision + ft_nbrlen(nbri, 10) + 1, 1, opt->neg);
	return (ret);
}
