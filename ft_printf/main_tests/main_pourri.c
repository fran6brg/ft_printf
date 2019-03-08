#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/t_options.h"
#include "../includes/t_functions_pointers.h"
#include "../includes/functions.h"
#include "../libft/libft.h"
char	*ft_strrev(char *str)
{
	int i;
	int j;
	char	c;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (j > i)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		j--;
		i++;
	}
	return (str);
}
/*
void	ft_putnbr_base(int value, int base)
{
	char	c;
	unsigned int	taf;

	taf = value;
	if (base < 2 || base > 16)
		return ;
	if (value < 0)
		taf = -value;
	if (taf >= base)
		ft_putnbr_base(taf / base, base);
	c = (taf % base < 10) ? (taf % base) + '0' : (taf % base) + ('A' - 10);
	write(1, &c, 1);
}*/

#include <string.h>

int main()
{
	float base = -163.1253;
	int value = 5;
	char tab[value];
	while (value > 0)
		tab[value--] = 'c';
//	unsigned long long d = 18446744065119617025LL;

//	value = base < 0 ? -base : base;
//	printf("%lu\n", strlen("-0000000000000000000000000000000000000010"));
//	printf("%8.1i\n", 550);
//	printf("% -2.25i\n", 550);
//	printf("%-25i\n", -550);
//	printf("%-25i\n", -550);
//	printf("%-.25i\n", -550);
//	printf("%25i", -550);
	value = ft_printf("%5.x%5.0x", 0, 0);
	printf("\nret = %i", value);
//ft_putnbr_base(value, base);
}
/*pad1 - pad2 - sign --> print space
pad2 - len - (!sign is print && have a sign) --> */
