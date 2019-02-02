/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:42:55 by fberger           #+#    #+#             */
/*   Updated: 2019/02/02 13:11:56 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long int value, int b, int x)
{
	char					c;
	char					d;
	unsigned long long int	t;

	t = value;
	d = x == 'X' ? 'A' : 'a';
	if (b < 2 || b > 16)
		return ;
	if (value < 0)
		t = -value;
	if (t >= (unsigned long long)b)
		ft_putnbr_base(t / b, b, x);
	c = (t % b < 10) ? (t % b) + '0' : (t % b) + (d - 10);
	write(1, &c, 1);
}

void	ft_putnbr(long long nb)
{
	unsigned long long int	nbr;

	nbr = nb;
	if (nb < 0)
		nbr = -nbr;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
