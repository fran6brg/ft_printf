/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:04:46 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/17 16:56:10 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

long long	get_type(t_options *option, va_list *args)
{
	long long	n;

	if (option->ll || option->l || option->type == 'p')
	{
		if (option->type == 'x' || option->type == 'X'
				|| option->type == 'p' || option->type == 'o')
		{
			// printf("here1");
			n = va_arg(*args, unsigned long);
		}
		else if (option->ll)
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
			n = (unsigned char)va_arg(*args, int);
		else
			n = (unsigned short)va_arg(*args, int);
	}
	else if (option->type == 'd' || option->type == 'd')
		n = va_arg(*args, int);
	else
		n = va_arg(*args, unsigned int);
	return (n);
}
