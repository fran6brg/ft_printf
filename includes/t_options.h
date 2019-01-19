#ifndef T_FUNCTIONS_POINTERS_H
# define T_FUNCTIONS_POINTERS_H
# include <string.h>

typedef struct	s_options
{
	char			type; // = la position du % + option->flen
	char			*flags; // = ft_strsub de ce qu'il y a entre le % et le type
	//char			*minlen;
	//char			*maxlen;
	int				fpos; // position dans la string
	int				flen; // == nb of char, between % and the type, in format
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
