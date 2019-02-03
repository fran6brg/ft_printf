/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:31:13 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/03 09:38:31 by bihattay         ###   ########.fr       */
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
	return (0);
}

int		ft_printf_base(t_options *option, va_list *args)
{
	long long int	value;
	int				base;
	int				ret;

//	print_t_option(&option);
	write(1, "ok inside BASE function : -", 27);
	base = get_base(option);
	value = get_type(option, args);
	if ((option->left_zeros || option->left_justify) && (option->hashtag
					|| option->type == 'p'))
		option->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	ret = helper_print_nb_padding(option, ft_nbrlen(value, base), 0, value);
	if (!option->left_zeros && !option->left_justify && (option->hashtag
			|| option->type == 'p'))
		option->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (option->type == 'p' || option->hashtag)
		ret += ft_print_str_ret("10");
	ret += ft_putnbr_base(value, base, option->type);
	ret += helper_print_nb_padding(option, ft_nbrlen(value, base), 1, value);
	if (option->hashtag || option->type == 'p')
		ret += 2;
	printf("////// RET IN BASE FUNCTION %d ////////\n\n", ret);
//	write(1, "-\n\n", 3);
	return (ret);
}

