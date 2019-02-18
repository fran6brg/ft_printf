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

int		print_sign(t_options *option, int nb)
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

int		get_sign(t_options *option)
{
	int		ret;

	ret = 0;
	if (option->type == 'd' || option->type == 'i')
	{
		if (!option->neg && option->sign) // ok
			ret += 1;
	}
	return (ret);
}

/*
---------------------------   print_zeros_padding ------------------------------
*/

int		print_zeros_padding_before(t_options *option, int len, int nb) // sert a print les 0 padding en toute circonstances
{
	int		i;
	int		ret;

	i = -1;
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
	//////////////////////////////////////////////////////////////////////////////
	if (option->pad_max) // 5.1
	{
		if (option->pad_min) // 5.1.1
		{
			if (option->left_zeros) // final 5.1.1.1
			{
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // final 5.1.1.2
			{
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
		}
		else if (!option->pad_min)  // 5.1.2
		{
			if (option->left_zeros)   // final 5.1.2.1
			{
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // final 5.1.2.2
			{
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space))
				{
					// printf("len =%d ", len);
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
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // 5.2.1.2
			{
				//
			}
		}
		else if (!option->pad_min) // 5.2.2
		{
			if (option->left_zeros) // 5.2.2.1
			{
				while (++i < option->pad_min - len - get_sign(option))
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

int		print_zeros_padding_after(t_options *option, int len, int nb) // sert a print les 0 padding en toute circonstances
{
	int		i;
	int		ret;

	i = -1;
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
	//////////////////////////////////////////////////////////////////////////////
	if (option->pad_max) // 6.1
	{
		if (option->pad_min) // 6.1.1
		{
			if (option->left_zeros) // final 6.1.1.1
			{
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // final 6.1.1.2
			{
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
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
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
				{
					// printf("len =%d ", len);
					ret += ft_putchar_ret('0');
				}
			}
			else if (!option->left_zeros) // final 6.1.2.2
			{
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
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
				while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
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
				while (++i < option->pad_min - len - get_sign(option))
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
---------------------------   print_spaces_padding -----------------------------
*/

int		print_spaces_padding_before(t_options *option, int len, int nb, int after) // sert a print les spaces padding en toute circonstances
{
	int		i;
	int		ret;
	int		un_space_a_til_ete_print;
	int		sign_is_print;

	un_space_a_til_ete_print = (option->space && !get_sign(option) && !option->neg) ? 1 : 0;
	sign_is_print = 0;
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
	while (++i < option->pad_min - len - get_sign(option) - un_space_a_til_ete_print)
	{
		if (option->pad_min && i + 1 == (option->pad_min - len - get_sign(option) - un_space_a_til_ete_print))
		{
			if (!option->sign_is_print /* si before && signe non print alors print le signe */
				&& !(!option->neg && !option->sign) /* sauf si le nb est positif et qu il ne faut pas imprimer le signe (si nb = '100' -> print '100') */
				&& option->pad_min > option->pad_max) /* ... */
			{
				// print_t_option(&option);
				ret += print_sign(option, nb);
				sign_is_print = 1;
				break;
			}
			else
				ret += ft_putchar_ret(' ');
		}
		else
			ret += ft_putchar_ret(' ');
	}
	// printf("i=%d\n", i);
	if (sign_is_print) // si on a print le sign en before alors on augmente le pad_min de 1 car on printera pas le sign dans print_zeros_padding
	{
			option->sign_is_print = 1;
			option->pad_max += 1;
	}
	if (!after && !option->pad_max && !sign_is_print)
		ret += print_sign(option, nb);
	return (ret);
}


int		print_spaces_padding_after(t_options *option, int len, int nb, int after) // sert a print les spaces padding en toute circonstances
{
	int		i;
	int		ret;
	int		un_space_a_til_ete_print;

	un_space_a_til_ete_print = (option->space && !get_sign(option) && !option->neg) ? 1 : 0;
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
	while (++i < option->pad_min - len - get_sign(option) - un_space_a_til_ete_print)
	{
				ret += ft_putchar_ret(' ');
	}
	return (ret);
}

//
// int		print_spaces_padding(t_options *option, int len, int nb, int after) // sert a print les spaces padding en toute circonstances
// {
// 	int		i;
// 	int		ret;
// 	int		un_space_a_til_ete_print;
// 	int		sign_is_print;
//
// 	un_space_a_til_ete_print = (option->space && !get_sign(option) && !option->neg) ? 1 : 0;
// 	sign_is_print = 0;
// 	len = option->pad_max > len ? option->pad_max : len;
// 	i = -1;
// 	ret = 0;
// 	if (option->type != 'd' && option->type != 'i' && (option->hashtag || option->type == 'p'))
// 	{
// 		if (option->type != 'o')
// 			len += 2;
// 		else if (option->type == 'o' && nb != 0)
// 			len += 1;
// 	}
// 	// printf("\n/********** un_space_a_til_ete_print %d***********\\\n", un_space_a_til_ete_print);
// 	// printf("\n/********** len %d***********\\\n", len);
// 	while (++i < option->pad_min - len - get_sign(option) - un_space_a_til_ete_print)
// 	{
// 		if (option->pad_min && i + 1 == (option->pad_min - len - get_sign(option) - un_space_a_til_ete_print))
// 		{
// 			if ((!after && !option->sign_is_print) /* si before && signe non print alors print le signe */
// 				&& !(!option->neg && !option->sign) /* sauf si le nb est positif et qu il ne faut pas imprimer le signe (si nb = '100' -> print '100') */
// 				&& option->pad_min < option->pad_max) /* ... */
// 			{
// 				// print_t_option(&option);
// 				ret += print_sign(option, nb);
// 				sign_is_print = 1;
// 				break;
// 			}
// 			else
// 				ret += ft_putchar_ret(' ');
// 		}
// 		else
// 			ret += ft_putchar_ret(' ');
// 	}
// 	// printf("i=%d\n", i);
// 	if (sign_is_print) // si on a print le sign en before alors on augmente le pad_min de 1 car on printera pas le sign dans print_zeros_padding
// 	{
// 			option->sign_is_print = 1;
// 			option->pad_max += 1;
// 	}
// 	if (!after && !option->pad_max && !sign_is_print)
// 		ret += print_sign(option, nb);
// 	return (ret);
// }

/*
 ** ---------- nb_padding rooter selon before/after + left_justify --------------
 */

int		helper_print_nb_padding(t_options *option, int len, int after, int nb)
{
	int		ret;
	int   before;

	// print_t_option(&option);
	// printf("\n%d.%d.%d.%d.%d\n", after ? 2 : 1, option->left_justify ? 1 : 2, option->pad_min ? 1 : 2, option->pad_max ? 1 : 2, option->left_zeros ? 1 : 2);
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
					if (option->left_zeros) // final 1.1.1.2.1
					{
						ret += print_zeros_padding_before(option, len, nb);
					}
					else if (!option->left_zeros) // final 1.1.1.2.2
					{
						ret += print_zeros_padding_before(option, len, nb);
					}
				}
				else if (!option->pad_max) // 1.1.1.2
				{
					if (option->left_zeros) // final 1.1.1.2.1
					{
						ret += print_zeros_padding_before(option, len, nb);
					}
					else if (!option->left_zeros) // final 1.1.1.2.2
					{
						// write(1, "h", 1);
						ret += print_zeros_padding_before(option, len, nb);
					}
				}
			}
			else if (!option->pad_min) // 1.1.2
			{
				if (option->pad_max) // 1.1.2.1
				{
					if (option->left_zeros) // 1.1.2.2.1
					{
						// write(1, "h", 1);
					}
					else if (!option->left_zeros) // 1.1.2.2.2
					{
						// printf("bitch");
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
						//
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
						ret += print_zeros_padding_before(option, len, nb);
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
						if (option->sign)
							ret += print_sign(option, nb);
					}
					else if (!option->pad_max) // final 2.1.1.1.2
					{
						// write(1, "h", 1);
						ret += print_zeros_padding_after(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
					}
				}
				else if (!option->pad_min) // 2.1.1.2
				{
					if (option->pad_max) // final 2.1.1.2.1
					{
						// write(1, "h", 1);
						ret += print_zeros_padding_after(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
					}
					else if (!option->pad_max) // final 2.1.1.2.2
					{
						// write(1, "h", 1);
						ret += print_zeros_padding_after(option, len, nb);
						if (option->sign)
							ret += print_sign(option, nb);
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
						if (option->sign)
							ret += print_sign(option, nb);
					}
					else if (!option->pad_max) // final 2.1.2.1.2
					{
						// write(1, "h", 1);
						ret += print_spaces_padding_after(option, len, nb, after);
						if (option->sign)
							ret += print_sign(option, nb);
					}
				}
				else if (!option->pad_min) // 2.1.2.2
				{
					if (option->pad_max) // final 2.1.2.2.1
					{
						// write(1, "h", 1);
						ret += print_spaces_padding_after(option, len, nb, after);
						if (option->sign)
							ret += print_sign(option, nb);
					}
					else if (!option->pad_max) // final 2.1.2.2.2
					{
						// write(1, "h", 1);
						ret += print_spaces_padding_after(option, len, nb, after);
						if (option->sign)
							ret += print_sign(option, nb);
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


// if ((option->left_zeros && !option->pad_max) || option->pad_max)
// {
// 	if (option->pad_max)
// 	{
// 		while (++i < option->pad_max - len + (get_sign(option) && !option->left_justify) - (option->space && option->pad_min > option->pad_max ? 1 : 0))
// 		{
// 			// printf("len =%d ", len);
// 			ret += ft_putchar_ret('0');
// 		}
// 		// printf("i=%i ", i);
// 	}
// 	else
// 	{
// 		while (++i < option->pad_min - len - get_sign(option))
// 		{
// 			ret += ft_putchar_ret('0');
// 		}
// 	}
// }
