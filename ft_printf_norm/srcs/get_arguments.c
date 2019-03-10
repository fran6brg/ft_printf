/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:04:46 by bihattay          #+#    #+#             */
/*   Updated: 2019/03/06 05:24:58 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

long long	get_type(t_options *option, va_list *args)
{
	long long n;

	if (option->type == 'u' || option->type == 'U')
	{
		if (option->l)
			n = va_arg(*args, unsigned long);
		else if (option->ll)
			n = va_arg(*args, unsigned long long);
		else if (option->j)
			n = va_arg(*args, intmax_t);
		else if (option->type == 'U')
			n = va_arg(*args, unsigned long);
		else
			n = va_arg(*args, unsigned int);
	}
	else if (option->ll || option->l)
	{
		if (option->ll)
			n = va_arg(*args, long long);
		else
			n = va_arg(*args, long);
	}
	else if (option->h || option->hh)
	{
		if (option->hh)
			n = (char)va_arg(*args, int);
		else
			n = (short)va_arg(*args, int);
	}
	else if (option->j)
		n = va_arg(*args, intmax_t);
	else if (option->z)
		n = va_arg(*args, size_t);
	else
			n = va_arg(*args, int);
	return (n);
}

unsigned long long	get_utype(t_options *option, va_list *args)
{
	unsigned long long n;

	if (option->type == 'u' || option->type == 'U')
	{
		if (option->l)
			n = va_arg(*args, unsigned long);
		else if (option->ll)
			n = va_arg(*args, unsigned long long);
		else if (option->j)
			n = va_arg(*args, intmax_t);
		else if (option->type == 'U')
			n = va_arg(*args, unsigned long);
		else
			n = va_arg(*args, unsigned int);
	}
	return (n);
}
