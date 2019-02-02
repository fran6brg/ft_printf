#include <stdio.h>
#include "includes/t_options.h"
#include "includes/t_functions_pointers.h"
#include "includes/functions.h"
#include "3.Libft/libft.h"
//#include "includes/t_functions_pointers.h"

int main(int argc, char **argv)
{
  long int i = -2147488747762;
  // int j = 2;
  // int k = 3;
  char c = 'a';
  char *s = "lolololol";
  char *s2 = "lolololol";

  //ft_printf("char = %10c string = %.10s abc %#0+-i\n", c, s, i);
/*
  // 1. c
   ft_printf("char = -%0c-\n", c);
   printf("passed : char = -%%0c-\n");
   printf("rslt p : char = -%0c-\n", c);
   printf("\n*************\n\n");
  // 2. s
  printf("\n*************\n");
   ft_printf("str = -%0ss-\n", s);
   printf("passed : str = -%%0ss-\n");
   printf("rslt p : str = -%0ss-\n", s2);
   printf("\n*************\n\n");

  // 3. i
  printf("\n*************\n");
  ft_printf("i = -%d-\n", i);
  printf("passed : d = -%%0i-\n");
  printf("rslt p : d = -%d-\n", i);
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

  // 4. X x p o b
  printf("\n*************\n");
  ft_printf("p = -%12p-\n", s);
  printf("passed : p = -%%p-\n");
  printf("rslt p : p = -%12p-\n", s);
  printf("\n*************\n");
*/

  float f1 = 100.123456111;
  double f2 = 100.123456789;

  // 5. floats
  printf("\n****** floats *******\n");
  ft_printf("f = -%.10f-\n", f1);
  printf("passed : f = -%%.10f-\n");
  printf("rslt p : f = -%.10f-\n", f1);
  ft_printf("rslt p : d = -%lf-\n", f2);
  printf("passed : d = -%%lf-\n");
  printf("rslt p : d = -%lf-\n", f2);
  // printf("passed : f = -%%+-04f-\n");
  // printf("rslt p : f = -%+-04f-\n", f);
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
