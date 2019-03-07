/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:41:13 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/14 10:54:58 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		ft_putchar_ret(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_printf_modulo(t_options *option, va_list *args)
{
	int		ret;

	ret = helper_print_str_padding(option, 1, 0);
	ft_putchar('%');
	ret += helper_print_str_padding(option, 1, 1);
	return (1);
}

int		ft_printf_char(t_options *option, va_list *args)
{
	int		ret;

	ret = helper_print_str_padding(option, 1, 0);
	ret += ft_putchar_ret(va_arg(*args, int));
	ret += helper_print_str_padding(option, 1, 1);
	return (ret);
}
