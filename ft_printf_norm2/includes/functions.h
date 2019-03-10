/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:40:42 by fberger           #+#    #+#             */
/*   Updated: 2019/03/10 06:00:54 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "../libft/libft.h"
# include "t_functions_pointers.h"

t_options			*create_new_option(const char *format, int i);
void				push_back_new_option(t_options **latest_opt, t_options *n);
int					print_sign(t_options *opt, long long nb);
int					nb_have_a_sign(t_options *opt, long long nb);
int					nb_have_a_prefix(t_options *opt, long long value, int len);
int					print_prefix(t_options *opt, long long value);
int					ft_print_loop_ret(char c, int nb);
int					helper_nb_pad(t_options *opt, int l, int a, long long n);
int					helper_str_pad(t_options *opt, int ln, int aftr);
int					helper_f_pad(t_options *opt, int len, int after, int nb);
int					compute_new_option_len_in_format(const char *formt, int i);
int					ft_strchr_modified(const char *s, int c, int flen);
int					ft_strstr_modified(const char *m, const char *a, int flen);
int					get_base(t_options *opt);
int					ft_printf_base(t_options *opt, va_list *args);
int					ft_printf_char(t_options *opt, va_list *args);
int					ft_printf_string(t_options *opt, va_list *args);
int					ft_printf_floats(t_options *opt, va_list *args);
int					ft_printf_integer(t_options *opt, va_list *args);
int					ft_printf_modulo(t_options *opt, va_list *args);
int					ft_print_nstr_ret(char *str, int limit);
unsigned long long	get_utype(t_options *opt, va_list *args);
int					ft_putchar_ret(char c);
int					extract_options(const char *format, t_options **opts);
void				print_t_options_list(t_options **opts);
void				print_t_option(t_options **opt);
long long			get_type(t_options *opt, va_list *args);
int					ft_printf(const char *format, ...);

#endif
