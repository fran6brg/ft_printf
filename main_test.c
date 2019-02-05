#include <stdio.h>
#include "includes/t_options.h"
#include "includes/t_functions_pointers.h"
#include "includes/functions.h"
#include "3.Libft/libft.h"
//#include "includes/t_functions_pointers.h"

int main(int argc, char **argv)
{
	int ret;
	int ret2;
  long int i = -2147488747762;
  int i2 = -214742;
  // int j = 2;
  // int k = 3;
  char c = 'a';
  char *s = "lolololol";
  char *s2 = "lolololol";

  //ft_printf("char = %10c string = %.10s abc %#0+-i\n", c, s, i);


  // 0. nothing
 /* printf("\n*************\n");
  printf("TESTS: simple string :\n");
  printf("MY PRINTF RET :\n");
  ret =ft_printf("Salut");
  printf("\npassed arg is nothing\n");
  ret2 =printf("Salut\n");
  printf("ret for : ft_printf is %d || printf is%d", ret, ret2);
  printf("\n*************\n");

  // 1. c
  printf("\n*************\n");
  printf("TESTS: c :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("char = -%c-\n", c);
  ret2 = printf("char = -%c-\n", c);
  printf("passed : -%%c-\n");
  printf("ret for : ft_printf is %d || printf is%d", ret, ret2);
   printf("\n*************\n\n");
  // 2. s
  printf("\n*************\n");
  printf("TESTS: s :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("str = -%ss-\n", s);
   ret2 = printf("str = -%ss-\n", s2);
   printf("passed : str = -%%s-\n");
  printf("ret for : ft_printf is %d || printf is%d", ret, ret2);
   pMaMaMaMaÿQrintf("\n*************\n\n");

  // 3. d et i


  printf("\n*************\n");
  printf("\033[0;33mTEST>\t[%% .40d=%% 10.40d=%% 10.40d=%%10.0d=%%+010.d=%%10.0d=%%+ 010.d]\n");
  // ft_printf("\033[0;33mYOUR>\t[% .40d=% 10.40d=% 10.40d=%10.0d=%+010.d=%10.0d=%+ 010.d]\n", 1, 10, -10, -10, -10, 10, 10);
  // printf("\033[0;31mREAL>\t[% .40d=% 10.40d=% 10.40d=%10.0d=%+010.d=%10.0d=%+ 010.d]\n", 1, 10, -10, -10, -10, 10, 10);
  ft_printf("\033[0;33mYOUR>\t[% .40d]\n", 1);
  printf("\033[0;31mREAL>\t[% .40d]\n", 1);
  printf("\n*************\n");

  */
  printf("\n*************\n");
  printf("\033[0;33mTEST>\t[%%10.8lld=%%#25.22llda=%%#-+ 08.5llda]\", 100LL, -1LL, 100LL\n");
  // ft_printf("\033[0;33mYOUR>\t[%10.8lld=%#25.22llda=%#-+ 08.5llda]\n", 100LL, -1LL, 100LL);
  // printf("\033[0;31mREAL>\t[%10.8lld=%#25.22llda=%#-+ 08.5llda]\n", 100LL, -1LL, 100LL);
  ft_printf("\033[0;33mYOUR>\t[%10.8lld]\n", 100LL);
  printf("\033[0;31mREAL>\t[%10.8lld]\n", 100LL);
  printf("\n*************\n");
  /*
  printf("\n*************\n");
  printf("TESTS: d i :\n");
  ret = ft_printf("d = -%ld-\n", i);
  ret2 = printf("d = -%ld-\n", i);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : d = -%%0i-\n");
  printf("\n*************\n");
  printf("\n*************\n");
  ret = ft_printf("i = -%-9i-\n", -5000);
  ret2 = printf("i = -%-9i-\n", -5000);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : i = -%%-9i-\n");
  printf("\n*************\n");
  printf("\n*************\n");
 // ft_printf("i = -%+-04i-\n", i);
 // printf("passed : i = -%%+-04i-\n");
 // printf("rslt p : i = -%+-04i-\n", i);
 // printf("\n*************\n");

  // 4. X x p o b
  printf("\n*************\n");
  printf("TESTS: X x p o b :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("p = -%12p-\n", s);
  ret2 = printf("p = -%12p-\n", s);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : p = -%%p-\n");
  printf("\n*************\n");

*/

  // 4.bis. with #
  /*printf("\n*************\n");
  printf("TESTS: X x p o b with # :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("x = -%#12o-\n", 56465);
  ret2 = printf("x = -%#12o-\n", 56465);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : -%%x-\n");
  printf("\n*************\n");

  // 5. floats
  float f1 = 100.123456111;
  double f2 = 100.123456789;

  printf("\n****** floats *******\n");
  printf("TESTS: f lf :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("f = -%.10f-\n", f1);
  ret2 = printf("f = -%.10f-\n", f1);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : -%%.10f-\n");
  printf("MY PRINTF RET :\n");
  ft_printf("lf = -%lf-\n", f2);
  printf("lf = -%lf-\n", f2);
  printf("ret ft_printf %d || ret real_printf %d\n", ret, ret2);
  printf("passed : -%%lf-\n");
  // printf("passed : f = -%%+-04f-\n");
  // printf("rslt p : f = -%+-04f-\n", f);
   */
  printf("\n\n");
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
