/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:26:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/17 18:22:04 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

/*
 ** ---------- float_padding printer   ----------------------------------------
 */

int		helper_print_floats_padding(t_options *option, int len, int after, int neg)
{
	int		ret;
	int		i;

	i = -1;
	ret = 0;
	if ((!after && option->left_justify) || (after && !option->left_justify))
		return (0);
	//	printf("\n WERE EEEEHERE %d\n\n", neg);
	if (option->left_zeros && !option->left_justify)
		if (option->sign || neg == 1)
			ret += ft_putchar_ret(neg == 1 ? '-' : '+');
	while (++i < option->pad_min - (len + neg))
	{
		if (option->left_zeros && !option->left_justify)
			ret += ft_putchar_ret('0');
		else
			ret += ft_putchar_ret(' ');
	}
	if (!option->left_zeros)
		if (option->sign || neg == 1)
			ret += ft_putchar_ret(neg == 1 ? '-' : '+');
	return (ret);
}

/*
 ** ---------- nb_padding functions selon before/after + left_justify --------------
 */

int		print_sign(t_options *option, long long nb)
{
	int		ret;

	ret = 0;
	if (!option->sign_is_print && (option->type == 'd' || option->type == 'i'))
	{
		if (nb < 0)
		{
			ret += ft_putchar_ret('-');
			option->sign_is_print = 1;
		}
		if (nb >= 0 && option->sign)
		{
			ret += ft_putchar_ret('+');
			option->sign_is_print = 1;
		}
	}
	return (ret);
}

int		nb_have_a_sign(t_options *option, long long nb)
{
	int		ret;

	ret = 0;
	if (option->type == 'd' || option->type == 'i')
	{
		if ((option->neg)
		|| (!option->neg && option->sign && nb >= 0)) // ok
			ret = 1;
	}
	return (ret);
}

/*
---------------------------   print_spaces_padding -----------------------------
*/

int		print_spaces_padding_before(t_options *option, int len, long long nb, int after) // sert a print les spaces padding en toute circonstances
{
	int		i;
	int		ret;
	int		un_space_a_til_ete_print;
	int		sign_is_print;
	int		get_sign_option;

	un_space_a_til_ete_print = (option->space && !get_sign_option && !option->neg) ? 1 : 0;
	sign_is_print = 0;
	get_sign_option = nb_have_a_sign(option, nb);
	len = option->pad_max > len ? (option->pad_max - get_sign_option) : len; /* ok mais attention à bien diminuer le pad-max du signe car celui ci n est pas compté dans len */
	if (option->type != 'd' && option->type != 'i' && (option->hashtag || option->type == 'p'))
	{
		if (option->type != 'o')
			len += 2;
		else if (option->type == 'o' && nb != 0)
			len += 1;
	}
	i = -1;
	ret = 0;
	// printf("len = %d || get_sign_option = %i || un_space_a_til_ete_print = %i\n", len, get_sign_option, un_space_a_til_ete_print);
	while (++i < option->pad_min - len - get_sign_option /* normal */ - un_space_a_til_ete_print)
	{
		// printf("get_sign_option = %i ||", get_sign_option);
		if (option->pad_min && i + 1 == (option->pad_min - len - get_sign_option - un_space_a_til_ete_print))
		{
			if (!option->sign_is_print /* si before && signe non print alors print le signe */
			&& !(!option->neg && !option->sign) /* sauf si le nb est positif et qu il ne faut pas imprimer le signe (si nb = '100' -> print '100') */
			&& option->pad_min > option->pad_max /* ... */
			&& option->pad_max) /* si pad max == 0 alors on print ' ' car ça veut dire qu il n y  aura pas de 0 a mettre */
			{
				ret += print_sign(option, nb);
				sign_is_print = 1;
			}
			else
				ret += ft_putchar_ret(' ');
		}
		else
			ret += ft_putchar_ret(' ');
	}
	if (sign_is_print) // si on a print le sign en before alors on augmente le pad_min de 1 car on printera pas le sign dans print_zeros_padding
	{
		option->sign_is_print = 1;
		option->pad_max += 1;
	}
	if (!after && !option->pad_max && !sign_is_print)
	{
		ret += print_sign(option, nb);
		// ft_putchar_ret('h');
	}
	return (ret);
}

