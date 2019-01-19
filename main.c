#include <stdio.h>
#include "3.Libft/libft.h"

int main(int argc, char **argv)
{
  /*

  t_func	g_func[SPECIFIER_COUNT] =
  {

  	1. {'c', &print_char},*/
    printf("*********\n 'c', print_char\n\n");
    char c = 'a';
    printf("  defined \n");
    printf("    sans option 'a' : %c\n", c);
    printf("    option 15 'a'   : %15c\n", c);
    printf("  undefined \n");
    //printf("    option 015 'a'  : %015c\n", c);
    //printf("    option +015 'a' : %+015c\n", c);
    printf("\n");

  	//{'C', &print_char},
    //printf("*********\n 'C', &print_char\n\n");

  /*	// 2. {'%', &print_char},
    printf("*********\n 'pourcentage', &print_char\n\n");
    int x = 10;
    int y = 100;
    printf("  defined \n");
    printf("    sans option                   : %%\n");
    //printf("    sans option 'x pourcentage y' : %%\n", (x / y));
    printf("  undefined \n");
    printf("\n");

  	//{'s', &print_string},
    printf("*********\n 's', &print_char\n\n");
    printf("  defined \n");
    printf("    sans option str     : %s\n", ft_strdup("grosses liasses grosses fesses"));
    printf("    option .            : %.s\n", ft_strdup("grosses liasses grosses fesses"));
    printf("    option .15          : %.15s\n", ft_strdup("grosses liasses grosses fesses"));
    //printf("    sans option 'x pourcentage y' : %%\n", (x / y));
    printf("  undefined \n");
    //printf("    option -+#0         : %-+#0s\n", ft_strdup("grosses liasses grosses fesses"));
    // -+#
    // flag '0' is ignored when flag '-' is present

  	//{'S', &print_unicode_string},
    //printf("*********\n 'S', &print_unicode_string\n\n");

  	//{'r', &print_string},
    //printf("*********\n 'r', &print_string\n\n");

  	//{'d', &print_integer},
    printf("*********\n 'd', &print_integer\n\n");

  	//{'D', &print_integer},
    //printf("*********\n 'D', &print_integer\n\n");

  	//{'i', &print_integer},
    printf("*********\n 'i', &print_integer\n\n");
    int i = -42;
    printf("  defined \n");
    printf("    sans option i  : %i\n", i);
    printf("    option 15 i    : %15i\n", i);
    printf("    option -  i    : %-i\n", i);
    // + = 2 effets ; flag - --> put espace | flag 0-->put 0 | flag + --> put espace && signe positif
    printf("    option +15 i   : %+15i\n", i);
    printf("    option +015 i  : %+015i\n", i);
    // warning: flag '0' is ignored when flag '-' is present [-Wformat]
    printf("    option -015 i  : %-015i\n", i);
    printf("    option +-15 i  : %+-15i\n", i);
    // warning: flag '0' is ignored when flag '-' is present [-Wformat]
    printf("    option +-015 i : %+-015i\n", i);
    printf("  undefined \n");
    printf("\n");

  	//{'u', &print_integer},
    printf("*********\n 'u', &print_integer\n\n");

  	//{'U', &print_integer},
    //printf("*********\n 'U', &print_integer\n\n");

  	//{'x', &print_base},
    printf("*********\n 'x', &print_base\n\n");

  	//{'p', &print_base},
    printf("*********\n 'p', &print_base\n\n");

  	//{'X', &print_base},
    printf("*********\n 'X', &print_base\n\n");

  	//{'o', &print_base},
    printf("*********\n 'o', &print_base\n\n");

  	//{'O', &print_base},
    //printf("*********\n 'O', &print_base\n\n");

  	//{'b', &print_base},
    //printf("*********\n 'b', &print_base\n\n");

  	//{'f', &print_floats},
    printf("*********\n 'f', &print_floats\n\n");
    float f = -42.123456789;
    printf("  defined \n");
    printf("    sans option f   : %f\n", f);
    printf("    option 8.2 f    : %8.2f\n", f);
    printf("    option 20.2 f    : %20.2f\n", f);*/

  	//{'F', &print_floats},
    //printf("*********\n 'F', &print_floats\n\n");
  //};
  return (1);
}

/*
• Vous ne ferez pas la gestion de buffer présente dans la fonction printf de la libc.
• Vous devez gérer les conversions suivantes : csp
• Vous devez gérer les conversions suivantes : diouxX avec les flags hh, h, l, ll
• Vous devez gérer la conversion suivante : f avec les flags l et L
• Vous devez gérer le %%
• Vous devez gérer les flags #0-+ et espace
• Vous devez gérer la taille minimum du champ
• Vous devez gérer la précision
*/
