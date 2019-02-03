/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:41:13 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/02 23:28:57 by bihattay         ###   ########.fr       */
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
//	write(1, "ok modulo final function : -", 28);

	ft_putchar('%');

//	write(1, "-\n\n", 3);
	return (1);
}

int		ft_printf_char(t_options *option, va_list *args)
{
//	print_t_option(&option);
//	write(1, "ok inside CHARACTER function : -", 32);

	helper_print_str_padding(option, 1, 0); // imprimer avant si sign == 0
	ft_putchar(va_arg(*args, int));
	helper_print_str_padding(option, 1, 1); // imprimer apres si sign == 1

//	write(1, "-\n\n", 3);
	return (1);
}


