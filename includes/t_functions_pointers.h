#ifndef T_OPTIONS_H
# define T_OPTIONS_H
# include <string.h>

# define NB_ACCEPTED_OPTIONS (11)

typedef struct			s_func
{
	char	option;
	int		(*func)(t_options*, va_list*);
}						t_func;

#endif
