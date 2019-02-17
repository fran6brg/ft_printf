/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:26:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/14 13:25:42 by bihattay         ###   ########.fr       */
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
	while (++i < option->pad_max - (len + neg))
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
 ** ---------- nb_padding functions selon before/after + left_justify --------------
 */

int		print_sign(t_options *option, int nb)
{
	int		ret;

	ret = 0;
	if (nb < 0)
		ret += ft_putchar_ret('-');
	if (nb >= 0 && option->sign)
		ret += ft_putchar_ret('+');
	return (ret);
}

int		print_zero_padding(t_options *option, int len, int nb) // sert a print les 0 padding en toute circonstances
{
	int		i;
	int		ret;

	i = -1;
	if (option->type != 'd' && option->type != 'i')
		len -= 2; // pourquoi ?
	ret = print_sign(option, nb);
	if ((option->left_zeros && !option->pad_min) || option->pad_min)
	{
		if (option->pad_min)
			while (++i < option->pad_min - len + ((nb < 0 || (option->sign
								&& nb >= 0)) && !option->left_justify))
				ret += ft_putchar_ret('0');
		else
			while (++i < option->pad_max - len - (option->neg
						|| (option->sign && nb >= 0)))
				ret += ft_putchar_ret('0');
	}
	return (ret);
}

int		print_spaces_padding(t_options *option, int len, int nb, int after) // sert a print les spaces padding en toute circonstances
{
	int		i;
	int		ret;
	int		flem;

	flem = (option->space && !(nb < 0 || (option->sign && nb >= 0))) ? 1 : 0;
	len = option->pad_min > len ? option->pad_min + option->neg : len;
	i = -1;
	ret = 0;
	while (++i < option->pad_max - len - (option->sign && nb >= 0) - flem)
		ret += ft_putchar_ret(' ');
	if (!after && !option->pad_min && (option->type == 'd' || option->type == 'i'))
		ret += print_sign(option, nb);
	return (ret);
}
/*
 ** ---------- nb_padding rooter selon before/after + left_justify --------------
 */

int		helper_print_nb_padding(t_options *option, int len, int after, int nb)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
//	len = option->type == 'p' ? len + 2 : len;
	if (after && !option->left_justify)
		return (0);
	if (!after && option->left_justify) // [nbb:space]
	{
		if ((option->left_zeros && !option->pad_min) || option->pad_min) // [000:nbb:space]
			ret += print_zero_padding(option, len, nb);
	}
	else if ((option->left_justify && after) || (option->pad_max && !option->pad_min && !after)) // [?:nba:space]
		ret += print_spaces_padding(option, len, nb, after);
	else if (option->pad_max && option->pad_min && !option->left_justify) // [space:0:nba?]
	{
		ret += print_spaces_padding(option, len, nb, after);
		ret += print_zero_padding(option, len, nb);
	}
	else if ((option->left_zeros && !option->pad_min) || (option->pad_min && !option->pad_max)) // [nba:space]
		ret += print_zero_padding(option, len, nb);
	else
		ret += print_sign(option, nb);
	return (ret);
}

/*
int		helper_print_nb_padding(t_options *option, int len, int after, int nb)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if ((!after && option->left_justify) || (after && !option->left_justify))
		return (0);
	if (option->type == 'p' || (option->type == 'o' && option->hashtag))
		len += (option->type == 'p') ? 4 : 1;
	else if (option->hashtag && (option->type == 'x' || option->type == 'X'))
		len += 2;
	while (++i < (option->pad_max - len - (option->sign || nb < 0)))
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
} */
