/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:26:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/06 07:07:40 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

/*
** ----------------------------- nb_padding before -----------------------------
*/

int		helper_print_nb_padding_is_b_is_lj(t_options *option, int len, int after, int nb)
{
		// normalement rien a faire
}

int		helper_print_nb_padding_is_b_not_lj(t_options *option, int len, int after, int nb)
{
}

/*
** ----------------------------- nb_padding after ------------------------------
*/

int		helper_print_nb_padding_depending_on_lj(t_options *option, int len, int after, int nb)
{
	int		i;
	int		ret;

	if (option->type == 'p' || (option->type == 'o' && option->hashtag))
		len += (option->type == 'p') ? 4 : 1;
	else if (option->hashtag && (option->type == 'x' || option->type == 'X'))
		len += 2;
	i = -1;
	ret = 0;
	//printf("len %i\n", len);
	//printf("here i < %i\n", option->pad_max - len - (option->sign || nb < 0));
	while (++i < (option->pad_max - len - (option->sign || nb < 0)))
	{
		if ((option->left_zeros && !option->left_justify) || option->point)
		{
			// je comprends pas à quoi sert cette condition ?
			// if (i == 0 && nb >= 0 && (option->type == 'd' || option->type == 'i'))
			// 	i++;
			// else
			if (/*option->pad_min == 0 ||*/ (option->pad_max - i) > option->pad_min) // ok good
			{
				if ((option->pad_max - (i + 1)) == option->pad_min && nb < 0)
					ret += ft_putchar_ret('-');
				else
					ret += ft_putchar_ret(' ');
			}
			else
				ret += ft_putchar_ret('0'); // ok good
		}
		else
			ret += ft_putchar_ret(' ');
	}
}

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
	while (++i < option->pad_min - (len + neg))
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

/*
** ---------- nb_padding rooter selon before/after + left_justify --------------
*/

int		helper_print_nb_padding(t_options *option, int len, int after, int nb)
{
	if ((!after && option->left_justify) || (after && !option->left_justify))
		return (0);
	if (option->left_justify == 0) // aligné à droite
	{
			return (helper_print_nb_padding_depending_on_lj(option, len, after, nb));
	}
	else if (option->left_justify == 1) // aligné à gauche
	{
			return (helper_print_nb_padding_depending_on_lj(option, len, after, nb));
	}
	else
		;
}
