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
 */ // 2. s
  /*printf("\n*************\n");
   printf("\033[0;33mTEST>\t[%%.2s || %% 10.5s || %%- 10.9s]\", 100LL, -1LL, 100LL\n");
   ret = ft_printf("\033[0;33mYOUR>\t[%.2s]\n", s);
   ret2 = printf("\033[0;32mYOUR>\t[%.2s]\n", s);
  printf("ret for : ft_printf is %d || printf is%d", ret, ret2);
   ret = ft_printf("\033[0;33mYOUR>\t[%10.5s]\n", s);
   ret2 = printf("\033[0;32mYOUR>\t[%10.5s]\n", s);
  printf("ret for : ft_printf is %d || printf is%d", ret, ret2);
   ret = ft_printf("\033[0;33mYOUR>\t[%- 10.7s]\n", s);
   ret2 = printf("\033[0;32mYOUR>\t[%- 10.7s]\n", s);
  printf("ret for : ft_printf is %d || printf is%d", ret, ret2);
   printf("\n*************\n\n");


  // 3. d et i

  printf("\n*************\n");
  printf("\033[0;33mTEST>\t[%%-10d %% d %%+d %%010d %%hhd %%llda]\", 3, 3, 3, 1, 0, 18446744065119617025LL\n");
	// ft_printf("\033[0;33mYOUR>\t[%-10d]\n", 3);
  //    printf("\033[0;31mREAL>\t[%-10d]\n", 3);
  ft_printf("\033[0;33mYOUR>\t[% d]\n", 3);
     printf("\033[0;31mREAL>\t[% d]\n", 3);
  // ft_printf("\033[0;33mYOUR>\t[%+d]\n", 3);
  // 	 printf("\033[0;31mREAL>\t[%+d]\n", 3);
	// ft_printf("\033[0;33mYOUR>\t[%010d]\n", 1);
	//    printf("\033[0;31mREAL>\t[%010d]\n", 1);
	// ft_printf("\033[0;33mYOUR>\t[%llda]\n", 18446744065119617025LL);
	// 	 printf("\033[0;31mREAL>\t[%llda]\n", 18446744065119617025LL);
  printf("\n*************\n");

  printf("\n*************\n");
   printf("\033[0;33mTEST>\t[%%10.8lld || %%#25.22llda || %%#-+ 08.5llda]\", 100LL, -1LL, 100LL\n");
  //ft_printf("\033[0;33mYOUR>\t[%10.8lld=%#25.22llda=%#-+ 08.5llda]\n", 100LL, -1LL, 100LL);
  //printf("\033[0;31mREAL>\t[%10.8lld=%#25.22llda=%#-+ 08.5llda]\n", 100LL, -1LL, 100LL);
  // ft_printf("\033[0;33mYOUR>\t[%10.8lld]\n", 100LL);
  // printf("\033[0;31mREAL>\t[%10.8lld]\n", 100LL);
	// printf("\n*************\n");
  ft_printf("\033[0;33mYOUR>\t[%#25.22llda=]\n", -1LL);
  printf("\033[0;31mREAL>\t[%#25.22llda=]\n", -1LL);
	// // printf("\n*************\n");
  // ft_printf("\033[0;33mYOUR>\t[%#-+ 08.5llda]\n", 100LL);
  // printf("\033[0;31mREAL>\t[%#-+ 08.5llda]\n", 100LL);
	// printf("\n*************\n");
  // ft_printf("\033[0;33mYOUR>\t[%ld]\n", -3456);
  // printf("\033[0;31mREAL>\t[%ld]\n", -3456);

  printf("\n*************\n");
  printf("\033[0;33mTEST>\t[%% .40d=%% 10.40d=%% 10.40d=%%10.0d=%%+010.d=%%10.0d=%%+ 010.d]\n");
  // ft_printf("\033[0;33mYOUR>\t[% .40d=% 10.40d=% 10.40d=%10.0d=%+010.d=%10.0d=%+ 010.d]\n", 1, 10, -10, -10, -10, 10, 10);
  // printf("\033[0;31mREAL>\t[% .40d=% 10.40d=% 10.40d=%10.0d=%+010.d=%10.0d=%+ 010.d]\n", 1, 10, -10, -10, -10, 10, 10);
  // ft_printf("\033[0;33mYOUR>\t[% .40d]\n", 1);
  //    printf("\033[0;31mREAL>\t[% .40d]\n", 1);
	 ft_printf("\033[0;33mYOUR>\t[% 10.40d]\n", 10);
 	   printf("\033[0;31mREAL>\t[% 10.40d]\n", 10);
	ft_printf("\033[0;33mYOUR>\t[% 10.40d]\n", -10);
	   printf("\033[0;31mREAL>\t[% 10.40d]\n", -10);
	// ft_printf("\033[0;33mYOUR>\t[%10.0d]\n", -10);
	// 	 printf("\033[0;31mREAL>\t[%10.0d]\n", -10);
	// ft_printf("\033[0;33mYOUR>\t[%+010.d]\n", 10);
	// 	 printf("\033[0;31mREAL>\t[%+010.d]\n", 10);
	ft_printf("\033[0;33mYOUR>\t[%+ 010.d]\n", 10);
		 printf("\033[0;31mREAL>\t[%+ 010.d]\n", 10);
  printf("\n*************\n");

	printf("\n*************\n");
	printf("\033[0;33mTEST>\t[%% 10.0d=%%+ 010.d=%% 10.0d]\", -10, -10, 10\n");
	// ft_printf("\033[0;33mYOUR>\t[% 10.0d=%+ 010.d=% 10.0d]\n", -10, -10, 10);
	// 	 printf("\033[0;31mREAL>\t[% 10.0d=%+ 010.d=% 10.0d]\n", -10, -10, 10);
	ft_printf("\033[0;33mYOUR>\t[% 10.0d]\n", -10);
	   printf("\033[0;31mREAL>\t[% 10.0d]\n", -10);
	ft_printf("\033[0;33mYOUR>\t[%+ 010.d]\n", -10);
	   printf("\033[0;31mREAL>\t[%+ 010.d]\n", -10);
  ft_printf("\033[0;33mYOUR>\t[% 10.0d]\n", 10);
 	   printf("\033[0;31mREAL>\t[% 10.0d]\n", 10);

	printf("\n*************\n");


  // printf("\n*************\n");
  // printf("TESTS: d i :\n");
  // ret = ft_printf("d = -%ld-\n", i);
  // ret2 = printf("d = -%ld-\n", i);
  // printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  // printf("passed : d = -%%0i-\n");
  // printf("\n*************\n");
  // printf("\n*************\n");
  // ret = ft_printf("i = -%-9i-\n", -5000);
  // ret2 = printf("i = -%-9i-\n", -5000);
  // printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  // printf("passed : i = -%%-9i-\n");
  // printf("\n*************\n");
  // printf("\n*************\n");
 // ft_printf("i = -%+-04i-\n", i);
 // printf("passed : i = -%%+-04i-\n");
 // printf("rslt p : i = -%+-04i-\n", i);
 // printf("\n*************\n");

 printf("\n*************\n");
 printf("\033[0;33mTEST>\t['%%-d'%%-+d'%%+-d'%%+d'%% d'%% .0d'%% +d'%%03d'%%-03d'%%-+0003d'%%0+ 3d']\", 5, 5, 5, 5, -5, -5, 0, 5, 5, -5, -5, -5U\n");
 // ft_printf("\033[0;33mYOUR>\t['%-d'%-+d'%+-d'%+d'% d'% .0d'% +d'%03d'%-03d'%-+0003d'%0+ 3d']\n", 5, 5, 5, 5, -5, -5, 0, 5, 5, -5, -5, -5U);
	//   printf("\033[0;31mREAL>\t['%-d'%-+d'%+-d'%+d'% d'% .0d'% +d'%03d'%-03d'%-+0003d'%0+ 3d']\n", 5, 5, 5, 5, -5, -5, 0, 5, 5, -5, -5, -5U);
 ft_printf("\033[0;33mYOUR>\t['%-d']\n", 5);
    printf("\033[0;31mREAL>\t['%-d']\n", 5);
 ft_printf("\033[0;33mYOUR>\t['%-+d']\n", 5);
    printf("\033[0;31mREAL>\t['%-+d']\n", 5);
 ft_printf("\033[0;33mYOUR>\t['%+-d']\n", 5);
    printf("\033[0;31mREAL>\t['%+-d']\n", 5);
 ft_printf("\033[0;33mYOUR>\t['%+d']\n", 5);
    printf("\033[0;31mREAL>\t['%+d']\n", 5);
 ft_printf("\033[0;33mYOUR>\t['% d']\n", -5);
    printf("\033[0;33mREAL>\t['% d']\n", -5);
 ft_printf("\033[0;33mYOUR>\t['% .0d']\n", -5);
   	printf("\033[0;33mREAL>\t['% .0d']\n", -5);
 ft_printf("\033[0;33mYOUR>\t['% +d']\n", 0);
  	printf("\033[0;33mREAL>\t['% +d']\n", 0);
 ft_printf("\033[0;33mYOUR>\t['%03d']\n", 5);
  	printf("\033[0;33mREAL>\t['%03d']\n", 5);
 ft_printf("\033[0;33mYOUR>\t['%-03d']\n", 5);
  	printf("\033[0;33mREAL>\t['%-03d']\n", 5);
 ft_printf("\033[0;33mYOUR>\t['%-+0003d']\n", -5);
    printf("\033[0;33mREAL>\t['%-+0003d']\n", -5);
 ft_printf("\033[0;33mYOUR>\t['%0+ 3d']\n", -5U);
    printf("\033[0;33mREAL>\t['%0+ 3d']\n", -5U);

 printf("\n*************\n");
*/
 printf("\033[0;33mTEST>\t[%% 10.0d=%%4.5d=%%+#4.5d=%% 0-54.2d=%% 0-54.2d=%%- 0.2d=%%+-d=%% +-d-%%.4d-%%.4d-%%.d-%%.0d-%%d %%hd %%d %%ld]\", 0, 42, -42U, 2147483777LL, NULL - 1, NULL, 2147483647, -2147483648, 7, 12345, 1, 9, 126, 12356, 1456, -3456\n");
