/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:26:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/03 12:44:50 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		helper_print_str_padding(t_options *option, int len, int after)
{
	int		i;
	int		ret;

	ret = 0;
	i = -1;
	if (((!after && option->left_justify) || (after && !option->left_justify))
			|| (option->point && (option->number > len)))
		return (0);
	while (++i < option->number - len)
	{
		if (option->left_zeros && !option->left_justify)
			ret += ft_putchar_ret('0');
		else
			ret += ft_putchar_ret(' ');
	}
	return (ret);
}

int		helper_print_nb_padding(t_options *option, int len, int after, int nb)
{
	int		i;
	int		ret;

	if ((!after && option->left_justify) || (after && !option->left_justify))
		return (0);
	if (option->type == 'p' || (option->type == 'o' && option->hashtag))
		len += (option->type == 'p') ? 4 : 1;
	else if (option->hashtag && (option->type == 'x' || option->type == 'X'))
		len += 2;
	i = -1;
	ret = 0;
	//printf("here i < %i\n", option->number - len - (option->sign || nb < 0));
	while (++i < (option->number - len - (option->sign || nb < 0)))
	{
		if ((option->left_zeros && !option->left_justify) || option->point)
		{
			// if (i == 0 && nb >= 0 && (option->type == 'd' || option->type == 'i'))
			// 	i++;
			// else
			// je comprends pas à quoi ca sert cette condition ?
				ret += ft_putchar_ret('0');
		}
		else
			ret += ft_putchar_ret(' ');
	}
	if (option->space && !option->sign) // (space) If no sign is going to be written, a blank space is inserted before the value.
			ret += ft_putchar_ret(' ');
	return (ret);
}
