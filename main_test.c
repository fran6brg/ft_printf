#include <stdio.h>
#include "includes/t_options.h"
#include "includes/t_functions_pointers.h"
#include "includes/functions.h"
#include "3.Libft/libft.h"
//#include "includes/t_functions_pointers.h"

int main(int argc, char **argv)
{
  int i = 10000;
  // int j = 2;
  // int k = 3;
  char c = 'a';
  char *s = "lolololol";
  char *s2 = "lolololol";

  //ft_printf("char = %10c string = %.10s abc %#0+-i\n", c, s, i);

  // 1. c
  // printf("\n*************\n\n");
  // ft_printf("char = -%010c-\n", c);
  // printf("passed : char = -%%010c-\n");
  // printf("rslt p : char = -%010c-\n", c);
  // printf("\n*************\n\n");

  // 2. s
  // printf("\n*************\n\n");
  // ft_printf("str = -%-0000000 15ss-\n", s);
  // printf("passed : str = -%%0000000 15ss-\n");
  // printf("rslt p : str = -%-0000000 15ss-\n", s2);
  // printf("\n*************\n\n");

  // 3. i
  printf("\n*************\n");
  ft_printf("i = -%+-04i-\n", i);
  printf("passed : i = -%%+-04i-\n");
  printf("rslt p : i = -%+-04i-\n", i);
  printf("\n*************\n");
  printf("\n*************\n");
  ft_printf("i = -%-9i-\n", -5000);
  printf("passed : i = -%%-9i-\n");
  printf("rslt p : i = -%-9i-\n", -5000);
  printf("\n*************\n");
  printf("\n*************\n");
  ft_printf("i = -%+-04i-\n", i);
  printf("passed : i = -%%+-04i-\n");
  printf("rslt p : i = -%+-04i-\n", i);
  printf("\n*************\n");

  return (1);
}

//https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

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
