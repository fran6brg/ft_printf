#ifndef T_OPTIONS_H
# define T_OPTIONS_H
# include <string.h>

# define SPECIFIER_COUNT (11)

typedef struct			s_func
{
	char	option;
	int		(*func)(t_options*, va_list*);
}						t_func;

#endif
