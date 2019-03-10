/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 02:59:11 by fberger           #+#    #+#             */
/*   Updated: 2019/03/06 03:21:01 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/t_options.h"
#include "../includes/t_functions_pointers.h"
#include "../includes/functions.h"

t_functions_pointers	fp[NB_ACCEPTED_OPTIONS] =
{
	{'c', &ft_printf_char},
	{'s', &ft_printf_string},
	{'p', &ft_printf_base},
	{'d', &ft_printf_integer},
	{'i', &ft_printf_integer},
	{'o', &ft_printf_base},
	{'u', &ft_printf_base},
	{'U', &ft_printf_base},
	{'x', &ft_printf_base},
	{'X', &ft_printf_base},
	{'b', &ft_printf_base},
	{'f', &ft_printf_floats},
	{'%', &ft_printf_modulo},
};

int		root_options_printers(t_options *option, va_list *args)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < NB_ACCEPTED_OPTIONS)
	{
		if (fp[i].option == option->type)
		{
			if ((ret = fp[i].function(option, args)) == -1)
				return (-1);
			return (ret);
		}
		i++;
	}
	return (0);
}

int		no_opts_prntrs(t_options *options, const char *format, const int len)
{
	static int		idx = 0;
	int				ret;

	ret = options != NULL ? options->index - idx : len - idx;
	if (format + idx)
		write(1, format + idx, ret);
	idx += ret;
	if (options != NULL)
		idx += options->flen + 1;
	else
		idx = 0;
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_options	*options;
	t_options	*option;
	const int	formatlen = ft_strlen(format);
	int			ret;

	if (format == NULL)
	{
		ret = ft_printf_string(NULL, NULL);
		return (ret);
	}
	options = NULL;
	if (extract_options(format, &options) == -1)
		return (-1);
	va_start(args, format);
	option = options;
	ret = 0;
	while (option != NULL)
	{
		ret += no_opts_prntrs(option, format, formatlen);
		ret += root_options_printers(option, &args);
		option = option->next;
	}
	ret += no_opts_prntrs(NULL, format, formatlen);
	va_end(args);
	return (ret);
}
