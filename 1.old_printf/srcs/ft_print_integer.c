/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:50:51 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/03 10:21:44 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		ft_printf_integer(t_options *option, va_list *args)
{
	long long	n;
	long long	nb;
	int			len;
	int			ret;

	ret = 0;
	n = get_type(option, args);
	nb = n >= 0 ? n : -n;
	len = 0;
	len = ft_nbrlen(nb, 10);
	if (!option->pad_min && (option->sign || n < 0) && option->left_zeros)
		ret += ft_putchar_ret((n < 0) ? '-' : '+');
	ret += helper_print_nb_padding(option, len, 0, n);
	if (option->space && option->sign == 0 && n > 0) // (space) If no sign is going to be written, a blank space is inserted before the value.
		ret += ft_putchar_ret(' ');
	else if (!option->pad_min && (option->sign || n < 0) && !option->left_zeros)
		ret += ft_putchar_ret((n < 0) ? '-' : '+');
	ret += ft_putnbr_base(n, 10, option->type);
	ret += helper_print_nb_padding(option, len, 1, n);
	return (ret);
}
