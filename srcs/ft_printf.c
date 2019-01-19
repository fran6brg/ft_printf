/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 02:59:11 by fberger           #+#    #+#             */
/*   Updated: 2019/01/15 02:59:13 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/t_options.h"
#include "../3.Libft/libft.h"

/*
** functions pointer -----------------------------------------------------------
*/

// à faire :

/*t_func	p_func[10] =
{
	{'c', &print_char},
	//{'C', &print_char},
	{'s', &print_string},
	//{'S', &print_unicode_string},
  {'p', &print_base},
	//{'r', &print_string},
	{'d', &print_integer},
	//{'D', &print_integer},
	{'i', &print_integer},
  {'o', &print_base},
  //{'O', &print_base},
	{'u', &print_integer},
	//{'U', &print_integer},
	{'x', &print_base},
	//{'X', &print_base},
	//{'b', &print_base},
	{'f', &print_floats},
	//{'F', &print_floats},
  {'%', &print_char},
};*/

/*
** flags -----------------------------------------------------------------------
*/

int		is_accepted_options(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
      || c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%');
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

/*
** t_options list functions ----------------------------------------------------
*/

t_options	*create_new_option(const char *format, int i)
{
  t_options	*new;

	if ((new = (t_options*)ft_memalloc(sizeof(t_options))) == NULL)
		return (NULL);
	//ft_bzero(new, sizeof(t_options));
  if ((new->flen = compute_new_option_len_in_format(format, i)) == -1)
        return (NULL);
  new->type = (new->flen > 0 ? (format[i + new->flen]) : (char)NULL);
  if (new->flen > 1)
      new->flags = ft_strsub(format, i + 1, (size_t)(new->flen - 1));
  //printf("new option[%i]->flen = %i\n", i, new->flen);
	return (new);
}

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
    printf("\n******** option[%i] *******\n", i);
    printf("o->type = %c\n", option->type);
    printf("o->flags = %s\n", option->flags);
    //printf("o->flags = %s == NULL ? : %d\n", option->flags, (option->flags == NULL));
    printf("o->flen = %i\n", option->flen);
    printf("**********  end ***********\n\n");
    option = option->next;
  }
}

/*
** la petite -------------------------------------------------------------------
*/

int		ft_printf(const char *format, ...)
{
	va_list		  args;
  t_options   *options;

  // step 1 = init struct
  options = NULL;
  if (extract_options(format, &options) == -1)
  {
    printf("RET -1 = LIST TO BE CLEAR\n");
    //options_lst_clear(spec);
    return (-1);
  }
  //va_start(args, format);
  // itérer sur la liste t_options et rooter les args (%c, %s, etc.) aux fonctions correspondantes
  //va_end(args);
  print_t_options_list(&options);
  return (1);
}
