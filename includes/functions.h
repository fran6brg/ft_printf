#ifndef FUNCTIONS_H
# define FUNCTIONS_H

t_options		*create_new_option(const char *format, int i);
void				push_back_new_option(t_options **latest_option, t_options *new);

int   			extract_options(const char *format, t_options **options);

void 				print_t_options_list(t_options **options);
void 				print_t_option(t_options **option);

int					ft_printf(const char *format, ...);

#endif
