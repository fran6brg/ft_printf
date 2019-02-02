/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 08:46:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/02 09:46:59 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(unsigned long long value, int base)
{
	int		len;

	len = 1;
	if (base == 0)
		return (0);
	while (value >= (unsigned long long)base)
	{
		len++;
		value /= base;
	}
	return (len);
}
