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

	if (option->ll || option->l)
	{
		if (option->ll)
		{
			n = va_arg(*args, long long);
			// printf("bitchn is %ld\n", n);
			// printf("here2: %d\n", n);
			// printf("here2: %ld\n", n);
			// printf("here2: %lld\n", n);
		}
		else
		{
			// printf("here3");
			n = va_arg(*args, long);
		}
	}
	else if (option->h || option->hh)
	{
		if (option->hh)
			n = (char)va_arg(*args, int); // [%hhd] 128 doit retourner -128 donc j ai tej le unsigned dans (unsigned char)
		else
			n = (short)va_arg(*args, int); // [%hd] 32768 doit retourner -32768 donc j ai tej le unsigned dans (unsigned int)
	}
	else if (option->j)
		n = va_arg(*args, intmax_t);
	else if (option->z)
		n = va_arg(*args, size_t);
	else
			n = va_arg(*args, int);
	// printf("here n = %d\n", n);
	return (n);
}

unsigned long long	get_utype(t_options *option, va_list *args)
{
	unsigned long long n;

	if (option->j)
		n = va_arg(*args, intmax_t);
	else if (option->ll || option->l || option->type == 'p')
	{
		if (option->type == 'x' || option->type == 'X' || option->type == 'o')
		{
				 n = va_arg(*args, long long);
			//printf("value get type%lld", n);
		}
		else if (option->type == 'p' || option->ll)
		{
			n = va_arg(*args, unsigned long long);
			// printf("\n1. n = %llu\n", n);
		}
		else
		{
			// printf("here3");
			n = va_arg(*args, long);
		}
	}
	else if (option->h || option->hh)
	{
		if (option->hh)
			n = (unsigned char)va_arg(*args, int); // [%hhd] 128 doit retourner -128 donc j ai tej le unsigned dans (unsigned char)
		else
			n = (unsigned short)va_arg(*args, int); // [%hd] 32768 doit retourner -32768 donc j ai tej le unsigned dans (unsigned int)
	}
	else
			n = va_arg(*args, unsigned int);
	// printf("here n = %llu\n", n);
	return (n);
}
