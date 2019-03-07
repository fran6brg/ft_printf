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

/*
 ** ---------- float_padding printer   ----------------------------------------
 */

int		helper_print_floats_padding(t_options *option, int len, int after, int neg)
{
	int		ret;
	int		i;

	i = -1;
	ret = 0;
	if ((!after && option->left_justify) || (after && !option->left_justify))
		return (0);
	//	printf("\n WERE EEEEHERE %d\n\n", neg);
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

int		helper_print_nb_padding(t_options *option, int len, int after, long long nb)
{
	int		ret;
	int		spaces;
	int 	zeros;

	ret = 0;
	spaces = option->pad_un - ft_max(option->pad_deux, len) - nb_have_a_sign(option, nb) - nb_have_a_prefix(option, nb, len);
	zeros = option->pad_deux - len;
	// printf("\n******* option(\"%s\") *****\n", option->flags);
	// printf("1. zeros_to_print          = %i\n", zeros);
	// printf("2. spaces_to_print         = %i\n", spaces);
	// printf("3. left_justify            = %d\n", option->left_justify);
	// printf("4. after                   = %d\n", after);
	// printf("5. option->space           = %d\n", option->space);
	// printf("6. sign                    = %d\n", option->sign);
	// printf("7. pad_un                  = %d\n", option->pad_un);
	// printf("8. pad_deux                = %d\n", option->pad_deux);
	// printf("9. value                   = %lld\n", nb);
	// printf("10. len                    = %d\n", len);
	// printf("**********  end  **********\n\n");
	if (option->left_zeros && !option->point && !option->left_justify)
	{
		if (!after)
		{
	//		printf("TEMRE");
			zeros = spaces;
			spaces = 0;
		}
	}
	if (!after && !option->left_justify)
		ret += ft_print_loop_ret(' ', spaces);
	if (!after && option->space && !nb_have_a_sign(option, nb) && option->pad_un <= option->pad_deux)
		ret += ft_putchar_ret(' ');
	if (!after)
	{
		if (!(option->type == 'o' && option->pad_deux > len))
			ret += print_prefix(option, nb);
		ret += print_sign(option, nb);
		ret += ft_print_loop_ret('0', zeros);
	}
	if (after && option->left_justify)
		ret += ft_print_loop_ret(' ', spaces);
	return (ret);
}
