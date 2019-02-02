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
	if (t > 0)
	{
			// c = (t % b < 10) ? (t % b) + '0' : (t % b) + (d - 10);
			// printf("t = %llu || c = %c\n", t, c);
			if (t < (unsigned long long)b)
				write(1, "1", 1);
			ft_putnbr_base(t / b, b, x);
	}
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

/*static char		*get_base(char c)
{
	if (c == 'b')
		return ("01");
	else if (c == 'o')
		return ("01234567");
	else if (c == 'x')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0");
}

// void		ft_putnbr_hexa(unsigned long nbr, char c, int **ret)
// void		ft_putnbr_base(unsigned long nbr, char c, int **ret) libft.h
// void		ft_putnbr_base(long long int value, int b, int x) alamorth

// ft_putnbr.c:68:8: error: conflicting types for 'ft_putnbr_base'
// void                    ft_putnbr_base(unsigned long nbr, char c, int **ret)
//                         ^
// ./libft.h:32:9: note: previous declaration is here
// void                            ft_putnbr_base(long long value, int base, int x);

void			ft_putnbr_base_bis(unsigned long value, char b, int **ret)
{
	char	*base;
	int		i;
	char	res[32];

	i = 31;
	base = get_base(c);
	printf("taille de la base = %zu\n", ft_strlen(base));
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		**ret += 1;
	}
	while (nbr > 0)
	{
		res[i] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
		i--;
		**ret += 1;
	}
	if (c == 'p')
	{
		write(1, "0x", 2);
		**ret += 2;
	}
	while (++i < 32)
		ft_putchar(res[i]);
}*/
