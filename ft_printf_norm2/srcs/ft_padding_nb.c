/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:26:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/17 18:22:04 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		ft_swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int		helper_nb_pad(t_options *option, int len, int after, long long nb)
{
	int		ret;
	int		spaces;
	int		zeros;

	ret = 0;
	spaces = option->pad_un - ft_max(option->pad_deux, len)
	- nb_have_a_sign(option, nb) - nb_have_a_prefix(option, nb, len);
	zeros = option->pad_deux - len;
	if (option->left_zeros && !option->point && !option->left_justify && !after)
		ft_swap_int(&zeros, &spaces);
	if (!after && !option->left_justify)
		ret += ft_print_loop_ret(' ', spaces);
	if (!after && option->space && !nb_have_a_sign(option, nb)
	&& option->pad_un <= option->pad_deux)
		if (option->type != 'u' && option->type != 'U')
			ret += ft_putchar_ret(' ');
	if (!after && !(option->type == 'o' && option->pad_deux > len))
		ret += print_prefix(option, nb);
	ret += (!after) ? print_sign(option, nb) : 0;
	ret += (!after) ? ft_print_loop_ret('0', zeros) : 0;
	if (after && option->left_justify)
		ret += ft_print_loop_ret(' ', spaces);
	return (ret);
}
