/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 02:59:11 by fberger           #+#    #+#             */
/*   Updated: 2019/02/02 13:33:54 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/t_options.h"
#include "../includes/t_functions_pointers.h"
#include "../includes/functions.h"
#include "../3.Libft/libft.h"
/*
 ** functions pointer -----------------------------------------------------------
 */

void helper_print_str_padding(t_options *option, int len, int after)
{
	int i;

	i = -1;
	if (((!after && option->left_justify) || (after && !option->left_justify))
			|| (option->point && (option->number > len)))
		return ;
	while(++i < option->number - len)
	{
		if (option->left_zeros && !option->left_justify)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

void helper_print_nb_padding(t_options *option, int len, int after, int nb)
{
	int i;

	i = -1;
	// before
	// after
	// left_justify
	// sign +
	// le vrai
	if ((!after && option->left_justify) || (after && !option->left_justify))
		return ;
//	if (!after && (option->left_zeros || option->left_justify) && option->hashtag)
//		write(1, "10", 2);
//	else if ()
	while(++i < (option->number - len - (option->sign || nb < 0)))
	{
		if (option->left_zeros && !option->left_justify)
		{
			if (i == 0 && nb >= 0 && (option->type == 'd'
						|| option->type == 'i'))
				i++;
			else
				ft_putchar('0');
		}
		else
			ft_putchar(' ');
	}
}

/*
 ** functions pointer -----------------------------------------------------------
 */

int ft_printf_char(t_options *option, va_list *args)
{
	print_t_option(&option);
	write(1, "ok inside CHARACTER function : -", 32);

	helper_print_str_padding(option, 1, 0); // imprimer avant si sign == 0
	ft_putchar(va_arg(*args, int));
	helper_print_str_padding(option, 1, 1); // imprimer apres si sign == 1

	write(1, "-\n\n", 3);
	return (1);
}

int ft_printf_string(t_options *option, va_list *args)
{
	char *tmp;

	print_t_option(&option);
	write(1,"ok inside STRING function : -", 29);

	if (!(tmp = ft_strdup(va_arg(*args, char*))))
		return (-1);
	helper_print_str_padding(option, ft_strlen(tmp), 0);
	ft_putstr(tmp);
	helper_print_str_padding(option, ft_strlen(tmp), 1);
	ft_strdel(&tmp);

	write(1, "-\n\n", 3);
	return (1);
}

long long	get_integer_type(t_options *option, va_list *args)
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

int		get_base(t_options *option)
{
	if (option->type == 'o')
		return (8);
	if (option->type == 'x' || option->type == 'X' || option->type == 'p')
		return (16);
	if (option->type == 'b')
		return (2);
	return (0);
}

int ft_printf_base(t_options *option, va_list *args)
{
	long long int	value;
	int				base;

	print_t_option(&option);
	write(1, "ok inside BASE function : -", 27);
	base = get_base(option);
	value = get_integer_type(option, args);
	if ((option->left_zeros || option->left_justify) && (option->hashtag
					|| option->type == 'p'))
		option->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	helper_print_nb_padding(option, ft_nbrlen(value, base), 0, value);
	if (!option->left_zeros && !option->left_justify && (option->hashtag
			|| option->type == 'p'))
		option->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	ft_putnbr_base(value, base, option->type);
	helper_print_nb_padding(option, ft_nbrlen(value, base), 1, value);
	write(1, "-\n\n", 3);
	return (1);
}

int ft_printf_integer(t_options *option, va_list *args)
{
	long long	n;
	long long	nb;
	int			len;

	print_t_option(&option);
	write(1,"ok inside INTEGER function : -", 30);
	n = get_integer_type(option, args);
	nb = n >= 0 ? n : -n;
	len = 0;
	len = ft_nbrlen(nb, 10);
	if (option->sign && option->left_zeros && n >= 0)
		ft_putchar((n < 0) ? '-' : '+');
	helper_print_nb_padding(option, len, 0, n);
	if (option->sign && !option->left_zeros && n >= 0)
		ft_putchar((n < 0) ? '-' : '+');
	ft_putnbr_base(n, 10, option->type);
	helper_print_nb_padding(option, len, 1, n);
	write(1, "-\n\n", 3);
	return (1);
}

int ft_printf_floats(t_options *option, va_list *args)
{
	printf("ok inside final function\n\n");
	return (1);
}

int ft_printf_modulo(t_options *option, va_list *args)
{
	write(1, "ok modulo final function : -", 28);

	ft_putchar('%');

	write(1, "-\n\n", 3);
	return (1);
}

t_functions_pointers	fp[NB_ACCEPTED_OPTIONS] =
{
	{'c', &ft_printf_char}, // ok,
	//{'C', &print_char},
	{'s', &ft_printf_string}, // ok
	//{'S', &print_unicode_string},
	{'p', &ft_printf_base},
	//{'r', &print_string},
	{'d', &ft_printf_integer},
	//{'D', &print_integer},
	{'i', &ft_printf_integer},
	{'o', &ft_printf_base},
	//{'O', &print_base},
	{'u', &ft_printf_integer},
	//{'U', &print_integer},
	{'x', &ft_printf_base},
	{'X', &ft_printf_base},
	{'b', &ft_printf_base},
	{'f', &ft_printf_floats},
	//{'F', &print_floats},
	{'%', &ft_printf_modulo},
};

// fonction qui renvoie vers la bonne fonction selon le type du %
int 	root_options_printers(t_options *option, va_list *args)
{
	int i;

	i = 0;
	while (i < NB_ACCEPTED_OPTIONS)
	{
		if (fp[i].option == option->type)
		{
			printf("option is %c | g_func[%i].spec is %c\n", option->type, i, fp[i].option);
			fp[i].func(option, args);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
 ** flags -----------------------------------------------------------------------
 */

int		is_accepted_options(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%'
			|| c == 'b');
}

int		is_accepted_flags(char c)
{
	return (c == ' ' || c == '.' || c == '#' || c == '0' || c == '+' || c == '-'
			|| ft_isdigit(c) || c == 'h' || c == 'l' || c == 'L' );
}

/*
   • Vous ne ferez pas la gestion de buffer présente dans la fonction printf de la libc.
   • Vous devez gérer les conversions suivantes : csp
   • Vous devez gérer les conversions suivantes : diouxX avec les flags hh, h, l, ll
   • Vous devez gérer la conversion suivante : f avec les flags l et L
   • Vous devez gérer le %%
   • Vous devez gérer les flags #0-+ et espace
   • Vous devez gérer la taille minimum du champ
   • Vous devez gérer la précision
   */

/*
 ** build new option ------------------------------------------------------------
 */

int    compute_new_option_len_in_format(const char *format, int i)
{
	int len;

	//printf("(*format + i) = %s", (format + i));
	len = 1;
	while (is_accepted_flags(format[i + len]))
		len++;
	if (is_accepted_options(format[i + len]))
		return (len);
	else
		return (-1);
}

int ft_strchr_modified(const char *s, int c)
{
	int		i;
	char	*sptr;

	i = -1;
	sptr = (char *)s;
	while (sptr[++i] != '\0')
	{
		if (sptr[i] == (char)c)
			return (1);
	}
	if ('\0' == (char)c)
		return (1);
	return (0);
}

int	ft_strstr_modified(const char *m, const char *a)
{
	int i;
	int j;

	i = -1;
	if (ft_strlen(a) == 0)
		return (0);
	while (m[++i])
	{
		j = 0;
		while (a[j] == m[i + j] && m[i + j])
			j++;
		if (a[j] == '\0')
			return (1);
	}
	return (0);
}

int extract_number_in_flags(t_options *new)
{
	int i;
	int j;
	int sum;

	i = 0;
	j = 0;
	sum = 0;

	while (new->flags[i])
	{
		if (new->flags[i] == '0')
			new->left_zeros = 1;
		else if (ft_isdigit(new->flags[i]))
		{
			while (new->flags[i] && ft_isdigit(new->flags[i + j]))
				sum = ((sum * 10) + ((int)new->flags[i + j++] - 48));
			i += (j - 1);
		}
		else
			;
		i++;
	}
	return (sum);
}

/*
 ** t_options list functions ----------------------------------------------------
 */

t_options	*create_new_option(const char *format, int i)
{
	t_options	*new;

	if ((new = (t_options*)ft_memalloc(sizeof(t_options))) == NULL)
		return (NULL);
	//ft_bzero(new, sizeof(t_options)); kc

	// 1. flen
	if ((new->flen = compute_new_option_len_in_format(format, i)) == -1)
		return (NULL);

	// 2. type
	new->type = (new->flen > 0 ? (format[i + new->flen]) : (char)NULL);

	// 3. flags
	if (new->flen > 1)
		new->flags = ft_strsub(format, i + 1, (size_t)(new->flen - 1));

	// 4. fpos dans format
	new->fpos = i;

	// 5. left_justify
	if (new->flen > 1 && ft_strchr_modified(new->flags, '-'))
		new->left_justify = 1;

	// 6. sign =
	if (new->flen > 1 && ft_strchr_modified(new->flags, '+'))
		new->sign = 1;

	if (new->flags && new->flen > 1)
		new->point = ft_strchr_modified(new->flags, '.') ? 1 : 0;
	// 7. space
	if (new->flen > 1 && new->sign != 1 && ft_strchr_modified(new->flags, ' '))
		new->space = 1;

	// 8. #
	if (new->flen > 1 && ft_strchr_modified(new->flags, '#'))
		new->hashtag = 1;

	// 9. 0 -> géré dans le 10. number
	// if (new->flen > 1 && ft_strchr_modified(new->flags, '0'))
	//		new->left_zeros = 1;

	// print_t_option(&new);
	// 10. number
	if (new->flen > 1)
		new->number = extract_number_in_flags(new);
	//printf("flags = %s || ft_atoi flags = %i\n", new->flags, ft_atoi(new->flags));
	// print_t_option(&new);
	//11. et 12 h / hh
	if (new->flen > 1 && ft_strstr_modified(new->flags, "h"))
		new->h = 1;
//	else if (new->flen > 1 && ft_strchr_modified(new->flags, "hh"))
//		new->hh = 1;

	// 13. et 14 ll / l
	if (new->flen > 1 && ft_strstr_modified(new->flags, "ll"))
		new->ll = 1;
	else if (new->flen > 1 && ft_strchr_modified(new->flags, 'l'))
		new->l = 1;
	if (new->flen > 1 && ft_strchr_modified(new->flags, 'L'))

		// 15. L
		if (new->flen > 1 && ft_strstr_modified(new->flags, "ll"))
			new->ll = 1;

	return (new);
}
//printf("new option[%i]->flen = %i\n", i, new->flen);

void	push_back_new_option(t_options **latest_option, t_options *new)
{
	t_options	*latest;

	if (latest_option == NULL)
		return ;
	if (*latest_option == NULL)
		*latest_option = new;
	else
	{
		latest = *latest_option;
		while (latest->next != NULL)
			latest = latest->next;
		latest->next = new;
	}
}

/*
 ** build t_options -------------------------------------------------------------
 */

int   extract_options(const char *format, t_options **options)
{
	int i;
	int format_len;
	t_options	*new;

	i = -1;
	format_len = ft_strlen(format);
	new = NULL;
	while (++i < format_len)
	{
		if (format[i] == '%')
		{
			if ((new = (create_new_option(format, i))) == NULL)
			{
				printf("RET -1 = unvalid option\n");
				return (-1);
			}
			else
			{
				i += new->flen;
				push_back_new_option(options, new);
			}
		}
	}
	return (1);
}

/*
 ** fonctions pour débugger -----------------------------------------------------
 */

void print_t_options_list(t_options **options)
{
	int i = 0;
	t_options	*option;

	option = *options;
	while (option != NULL && ++i)
	{
		printf("\n******* option(f[%i]) *****\n", i);
		printf("1. o->type         = %c\n", option->type);
		printf("2. o->flags        = %s\n", option->flags);
		printf("3. o->flen         = %i\n", option->flen);
		printf("4. o->fpos         = %i\n", option->fpos);
		printf("5. o->left_justify = %i\n", option->left_justify);
		printf("6. o->sign         = %i\n", option->sign);
		printf("7. o->space        = %i\n", option->space);
		printf("8. o->hashtag      = %i\n", option->hashtag);
		printf("9. o->left_zeros   = %i\n", option->left_zeros);
		printf("10 o->number       = %i\n", option->number);
		printf("11 o->h            = %i\n", option->h);
		printf("12 o->hh           = %i\n", option->hh);
		printf("13 o->l            = %i\n", option->l);
		printf("14 o->ll           = %i\n", option->ll);
		printf("15 o->L            = %i\n", option->L);
		printf("**********  end ***********\n\n");
		option = option->next;
	}
}

void print_t_option(t_options **option)
{
	t_options	*this_one;

	this_one = *option;
	printf("\n******* option(f[%i]) *****\n", this_one->fpos);
	printf("1. o->type         = %c\n", this_one->type);
	printf("2. o->flags        = %s\n", this_one->flags);
	printf("3. o->flen         = %i\n", this_one->flen);
	printf("4. o->fpos         = %i\n", this_one->fpos);
	printf("5. o->left_justify = %i\n", this_one->left_justify);
	printf("6. o->sign         = %i\n", this_one->sign);
	printf("7. o->space        = %i\n", this_one->space);
	printf("8. o->hashtag      = %i\n", this_one->hashtag);
	printf("9. o->left_zeros   = %i\n", this_one->left_zeros);
	printf("10 o->number       = %i\n", this_one->number);
	printf("11 o->h            = %i\n", this_one->h);
	printf("12 o->hh           = %i\n", this_one->hh);
	printf("13 o->l            = %i\n", this_one->l);
	printf("14 o->ll           = %i\n", this_one->ll);
	printf("15 o->L            = %i\n", this_one->L);
	printf("**********  end  **********\n\n");
}

/*
 ** la petite -------------------------------------------------------------------
 */

int		ft_printf(const char *format, ...)
{
	va_list		  args;
	t_options   *options;
	t_options 	*option;
	int					i;

	// step 1 = init struct
	options = NULL;
	printf("\n------- BUILDING LIST ---------\n");
	if (extract_options(format, &options) == -1)
	{
		printf("RET -1 = LIST TO BE CLEAR\n");
		//options_lst_clear(spec);
		return (-1);
	}
	// print_t_options_list(&options);
	printf("------- OK LIST ---------------\n");
	va_start(args, format);
	option = options;
	i = 0;
	printf("------- START FT_PRINTF -------\n\n");
	while (format[i])
	{
		//write(1, "insid1\n", 7);
		//printf("while : format[%i] = %c\n", i, format[i]);
		if (format[i] == '%' && format[i - 1] != '%')
		{
			//write(1, "\ninsid2\n", 8);
			// printf("\n %%     format[%i] = '%c'\n", i, format[i]);
			// print option
			// print_t_option(&option);
			i += (1 + option->flen);
			root_options_printers(option, &args);
			option = option != NULL ? option->next : NULL;
		}
		else
		{
			// printf("!%%     format[%i] = '%c'\n", i, format[i]);
			i++;
		}
	}
	// itérer sur la liste t_options et rooter les args (%c, %s, etc.) aux fonctions correspondantes
	va_end(args);
	//print_t_options_list(&options);
	return (1);
}
