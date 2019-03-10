/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:42:55 by fberger           #+#    #+#             */
/*   Updated: 2019/03/06 05:28:31 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base(unsigned long long int value, int b, int specifier)
{
	char					c;
	char					a;
	unsigned long long int	nb;
	static int				ret = 0;

	// printf("\n2. value = %lld\n", value);
	ret -= ret;
	nb = value;
	a = specifier == 'X' ? 'A' : 'a';
	if (b < 2 || b > 16)
		return (0);
	// if (value < 0)
	// {
		// if (b == 16)
		// 	nb = ULLONG_MAX + 1 + value;
		// // nb = 18446744073709551615 + (value + 1);
		// else
	//		nb = -value;
		// printf("\n3. nb = %lld\n", nb);
//	}
	if (nb >= (unsigned long long)b)
		ft_putnbr_base(nb / b, b, specifier);
	c = (nb % b < 10) ? (nb % b) + '0' : (nb % b) + (a - 10);
	ft_putchar(c);
	ret += 1;
	return (ret);
}
