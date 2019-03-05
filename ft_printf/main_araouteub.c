/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:06:31 by araout            #+#    #+#             */
/*   Updated: 2019/02/14 12:37:41 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/functions.h"

int main(void)
{
	char *test1 = "lololol";
	int test2;
	int	test3;
	double test4;

	test4 = 121312.44432414454;
	test3 = -12;
	ft_printf("%lld\n", 18446744065119617025LL);
//	printf("%p", test1);
	/*test1 = "BONJOUR%d";
	test2 = printf("printf : %s OKOK\n", test1);
	printf("printf :  %d OKOK\n", test2);
	printf("printf i : %i OKOK\n", test2);
	printf("printf signed u : %u OKOK\n", test3);
	printf("printf u : %u OKOK\n", test2);
	printf("printf o  : %o OKOK\n", test2);
	printf("printf signed o  : %o OKOK\n", test3);
	printf("printf signed x : %x OKOK\n", test3);
	printf("printf x  : %x OKOK\n", test2);
	printf("printf c : %c OKOK\n", *test1);
	printf("printf signed c : %c OKOK\n", test3);
	printf("printf f : %f OKOK\n", test4);
	printf("printf lf : %lf OKOK\n", test4);
	printf("printf llf : %llf OKOK\n", test4);
	printf("printf hf : %hf OKOK\n", test4);
	printf("printf e : %e OKOK\n", test4);
	printf("++++++++++++++++++++++++++++++++++++\n");
	ft_printf("ft_printf  : %s OKOK\n", test1);
	ft_printf("ft_printf :  %d OKOK\n", test2);
	ft_printf("ft_printf i : %i OKOK\n", test2);
	ft_printf("ft_printfi signed u : %u OKOK\n", test3);
	ft_printf("ft_printf u : %u OKOK\n", test2);
	ft_printf("ft_printf o  : %o OKOK\n", test2);
	ft_printf("ft_printf signed o  : %o OKOK\n", test3);
	ft_printf("ft_printf signed x  : %x OKOK\n", test3);
	ft_printf("ft_printf x  : %x OKOK\n", test2);
	ft_printf("ft_printf c : %c OKOK\n", *test1);
	ft_printf("ft_printf signed c : %c OKOK\n", test3);
	ft_printf("ft_printf f : %f OKOK\n", test4);
	ft_printf("ft_printf lf : %lf OKOK\n", test4);
	ft_printf("ft_printf llf : %llf OKOK\n", test4);
	ft_printf("ft_printf hf : %hf OKOK\n", test4);
	ft_printf("ft_printf e : %e OKOK\n", test4);
	*/
	return (0);
}
