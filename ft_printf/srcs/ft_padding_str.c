/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:26:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/07 07:13:37 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/functions.h"
//
// /*
// ** ------------------------ space padding  -------------------------------------
// */
//
// int		print_spaces_padding_before_str(t_options *option, int len, int after)
// {
// 	int		i;
// 	int		ret;
//
// 	ret = 0;
// 	i = -1;
// 	while (++i < option->pad_un - len)
// 	{
// 		ret += ft_putchar_ret(' ');
// 	}
// 	return (ret);
// }
//
// int		print_spaces_padding_after_str(t_options *option, int len, int after)
// {
// 	int		i;
// 	int		ret;
//
// 	ret = 0;
// 	i = -1;
// 	while (++i < option->pad_un - len)
// 	{
// 		ret += ft_putchar_ret(' ');
// 	}
// 	return (ret);
// }
//
// /*
// ** ------------------------ zeros padding  -------------------------------------
// */
//
// int		print_zeros_padding_before_str(t_options *option, int len, int after)
// {
// 	int		i;
// 	int		ret;
//
// 	ret = 0;
// 	i = -1;
// 	while (++i < option->pad_un - len)
// 	{
// 		ret += ft_putchar_ret('0');
// 	}
// 	return (ret);
// }
//
// int		print_zeros_padding_after_str(t_options *option, int len, int after)
// {
// 	int		i;
// 	int		ret;
//
// 	ret = 0;
// 	i = -1;
// 	while (++i < option->pad_un - len)
// 	{
// 		ret += ft_putchar_ret('0');
// 	}
// 	return (ret);
//
// }
//
// /*
// ** ------------------------------ helper ---------------------------------------
// */
//
// int		helper_print_str_padding(t_options *option, int len, int after)
// {
// 	int		ret;
// 	int   before;
//
// 	// print_t_option(&option);
// 	ret = 0;
// 	before = after ? 0 : 1;
// 	if (before) // 1.before
// 	{
// 		if (option->left_justify) // 1.1
// 		{
// 			// printf("here\n");
// 			return (0);
// 		}
// 		else // 1.2
// 		{
// 			if (option->point) // 1.2.1
// 			{
// 				if (option->pad_deux) // 1.2.1.1
// 				{
// 					if (option->pad_deux > len) // final 1.2.1.1.1
// 					{
// 						// printf("here\n");
// 						if (option->left_zeros) // final 1.2.1.1.2.1
// 						{
// 							ret += print_zeros_padding_before_str(option, len, after);
// 						}
// 						else // final 1.2.1.1.2.2
// 						{
// 							ret += print_spaces_padding_before_str(option, len, after);
// 						}
// 					}
// 					else // 1.2.1.1.2
// 					{
// 						// printf("here\n");
// 						if (option->left_zeros) // final 1.2.1.1.2.1
// 						{
// 							ret += print_zeros_padding_before_str(option, len, after);
// 						}
// 						else // final 1.2.1.1.2.2
// 						{
// 							ret += print_spaces_padding_before_str(option, len, after);
// 						}
// 					}
// 				}
// 				else // 1.2.1.2
// 				{
// 					if (option->left_zeros) // final 1.2.1.2.1
// 					{
// 						ret += print_zeros_padding_before_str(option, len, after);
// 					}
// 					else // final 1.2.1.2.2
// 					{
// 						ret += print_spaces_padding_before_str(option, len, after);
// 					}
// 				}
// 			}
// 			else // 1.2.2
// 			{
// 				if (option->pad_deux) // 1.2.2.1
// 				{
// 					if (option->pad_deux > len) // 1.2.2.1.1
// 					{
// 						return (0);
// 					}
// 					else // 1.2.2.1.2
// 					{
// 						if (option->left_zeros) // 1.2.2.1.2.1
// 						{
// 							ret += print_zeros_padding_before_str(option, len, after);
// 						}
// 						else // 1.2.2.1.2.2
// 						{
// 							ret += print_spaces_padding_before_str(option, len, after);
// 						}
// 					}
// 				}
// 				else // 1.2.2.2
// 				{
// 					if (option->left_zeros) // final 1.2.2.2.1
// 					{
// 						ret += print_zeros_padding_before_str(option, len, after);
// 					}
// 					else // final 1.2.2.2.2
// 					{
// 						ret += print_spaces_padding_before_str(option, len, after);
// 					}
// 				}
// 			}
// 		}
// 	}
// 	else // 2.after
// 	{
// 		if (option->left_justify) // 2.1
// 		{
// 			if (option->point) // 2.1.1
// 			{
// 				if (option->pad_deux) // 2.1.1.1
// 				{
// 					if (option->pad_deux > len) // 2.1.1.1.1
// 					{
// 						if (option->left_zeros) // final 1.2.2.2.1
// 						{
// 							ret += print_zeros_padding_after_str(option, len, after);
// 						}
// 						else // final 1.2.2.2.2
// 						{
// 							ret += print_spaces_padding_after_str(option, len, after);
// 						}
// 					}
// 					else // 2.1.1.1.2
// 					{
// 						if (option->left_zeros) // final 1.2.2.2.1
// 						{
// 							ret += print_zeros_padding_after_str(option, len, after);
// 						}
// 						else // final 1.2.2.2.2
// 						{
// 							ret += print_spaces_padding_after_str(option, len, after);
// 						}
// 					}
// 				}
// 				else // 2.1.1.2
// 				{
// 					if (option->pad_deux > len) // 2.1.1.2.1
// 					{
// 						return (0);
// 					}
// 					else // 2.1.1.2.2
// 					{
// 						if (option->left_zeros) // final 2.1.1.2.2.1
// 						{
// 							ret += print_zeros_padding_after_str(option, len, after);
// 						}
// 						else // final 2.1.1.2.2.2
// 						{
// 							ret += print_spaces_padding_after_str(option, len, after);
// 						}
// 					}
// 				}
// 			}
// 			else // 2.1.2
// 			{
// 				if (option->pad_deux) // 2.1.2.1
// 				{
// 					if (option->pad_deux > len) // 2.1.2.1.1
// 					{
// 						return (0);
// 					}
// 					else // 2.1.2.1.2
// 					{
// 						if (option->left_zeros) // final 2.1.2.2.1
// 						{
// 							ret += print_zeros_padding_after_str(option, len, after);
// 						}
// 						else // final 2.1.2.2.2
// 						{
// 							ret += print_spaces_padding_after_str(option, len, after);
// 						}
// 					}
// 				}
// 				else // 2.1.2.2
// 				{
// 					if (option->pad_deux > len) // 2.1.2.2.1
// 					{
// 						return (0);
// 					}
// 					else // 2.1.2.2.2
// 					{
// 						if (option->left_zeros) // final 2.1.2.2.2.1
// 						{
// 							ret += print_zeros_padding_after_str(option, len, after);
// 						}
// 						else // final 2.1.2.2.2.2
// 						{
// 							ret += print_spaces_padding_after_str(option, len, after);
// 						}
// 					}
// 				}
// 			}
// 		}
// 		else // 2.2
// 		{
// 			return (0);
// 		}
// 	}
// 	return (ret);
// }
//
// int		helper_print_str_padding(t_options *option, int len, int after)
//{

// {
// 	int		i;
// 	int		ret;
//
// 	ret = 0;
// 	i = -1;
// 	if (((!after && option->left_justify) || (after && !option->left_justify))
// 			|| (option->point && (option->pad_deux > len)))
// 		return (0);
// 	while (++i < option->pad_un - len)
// 	{
// 		if (option->left_zeros && !option->left_justify)
// 			ret += ft_putchar_ret('0');
// 		else
// 			ret += ft_putchar_ret(' ');
// 	}
// 	return (ret);
// }
int		helper_print_str_padding(t_options *option, int len, int after)
{
	int 	ret;
	int 	padding;
	char	c;

	ret = 0;
	c = ' ';
	padding = option->pad_un - len;
	if (option->left_zeros && !option->left_justify)
		c = '0';
	if (after && option->left_justify)
		ret += ft_print_loop_ret(c, padding);
	if (!after && !option->left_justify)
		ret += ft_print_loop_ret(c, padding);
	return (ret);
}
