/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:04:46 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/02 21:15:50 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

long long	get_type(t_options *option, va_list *args)
{
	long long	n;

	if (option->ll)
		n = va_arg(*args, long long);
	else if (option->l)
		n = va_arg(*args, long);
	else
		n = va_arg(*args, int);
	return (n);
}
