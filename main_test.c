#include <stdio.h>
#include "3.Libft/libft.h"
#include "includes/t_options.h"
//#include "includes/t_functions_pointers.h"

int main(int argc, char **argv)
{
  int i = 1;
  int j = 2;
  int k = 3;
  char *s = "lol";

  ft_printf("string = %.10s abc %#0+- def %#0+-100i fgh %i --- %%\n", s, i, j, k);
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
