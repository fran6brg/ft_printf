/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:50:51 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/17 18:29:57 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		ft_printf_integer(t_options *option, va_list *args)
{
	long long	n;
	int			len;
	int			ret;

	ret = 0;
	n = get_type(option, args);
	len = ft_nbrlen(n, 10) - (n == 0);
	// printf("len =%d ", len);
	if (n < 0)
		option->neg = 1;
// printf("len is %d nb is %lld\n", len, n);
	if (option->space && option->sign == 0 && n >= 0) // si insertion d'un espace
		ret += ft_putchar_ret(' ');
	 // before
	ret += helper_print_nb_padding(option, len - option->space, 0, n);
	if ((n == 0 && !option->point) || n != 0)
		ret += ft_putnbr_base(n, 10, option->type);
	// after
	ret += helper_print_nb_padding(option, len - option->space, 1, n);
//	print_t_option(&option);
	return (ret);
}
