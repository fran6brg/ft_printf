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

int		ft_printf_floats(t_options *option, va_list *args)
{
	long double		nbr;
	int				precision;
	int				nbr_to_int;
	int				i;
	int				ret;

	precision = (option->pad_min ? option->pad_min : 6);
	nbr = va_arg(*args, double);
	option->neg = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? -nbr : nbr;
	nbr_to_int = (int)nbr;
	ret = helper_print_floats_padding(option, precision + ft_nbrlen(nbr_to_int, 10) + 1, 0, option->neg);
	ret += ft_putnbr_base(nbr_to_int, 10, 'f');
	ret += ft_putchar_ret('.');
	nbr -= (long double)nbr_to_int;
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
	ret += ft_putchar_ret(nbr + 0.5 + '0');
	ret += helper_print_floats_padding(option, precision + ft_nbrlen(nbr_to_int, 10) + 1, 1, option->neg);
	return (ret);
}