int		print_spaces_padding_after(t_options *option, int len, long long nb, int after) // sert a print les spaces padding en toute circonstances
{
	int		i;
	int		ret;
	int		un_space_a_til_ete_print;

	un_space_a_til_ete_print = (option->space && !nb_have_a_sign(option, nb) && !option->neg) ? 1 : 0;
	len = option->pad_max > len ? option->pad_max : len;
	i = -1;
	ret = 0;

	if (option->type != 'd' && option->type != 'i' && (option->hashtag || option->type == 'p'))
	{
		if (option->type != 'o')
		len += 2;
		else if (option->type == 'o' && nb != 0)
		len += 1;
	}
	while (++i < option->pad_min - (len) - nb_have_a_sign(option, nb) - un_space_a_til_ete_print)
	{
		ret += ft_putchar_ret(' ');
	}
	return (ret);
}

/*
---------------------------   print_zeros_padding ------------------------------
*/

int		print_zeros_padding_before(t_options *option, int len, long long nb) // sert a print les 0 padding en toute circonstances
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (option->space && !option->sign && !option->neg) // si insertion d'un espace (space + pas de signe + n positif)
	{
		ret += ft_putchar_ret(' ');
		// len += 1; // + 010.
	}
	if (option->type != 'd' && option->type != 'i' && (option->hashtag || option->type == 'p'))
	{
		if (option->type != 'o')
		{
			// printf("here");
			len += 2;
		}
		else if (option->type == 'o' && nb != 0)
		{
			// printf("here");
			len += 1;
		}
	}
	if (!option->sign_is_print)
	{
		// printf("here");
		ret += print_sign(option, nb);
		option->sign_is_print = 1;
	}
	// printf("len =%d ", len);
	//////////////////////////////////////////////////////////////////////////////
	if (option->pad_max) // 5.1
	{
		if (option->pad_min) // 5.1.1
		{
			if (option->left_zeros) // final 5.1.1.1
			{
				if (option->pad_max > len)
				{
					// printf("%i < %d - %d + %d - %d\n", i, option->pad_max, (len - option->sign_is_print), (nb_have_a_sign(option, nb) && !option->left_justify), (option->space && option->pad_min > option->pad_max ? 1 : 0));
					while (++i < option->pad_max - len - nb_have_a_sign(option, nb) /* normal */
					- (option->space && !nb_have_a_sign(option, nb) /* si il y a un space pour un nb positif */
					&& option->pad_min > option->pad_max ? 1 : 0) /* je sais plus pourquoi */
					+ (option->pad_max - len)) /* il faut mettre des 0 entre les 2 */
					{
						// printf("len =%d ", len);
						ret += ft_putchar_ret('0');
					}
				}
				else
				{
					// printf("%i < %d - %d + %d - %d\n", i, option->pad_max, (len - option->sign_is_print), (nb_have_a_sign(option, nb) && !option->left_justify), (option->space && option->pad_min > option->pad_max ? 1 : 0));
					while (++i < option->pad_max - len - nb_have_a_sign(option, nb)
					- (option->space && !nb_have_a_sign(option, nb)
					&& option->pad_min > option->pad_max ? 1 : 0))
					{
						// printf("len =%d ", len);
						ret += ft_putchar_ret('0');
					}
				}
			}
			else if (!option->left_zeros) // final 5.1.1.2
			{
				if (option->pad_max >= option->pad_min) /* pourquoi ? */
				{
				//	printf("len =%d || nb_have_a_sign(option, nb) = %i || !option->left_justify = %i", len, nb_have_a_sign(option, nb), !option->left_justify);
					while (++i < option->pad_max - len - nb_have_a_sign(option, nb) /* normal */
					+ (nb_have_a_sign(option, nb) && !option->left_justify)) /* le signe apparaît avant si left_justify */
					{
						ret += ft_putchar_ret('0');
					}
				}
				else
				{
					// printf("len =%d || nb_have_a_sign(option, nb) = %i || !option->left_justify = %i\n", len, nb_have_a_sign(option, nb), !option->left_justify);
					while (++i < option->pad_max - len - nb_have_a_sign(option, nb) /* normal */
					+ (!option->neg && option->sign)) /* si nb positif avec obligation de mettre un signe */
					{
						ret += ft_putchar_ret('0');
					}
				}
			}
		}
		else if (!option->pad_min)  // 5.1.2
		{
			if (option->left_zeros)   // final 5.1.2.1
			{
				// printf("padmax - %d + %d - %d\n", len, (nb_have_a_sign(option, nb) && !option->left_justify), (option->space && option->pad_min > option->pad_max ? 1 : 0));
				// probablement a changer :
				while (++i < option->pad_max - len + (nb_have_a_sign(option, nb) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // final 5.1.2.2
			{
				// printf("(2) len =%d \n", len);
				while (++i < option->pad_max - len)
				{
					ret += ft_putchar_ret('0');
				}
			}
		}
	}
	else if (!option->pad_max)  // 5.2
	{
		if (option->pad_min) // 5.2.1
		{
			if (option->left_zeros) // 5.2.1.1
			{
				// printf("i = %i || len = %d\n", i, len);
				// while (++i < option->pad_min - len + (nb_have_a_sign(option, nb) && !option->left_justify) - (option->space))
				while (++i < option->pad_min - len - nb_have_a_sign(option, nb)
				- (option->space && !nb_have_a_sign(option, nb)
				&& option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // 5.2.1.2
			{
				// printf("len = %d || (nb_have_a_sign(option, nb) && !option->left_justify) = %i", len, (nb_have_a_sign(option, nb) && !option->left_justify));
				// probablement a changer :
				while (++i < option->pad_min - len + (nb_have_a_sign(option, nb) && !option->left_justify) - (option->space))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
		}
		else if (!option->pad_min) // 5.2.2
		{
			if (option->left_zeros) // 5.2.2.1
			{
				while (++i < option->pad_min - len - nb_have_a_sign(option, nb))
				{
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // 5.2.2.2
			{
				//
			}
		}
	}
	return (ret);
}

int		print_zeros_padding_after(t_options *option, int len, long long nb) // sert a print les 0 padding en toute circonstances
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (option->type != 'd' && option->type != 'i' && (option->hashtag || option->type == 'p'))
	{
		if (option->type != 'o')
		{
			// printf("here");
			len += 2;
		}
		else if (option->type == 'o' && nb != 0)
		{
			// printf("here");
			len += 1;
		}
	}
	if (!option->sign_is_print)
	{
		// printf("here");
		ret += print_sign(option, nb);
		option->sign_is_print = 1;
	}
	if (option->pad_max) // 6.1
	{
		if (option->pad_min) // 6.1.1
		{
			if (option->left_zeros) // final 6.1.1.1
			{
				while (++i < option->pad_max - len + (nb_have_a_sign(option, nb) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // final 6.1.1.2
			{
				while (++i < option->pad_max - len + (nb_have_a_sign(option, nb) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
		}
		else if (!option->pad_min)  // 6.1.2
		{
			if (option->left_zeros)   // final 6.1.2.1
			{
				// printf("padmax - %d + %d - %d\n", len, (nb_have_a_sign(option, nb) && !option->left_justify), (option->space && option->pad_min > option->pad_max ? 1 : 0));
				// printf("len =%d ", len);
				while (++i < option->pad_max - len + (nb_have_a_sign(option, nb) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // final 6.1.2.2
			{
				while (++i < option->pad_max - len + (nb_have_a_sign(option, nb) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
		}
	}
	else if (!option->pad_max)  // 6.2
	{
		if (option->pad_min) // 6.2.1
		{
			if (option->left_zeros) // 6.2.1.1
			{
				while (++i < option->pad_max - len + (nb_have_a_sign(option, nb) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // 6.2.1.2
			{
				//
			}
		}
		else if (!option->pad_min) // 6.2.2
		{
			if (option->left_zeros) // 6.2.2.1
			{
				while (++i < option->pad_min - len - nb_have_a_sign(option, nb))
				{
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // 6.2.2.2
			{
				//
			}
		}
	}
	return (ret);
}

/*
 ** ---------- nb_padding rooter selon before/after + left_justify --------------
 */

int		helper_print_nb_padding(t_options *option, int len, int after, long long nb)
{
	int		ret;
	int   before;

	// print_t_option(&option);
	// printf("\n%d.%d.%d.%d.%d\n", after ? 2 : 1, option->left_justify ? 1 : 2, option->pad_min ? 1 : 2, option->pad_max ? 1 : 2, option->left_zeros ? 1 : 2);
	//printf("2.5) len = %d  ", len);
	ret = 0;
	before = after ? 0 : 1;
	if (before) // 1.before
	{
		if (option->left_justify) // 1.1.alignement gauche
		{
			if (option->pad_min) // 1.1.1
			{
				if (option->pad_max) // 1.1.1.1
				{
					if (option->left_zeros) // final 1.1.1.1.1
					{
						ret += print_zeros_padding_before(option, len, nb);
					}
					else if (!option->left_zeros) // final 1.1.1.1.2
					{
						// printf("HERE");
						ret += print_zeros_padding_before(option, len, nb);
					}
				}
				else if (!option->pad_max) // 1.1.1.2
				{
					if (option->left_zeros) // final 1.1.1.2.1
					{
						// printf("HERE");
						ret += print_zeros_padding_before(option, len, nb);
					}
					else if (!option->left_zeros) // final 1.1.1.2.2
					{
						ret += print_sign(option, nb);
						// write(1, "here", 4);
						// ret += print_zeros_padding_before(option, len, nb);
						// ne rien mettre ici cf. mainprintf printf("\033[0;31mREAL>\t[%-10d]\n", 3);
					}
				}
			}
			else if (!option->pad_min) // 1.1.2
			{
				if (option->pad_max) // 1.1.2.1
				{
					if (option->left_zeros) // 1.1.2.2.1
					{
						ret += print_zeros_padding_before(option, len, nb);
					}
					else if (!option->left_zeros) // 1.1.2.2.2
					{
						ret += print_zeros_padding_before(option, len, nb);
					}
				}
				else if (!option->pad_max) // 1.1.2.2
				{
					if (option->left_zeros) // final 1.1.2.2.1
					{
						ret += print_zeros_padding_before(option, len, nb);
					}
					else if (!option->left_zeros) // 1.1.2.2.2
					{
						// printf("bitch");
						ret += print_sign(option, nb);
					}
				}
			}
		}
		else if (!option->left_justify) // 1.2.alignement droite
		{
			if (option->pad_min) // 1.2.1
			{
				if (option->pad_max) // final 1.2.1.1
				{
					if (option->left_zeros) // final 1.2.1.1.1
					{
						ret += print_spaces_padding_before(option, len, nb, after);
						ret += print_zeros_padding_before(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
					}
					else if (!option->left_zeros) // final 1.2.1.1.2
					{
						// printf("bitch");
						ret += print_spaces_padding_before(option, len, nb, after);
						ret += print_zeros_padding_before(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
					}
				}
				else if (!option->pad_max) // 1.2.1.2
				{
					if (option->left_zeros) // final 1.2.1.2.1
					{
						// printf("bitch");
						ret += print_zeros_padding_before(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
					}
					else if (!option->left_zeros) // final 1.2.1.2.2
					{
						//printf("3 len = %d  ", len);
						ret += print_spaces_padding_before(option, len, nb, after);
						if (option->sign)
							ret += print_sign(option, nb);
					}
				}
			}
			else if (!option->pad_min) // 1.2.2
			{
				if (option->pad_max) // final 1.2.2.1
				{
					if (option->left_zeros) // final 1.2.2.1.1
					{
						// printf("bitch i am here");
						ret += print_zeros_padding_before(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
					}
					else if (!option->left_zeros) // final 1.2.2.1.2
					{
						// printf("bitch i am here");
						ret += print_zeros_padding_before(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
					}
				}
				else if (!option->pad_max) // 1.2.2.2
				{
					if (option->left_zeros) // final 1.2.2.2.1
					{
						ret += print_zeros_padding_before(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
					}
					else if (!option->left_zeros) // 1.2.2.2.2
					{
						// printf("bitch i am here");
						ret += print_zeros_padding_before(option, len, nb);
					}
				}
			}
		}
	}
	else if (after) // 2.after
	{
		if (option->left_justify) // 2.1
		{
			if (option->left_zeros) // 2.1.1
			{
				if (option->pad_min) // 2.1.1.1
				{
					if (option->pad_max) // final 2.1.1.1.1
					{
						// write(1, "h", 1);
						ret += print_spaces_padding_after(option, len, nb, after);
					}
					else if (!option->pad_max) // final 2.1.1.1.2
					{
						// write(1, "h", 1);
						ret += print_zeros_padding_after(option, len, nb);
					}
				}
				else if (!option->pad_min) // 2.1.1.2
				{
					if (option->pad_max) // final 2.1.1.2.1
					{
						// write(1, "h", 1);
						ret += print_zeros_padding_after(option, len, nb);
					}
					else if (!option->pad_max) // final 2.1.1.2.2
					{
						// write(1, "h", 1);
						ret += print_zeros_padding_after(option, len, nb);
					}
				}
			}
			else if (!option->left_zeros) // 2.1.2
			{
				if (option->pad_min) // 2.1.2.1
				{
					if (option->pad_max) // final 2.1.2.1.1
					{
						// write(1, "h", 1);
						ret += print_spaces_padding_after(option, len, nb, after);
					}
					else if (!option->pad_max) // final 2.1.2.1.2
					{
						// write(1, "h", 1);
						ret += print_spaces_padding_after(option, len, nb, after);
					}
				}
				else if (!option->pad_min) // 2.1.2.2
				{
					if (option->pad_max) // final 2.1.2.2.1
					{
						// write(1, "h", 1);
						ret += print_spaces_padding_after(option, len, nb, after);
					}
					else if (!option->pad_max) // final 2.1.2.2.2
					{
						// write(1, "h", 1);
						ret += print_spaces_padding_after(option, len, nb, after);
					}
				}
			}
		}
		else if (!option->left_justify) // final 2.2 si after et alignement droite, ok rien à faire
		{
			return (0);
		}
	}
	return (ret);
}
