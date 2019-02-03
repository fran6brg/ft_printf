/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:26:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/02 21:54:24 by bihattay         ###   ########.fr       */
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
	while(++i < option->number - len)
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

	i = -1;
	ret = 0;
	// before
	// after
	// left_justify
	// sign +
	// le vrai
	if ((!after && option->left_justify) || (after && !option->left_justify))
		return (0);
	if (option->hashtag || option->type == 'p')
		len += 4;
	while(++i < (option->number - len - (option->sign || nb < 0)))
	{
		if (option->left_zeros && !option->left_justify)
		{
			if (i == 0 && nb >= 0 && (option->type == 'd'
						|| option->type == 'i'))
				i++;
			else
				ret += ft_putchar_ret('0');
		}
		else
			ret += ft_putchar_ret(' ');
	}
	return (ret);
}

