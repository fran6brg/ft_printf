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
	// printf("n is %ld\n", n);
	len = ft_nbrlen(n, 10) - (n == 0); // ok
	// printf("(1) len =%d ", len);
	if (n < 0)
	{
		// printf("neggg\n");
		option->neg = 1;
	}
	// before
	ret += helper_print_nb_padding(option, len, 0, n);
	if ((n == 0 && !option->point) || n != 0)
		ret += ft_putnbr(n);
	// after
	ret += helper_print_nb_padding(option, len, 1, n);
//	print_t_option(&option);
	return (ret);
}