// ft_printf("\033[0;33mYOUR>\t[% 10.0d]\n", 0);
//  printf("\033[0;31mREAL>\t[% 10.0d]\n", 0);
// ft_printf("\033[0;33mYOUR>\t[%4.5d]\n", 42);
//  printf("\033[0;31mREAL>\t[%4.5d]\n", 42);
// ft_printf("\033[0;33mYOUR>\t[%+#4.5d]\n", -42U);
//  printf("\033[0;31mREAL>\t[%+#4.5d]\n", -42U);
// ft_printf("\033[0;33mYOUR>\t[% 0-54.2d]\n", 2147483777LL);
//  printf("\033[0;31mREAL>\t[% 0-54.2d]\n", 2147483777LL);
ft_printf("\033[0;33mYOUR>\t[% 0-54.2d]\n", NULL - 1);
 printf("\033[0;31mREAL>\t[% 0-54.2d]\n", NULL - 1);
ft_printf("\033[0;33mYOUR>\t[%- 0.2d]\n", NULL);
 printf("\033[0;31mREAL>\t[%- 0.2d]\n", NULL);
// ft_printf("\033[0;33mYOUR>\t[%+-d]\n", 2147483647);
//  printf("\033[0;31mREAL>\t[%+-d]\n", 2147483647);
// ft_printf("\033[0;33mYOUR>\t[% +-d]\n", -2147483648);
//  printf("\033[0;31mREAL>\t[% +-d]\n", -2147483648);
// ft_printf("\033[0;33mYOUR>\t[%.4d]\n", 7);
//  printf("\033[0;31mREAL>\t[%.4d]\n", 7);
// ft_printf("\033[0;33mYOUR>\t[%.4d]\n", 12345);
//  printf("\033[0;31mREAL>\t[%.4d]\n", 12345);
// ft_printf("\033[0;33mYOUR>\t[%.d]\n", 1);
//  printf("\033[0;31mREAL>\t[%.d]\n", 1);
// ft_printf("\033[0;33mYOUR>\t[%.0d]\n", 9);
//  printf("\033[0;31mREAL>\t[%.0d]\n", 9);
// ft_printf("\033[0;33mYOUR>\t[%d]\n", 126);
//  printf("\033[0;31mREAL>\t[%d]\n", 126);
// ft_printf("\033[0;33mYOUR>\t[%hd]\n", 12356);
//  printf("\033[0;31mREAL>\t[%hd]\n", 12356);
// ft_printf("\033[0;33mYOUR>\t[%d]\n", 1456);
//  printf("\033[0;31mREAL>\t[%d]\n", 1456);
ft_printf("\033[0;33mYOUR>\t[%ld]\n", -3456);
 printf("\033[0;31mREAL>\t[%ld]\n", -3456);
/*
  // 4. X x p o b
  printf("\n*************\n");
  printf("TESTS: X x p o b :\n");
  printf("MY PRINTF RET :\n");
  ret = ft_printf("p = -%12p-\n", s);
  ret2 = printf("p = -%12p-\n", s);
  printf("ret ft_printf %d || ret real_printf %d\n\n", ret, ret2);
  printf("passed : p = -%%p-\n");
  printf("\n*************\n");


  // 4.bis. with #
  printf("\n*************\n");
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
