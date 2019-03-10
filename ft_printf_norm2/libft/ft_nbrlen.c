/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 08:46:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/13 01:08:20 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long value, int base)
{
	int		len;
	int		neg;

	neg = 0;
	len = 1;
	if (value < 0)
	{
		value = -value;
		neg = 1;
	}
	if (base == 0)
		return (0);
	while (value >= (long long)base)
	{
		len++;
		value /= base;
	}
	return (len);
}
