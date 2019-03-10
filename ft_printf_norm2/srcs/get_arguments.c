/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:04:46 by bihattay          #+#    #+#             */
/*   Updated: 2019/03/10 07:24:50 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

long long				get_type_bis(t_options *option, va_list *args)
{
	long long	n;

	if (option->ll || option->l)
	{
		if (option->ll)
			n = va_arg(*args, long long);
		else
			n = va_arg(*args, long);
	}
	else if (option->hh || option->h)
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

long long				get_type(t_options *option, va_list *args)
{
	long long	n;

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
	else
		n = get_type_bis(option, args);
	return (n);
}

unsigned long long		get_utype(t_options *option, va_list *args)
{
	unsigned long long	n;

	if (option->j)
		n = va_arg(*args, intmax_t);
	else if (option->ll || option->l || option->type == 'p')
	{
		if (option->type == 'x' || option->type == 'X' || option->type == 'o')
			n = va_arg(*args, long long);
		else if (option->type == 'p' || option->ll)
			n = va_arg(*args, unsigned long long);
		else
			n = va_arg(*args, long);
	}
	else if (option->h || option->hh)
	{
		if (option->hh)
			n = (unsigned char)va_arg(*args, int);
		else
			n = (unsigned short)va_arg(*args, int);
	}
	else
		n = va_arg(*args, unsigned int);
	return (n);
}
