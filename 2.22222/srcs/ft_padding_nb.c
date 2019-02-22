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
 ** ---------- nb_padding functions selon before/after + left_justify --------------
 */

int		print_sign(t_options *option, int nb)
{
	int		ret;

	ret = 0;
	if (option->type == 'd' || option->type == 'i')
	{
		if (nb < 0)
			ret += ft_putchar_ret('-');
		if (nb >= 0 && option->sign)
			ret += ft_putchar_ret('+');
	}
	return (ret);
}

int		get_sign(t_options *option)
{
	int		ret;

	ret = 0;
	if (option->type == 'd' || option->type == 'i')
	{
		if (!option->neg && option->sign)
			ret += 1;
	}
	return (ret);
}


int		print_zero_padding(t_options *option, int len, int nb) // sert a print les 0 padding en toute circonstances
{
	int		i;
	int		ret;

	i = -1;
	if (option->type != 'd' && option->type != 'i'
			&& (option->hashtag || option->type == 'p'))
	{
		if (option->type != 'o')
			len += 2;
		else if (option->type == 'o' && nb != 0)
			len += 1;
	}
	ret = print_sign(option, nb);
//	printf("\n/********** LEN zero %d %d %d ***********\\\n", len, option->pad_min, get_sign(option));
	if ((option->left_zeros && !option->pad_max) || option->pad_max)
	{
		if (option->pad_max)
			while (++i < option->pad_max - len + (get_sign(option)
						&& !option->left_justify))
				ret += ft_putchar_ret('0');
		else
			while (++i < option->pad_min - len - get_sign(option))
				ret += ft_putchar_ret('0');
	}
	return (ret);
}

int		print_spaces_padding(t_options *option, int len, int nb, int after) // sert a print les spaces padding en toute circonstances
{
	int		i;
	int		ret;
	int		un_space_a_til_ete_print;

	un_space_a_til_ete_print = (option->space && !get_sign(option) && !option->neg) ? 1 : 0;
	len = option->pad_max > len ? option->pad_max : len;
	i = -1;
	ret = 0;
	if (option->type != 'd' && option->type != 'i'
			&& (option->hashtag || option->type == 'p'))
	{
		if (option->type != 'o')
			len += 2;
		else if (option->type == 'o' && nb != 0)
			len += 1;
	}
//	printf("\n/********** FLEM spaces %d***********\\\n", un_space_a_til_ete_print);
	while (++i < option->pad_min - len - get_sign(option) - un_space_a_til_ete_print)
		ret += ft_putchar_ret(' ');
	if (!after && !option->pad_max)
		ret += print_sign(option, nb);
	return (ret);
}
/*
 ** ---------- nb_padding rooter selon before/after + left_justify --------------
 */

int		helper_print_nb_padding(t_options *option, int len, int after, int nb)
{
	int		ret;

//	printf("\n/********** nb/len helper %d || %d***********\\\n", nb, len);
	ret = 0;
	if (after && !option->left_justify)
		return (0);
	if (!after && option->left_justify)
	{
		if ((option->left_zeros && !option->pad_max) || option->pad_max)
			ret += print_zero_padding(option, len, nb);
	}
	else if ((option->left_justify && after)
			|| (option->pad_min && !option->pad_max && !after))
		ret += print_spaces_padding(option, len, nb, after);
	else if (option->pad_min && option->pad_max && !option->left_justify)
	{
		ret += print_spaces_padding(option, len, nb, after);
		ret += print_zero_padding(option, len, nb);
	}
	else if ((option->left_zeros && !option->pad_max)
			|| (option->pad_max && !option->pad_min))
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
	while (++i < (option->pad_min - len - (option->sign || nb < 0)))
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
