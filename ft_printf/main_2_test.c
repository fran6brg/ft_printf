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
  */// 2. s
 /* printf("\n*************\n");
  printf("TESTS: s :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("str = -%.2s-\n", NULL);
  printf("REAL PRINTF RET :\n");
  ret2 = printf("str = -%.2s-\n", NULL);
  printf("ret for : ft_printf is %d || printf is%d\n", ret, ret2);
   printf("passed : str = -%%.2s-\n");
  printf("\n*************\n\n");
  printf("\n*************\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("str = -%15s-\n", s);
  printf("REAL PRINTF RET :\n");
  ret2 = printf("str = -%15s-\n", s);
  printf("ret for : ft_printf is %d || printf is%d\n", ret, ret2);
   printf("passed : str = -%%.2s-\n");
  printf("\n*************\n\n");

  // 3. d et i
  printf("\n*************\n");
  printf("TESTS: d i :\n");
  ret = ft_printf("d = % 10.40d\n", -10);
  ret2 = printf("e = % 10.40d\n", -10);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : d = -%%10.40d\n");
  ret = ft_printf("d = -% 75ld-\n", i);
  ret2 = printf("d = -% 75ld-\n", i);
  printf("\n*************\n");
  printf("\n*************\n");
  ret = ft_printf("i = -%-10i-\n", -5000);
  ret2 = printf("i = -%-10i-\n", -5000);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : i = -%%-9i-\n");
  printf("\n*************\n");
  printf("\n*************\n");
  // ft_printf("i = -%+-04i-\n", i);
 // printf("passed : i = -%%+-04i-\n");
 // printf("rslt p : i = -%+-04i-\n", i);
 // printf("\n*************\n");

*/
	   printf("\033[0;33mTEST>\t[%% 10.0d=%%4.5d=%%+#4.5d=%% 0-54.2d=%% 0-54.2d=%%- 0.2d=%%+-d=%% +-d-%%.4d-%%.4d-%%.d-%%.0d-%%d %%hd %%d %%ld]\", 0, 42, -42U, 2147483777LL, NULL - 1, NULL, 2147483647, -2147483648, 7, 12345, 1, 9, 126, 12356, 1456, -3456\n");
	ft_printf("\033[0;33mYOUR>\t[1//% 10.0d]\n", 0);
	   printf("\033[0;31mREAL>\t[1//% 10.0d]\n", 0);
	ft_printf("\033[0;33mYOUR>\t[2//%4.5d]\n", 42);
	   printf("\033[0;31mREAL>\t[2//%4.5d]\n", 42);
	ft_printf("\033[0;33mYOUR>\t[3//%+#4.5d]\n", -42U);
	   printf("\033[0;31mREAL>\t[3//%+#4.5d]\n", -42U);
	ft_printf("\033[0;33mYOUR>\t[4//% 0-54.2d]\n", 2147483777LL);
	   printf("\033[0;31mREAL>\t[4//% 0-54.2d]\n", 2147483777LL);
	ft_printf("\033[0;33mYOUR>\t[5//% 0-54.2d]\n", NULL - 1);
	   printf("\033[0;31mREAL>\t[5//% 0-54.2d]\n", NULL - 1);
	ft_printf("\033[0;33mYOUR>\t[6//%- 0.2d]\n", NULL);
	   printf("\033[0;31mREAL>\t[6//%- 0.2d]\n", NULL);
	ft_printf("\033[0;33mYOUR>\t[7//%+-d]\n", 2147483647);
	   printf("\033[0;31mREAL>\t[7//%+-d]\n", 2147483647);
	ft_printf("\033[0;33mYOUR>\t[8//% +-d]\n", -2147483648);
	   printf("\033[0;31mREAL>\t[8//% +-d]\n", -2147483648);
	ft_printf("\033[0;33mYOUR>\t[9//%.4d]\n", 7);
	   printf("\033[0;31mREAL>\t[9//%.4d]\n", 7);
	ft_printf("\033[0;33mYOUR>\t[10//%.4d]\n", 12345);
	   printf("\033[0;31mREAL>\t[10//%.4d]\n", 12345);
	ft_printf("\033[0;33mYOUR>\t[11//%.d]\n", 1);
	   printf("\033[0;31mREAL>\t[11//%.d]\n", 1);
	ft_printf("\033[0;33mYOUR>\t[12//%.0d]\n", 9);
	   printf("\033[0;31mREAL>\t[12//%.0d]\n", 9);
	ft_printf("\033[0;33mYOUR>\t[13//%d]\n", 126);
	   printf("\033[0;31mREAL>\t[13//%d]\n", 126);
	ft_printf("\033[0;33mYOUR>\t[14//%hd]\n", 12356);
	   printf("\033[0;31mREAL>\t[14//%hd]\n", 12356);
	ft_printf("\033[0;33mYOUR>\t[15//%d]\n", 1456);
	   printf("\033[0;31mREAL>\t[15//%d]\n", 1456);
	ft_printf("\033[0;33mYOUR>\t[16//%ld]\n", -3456);
	   printf("\033[0;31mREAL>\t[16//%ld]\n", -3456);


/*
  // 4. X x p o b
  printf("\n*************\n");
  printf("TESTS: X x p o b :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("p = -%12p-\n", s);
  printf("PRINTF RET :\n");
  ret2 = printf("p = -%12p-\n", s);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : p = -%%p-\n");
  printf("\n*************\n");
  printf("\n*************\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("%#20.2o||%#31o||%28.28o||%31o||\n", -144491672, 0, 2147492, 40);
  printf("PRINTF RET :\n");
  ret2 = printf("%#20.2o||%#31o||%28.28o||%31o||\n", -144491672, 0, 2147492, 40);
//  ret2 = printf("%#20.2o||\n%#31o||\n%28.28o||\n%31o||\n", -144491672, 0, 2147492, 40);
  printf("ret ft_printf %d || ret real_printf %d\n", ret, ret2);
  printf("passed : %%#20.2o %%#31o %%28.28o %%31o\n");
  printf("\n*************\n");
*/
/*
  // 4.bis. with #
  printf("\n*************\n");
  printf("TESTS: X x p o b with # :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("x = -%#12o-\n", 56465);
  ret2 = printf("x = -%#12o-\n", 56465);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : -%%x-\n");
  printf("\n*************\n");
*/
  // 5. floats
 /* float f1 = 100.123456111;
  double f2 = 100.123456789;

  printf("\n****** floats *******\n");
  printf("TESTS: f lf :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("f = -% +12.9f-\n", f1);
  ret2 = printf("f = -% +12.9f-\n", f1);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : -%%-12f-\n");
  printf("MY PRINTF RET :\n");
  ft_printf("lf = -%lf-\n", f2);
  printf("lf = -%lf-\n", f2);
  printf("ret ft_printf %d || ret real_printf %d\n", ret, ret2);
  printf("passed : -%%lf-\n");*/
  // printf("passed : f = -%%+-04f-\n");
  // printf("rslt p : f = -%+-04f-\n", f);
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
