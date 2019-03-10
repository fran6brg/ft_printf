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

int		print_sign(t_options *option, long long nb)
{
	int		ret;

	ret = 0;
	if (!option->sign_is_print && (option->type == 'd' || option->type == 'i'))
	{
		if (nb < 0)
		{
			ret += ft_putchar_ret('-');
			option->sign_is_print = 1;
		}
		if (nb >= 0 && option->sign)
		{
			ret += ft_putchar_ret('+');
			option->sign_is_print = 1;
		}
	}
	return (ret);
}

int		nb_have_a_sign(t_options *option, long long nb)
{
	int		ret;

	ret = 0;
	if (option->type == 'd' || option->type == 'i')
		if ((option->neg) || (!option->neg && option->sign && nb >= 0))
			ret = 1;
	return (ret);
}

int		nb_have_a_prefix(t_options *option, long long value, int len)
{
	int ret;

	ret = 0;
	if (len != -125)
		if (option->type == 'o' && option->pad_deux > len)
	 		return (0);
	if (len != -125 && option->type == 'o'
			&& option->hashtag && value == 0 && !option->pad_un)
		return (0);
	if (option->hashtag || option->type == 'p')
	{
		if (value == 0 && option->type != 'p' && option->type != 'o')
			return (0);
		if (option->type == 'o')
			ret += 1;
		else if (option->type == 'x' || option->type == 'X' || option->type == 'p')
			ret += 2;
	}
	return (ret);
}

int		print_prefix(t_options *option, long long value)
{
	int 	prefix_size;

	prefix_size = 0;
	if ((prefix_size = nb_have_a_prefix(option, value, -125)) > 0)
	{
		if (prefix_size == 1)
			write(1, "0", 1);
		else
		{
			if (option->type == 'X')
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
		}
	}
	return (prefix_size);
}

int 	ft_print_loop_ret(char c, int nb)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (nb-- > 0)
		ret += ft_putchar_ret(c);
	return (ret);
}
