#ifndef T_OPTIONS_H
# define T_OPTIONS_H
# include <string.h>

typedef struct	s_options
{
	char			type;
	char			*flags;
	//char			*minlen;
	//char			*maxlen;
	//int				idx;
	int				len;
	//int				pad;
	//int				pad_right;
	//int				zeropad;
	//int				nbrneg;
	//int				print;
	//int				fd;
	//size_t			size;
	struct s_options	*next;
}				t_options;

t_options	*create_new_option(const char *format, int i);
void	push_back_new_option(t_options **latest_option, t_options *new);
int   extract_options(const char *format, t_options **options);
int		ft_printf(const char *format, ...);

#endif
