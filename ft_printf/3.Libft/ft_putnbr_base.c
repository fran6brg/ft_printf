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

int		ft_putnbr_base(long long int value, int b, int specifier)
{
	char					c;
	char					a;
	unsigned long long int	nb;
	static int				ret = 0;

	ret -= ret;
	nb = value;
	a = specifier == 'X' ? 'A' : 'a';
	if (b < 2 || b > 16)
		return (0);
	if (value < 0)
		nb = -value;
	if (nb >= (unsigned long long)b)
		ft_putnbr_base(nb / b, b, specifier);
	c = (nb % b < 10) ? (nb % b) + '0' : (nb % b) + (a - 10);
	ret += ft_putchar_ret(c);
	return (ret);
}
