/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 23:20:01 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/04 22:48:20 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		free_options(t_options **options)
{
	t_options	*tmp;
	t_options	*option;

	option = *options;
	while (option)
	{
		ft_memdel(&(option->flags));
		tmp = option;
		option = option->next;
		ft_memdel((void *)&tmp);
	}
	return (-1);
}
