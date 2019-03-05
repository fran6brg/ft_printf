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
  // char *s = "lolololol";
  char *s2 = "lolololol";

  //ft_printf("char = %10c string = %.10s abc %#0+-i\n", c, s, i);

	/*

  // 0. nothing
  printf("\n*************\n");
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
	ft_printf("\033[0;33mYOUR>\t[%llda]\n", 18446744065119617025LL);
		 printf("\033[0;31mREAL>\t[%llda]\n", 18446744065119617025LL);
  printf("\n*************\n");


  printf("\033[0;33mTEST>\t[%%10.8lld || %%#25.22llda || %%#-+ 08.5llda]\", 100LL, -1LL, 100LL\n");
	// ft_printf("\033[0;33mYOUR>\t[%10.8lld=%#25.22llda=%#-+ 08.5llda]\n", 100LL, -1LL, 100LL);
  //    printf("\033[0;31mREAL>\t[%10.8lld=%#25.22llda=%#-+ 08.5llda]\n", 100LL, -1LL, 100LL);
  ft_printf("\033[0;33mYOUR>\t[%10.8lld]\n", 100LL);
     printf("\033[0;31mREAL>\t[%10.8lld]\n", 100LL);
  ft_printf("\033[0;33mYOUR>\t[%#25.22lld]\n", -1LL);
     printf("\033[0;31mREAL>\t[%#25.22lld]\n", -1LL);
  ft_printf("\033[0;33mYOUR>\t[%#-+ 08.5lld]\n", 100LL);
     printf("\033[0;31mREAL>\t[%#-+ 08.5lld]\n", 100LL);
  // ft_printf("\033[0;33mYOUR>\t[%ld]\n", -3456);
  //    printf("\033[0;31mREAL>\t[%ld]\n", -3456);


  //printf("\n*************\n");
//   ft_printf("\033[0;33mYOUR>\t[% .40d=% 10.40d=% 10.40d=%10.0d=%+010.d=%10.0d=%+ 010.d]\n", 1, 10, -10, -10, -10, 10, 10);
  // printf("\033[0;31mREAL>\t[% .40d=% 10.40d=% 10.40d=%10.0d=%+010.d=%10.0d=%+ 010.d]\n", 1, 10, -10, -10, -10, 10, 10);
  ft_printf("\033[0;33mYOUR>\t[% .40d]\n", 1);
     printf("\033[0;31mREAL>\t[% .40d]\n", 1);
	ft_printf("\033[0;33mYOUR>\t[% 10.40d]\n", 10);
 	   printf("\033[0;31mREAL>\t[% 10.40d]\n", 10);
  ft_printf("\033[0;33mYOUR>\t[% 10.40d]\n", -10);
	   printf("\033[0;31mREAL>\t[% 10.40d]\n", -10);
	ft_printf("\033[0;33mYOUR>\t[%10.0d]\n", -10);
		 printf("\033[0;31mREAL>\t[%10.0d]\n", -10);
	// ft_printf("\033[0;33mYOUR>\t[%+010.d]\n", 10);
	// 	 printf("\033[0;31mREAL>\t[%+010.d]\n", 10);
  // ft_printf("\033[0;33mYOUR>\t[%+ 010.d]\n", 10);
	//    printf("\033[0;31mREAL>\t[%+ 010.d]\n", 10);


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
*/
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
/*

 printf("\n*************\n");
 printf("\033[0;33mTEST>\t[%% 10.0d=%%4.5d=%%+#4.5d=%% 0-54.2d=%% 0-54.2d=%%- 0.2d=%%+-d=%% +-d-%%.4d-%%.4d-%%.d-%%.0d-%%d %%hd %%d %%ld]\", 0, 42, -42U, 2147483777LL, NULL - 1, NULL, 2147483647, -2147483648, 7, 12345, 1, 9, 126, 12356, 1456, -3456\n");
ft_printf("\033[0;33mYOUR>\t[% 10.0d]\n", 0);
 printf("\033[0;31mREAL>\t[% 10.0d]\n", 0);
ft_printf("\033[0;33mYOUR>\t[%4.5d]\n", 42);
 printf("\033[0;31mREAL>\t[%4.5d]\n", 42);
ft_printf("\033[0;33mYOUR>\t[%+#4.5d]\n", -42U);
 printf("\033[0;31mREAL>\t[%+#4.5d]\n", -42U);
ft_printf("\033[0;33mYOUR>\t[% 0-54.2d]\n", 2147483777LL);
 printf("\033[0;31mREAL>\t[% 0-54.2d]\n", 2147483777LL);
ft_printf("\033[0;33mYOUR>\t[% 0-54.2d]\n", NULL - 1);
 printf("\033[0;31mREAL>\t[% 0-54.2d]\n", NULL - 1);
ft_printf("\033[0;33mYOUR>\t[%- 0.2d]\n", NULL);
 printf("\033[0;31mREAL>\t[%- 0.2d]\n", NULL);
ft_printf("\033[0;33mYOUR>\t[%+-d]\n", 2147483647);
 printf("\033[0;31mREAL>\t[%+-d]\n", 2147483647);
ft_printf("\033[0;33mYOUR>\t[% +-d]\n", -2147483648);
 printf("\033[0;31mREAL>\t[% +-d]\n", -2147483648);
ft_printf("\033[0;33mYOUR>\t[%.4d]\n", 7);
 printf("\033[0;31mREAL>\t[%.4d]\n", 7);
ft_printf("\033[0;33mYOUR>\t[%.4d]\n", 12345);
 printf("\033[0;31mREAL>\t[%.4d]\n", 12345);
ft_printf("\033[0;33mYOUR>\t[%.d]\n", 1);
 printf("\033[0;31mREAL>\t[%.d]\n", 1);
ft_printf("\033[0;33mYOUR>\t[%.0d]\n", 9);
 printf("\033[0;31mREAL>\t[%.0d]\n", 9);
ft_printf("\033[0;33mYOUR>\t[%d]\n", 126);
 printf("\033[0;31mREAL>\t[%d]\n", 126);
ft_printf("\033[0;33mYOUR>\t[%hd]\n", 12356);
 printf("\033[0;31mREAL>\t[%hd]\n", 12356);
ft_printf("\033[0;33mYOUR>\t[%d]\n", 1456);
 printf("\033[0;31mREAL>\t[%d]\n", 1456);
ft_printf("\033[0;33mYOUR>\t[%ld]\n", -3456);
 printf("\033[0;31mREAL>\t[%ld]\n", -3456);


 // printf("\n*************\n");
 // printf("\033[0;33mTEST>\t[%%+040.2i %%040.2i %%+012.2ji %%0+32.2i]\", -2097948570, -2097948570, 0, -1046073861\n");
 // ft_printf("\033[0;33mYOUR>\t[%+040.2i]\n", -2097948570);
 //    printf("\033[0;31mREAL>\t[%+040.2i]\n", -2097948570);
 // ft_printf("\033[0;33mYOUR>\t[%040.2i]\n", -2097948570);
 //    printf("\033[0;31mREAL>\t[%040.2i]\n", -2097948570);
 // ft_printf("\033[0;33mYOUR>\t[!%+012.2i!]\n", 0);
 //    printf("\033[0;31mREAL>\t[!%+012.2i!]\n", 0);
 // ft_printf("\033[0;33mYOUR>\t[%0+32.2i]\n", -1046073861);
 //    printf("\033[0;31mREAL>\t[%0+32.2i]\n", -1046073861);
 // printf("\n*************\n");


 char *lala = "hello\n\tworld";
 char *s = "moulitest: \t";

	 // printf("\n1. --------------\n");
	 printf("%%06.d, 36\n");
   ft_printf("ft>%06.d\n", 36);
	    printf("pr>%06.d\n", 36);
	 // printf("\n2. --------------\n");
	 printf("%%06.d, 123456789\n");
   ft_printf("ft>%06.d\n", 123456789);
	    printf("pr>%06.d\n", 123456789);
	 // printf("\n3. --------------\n");
	 printf("%%#20.15X, lala\n");
   ft_printf("ft>%#20.15X\n", lala);
	    printf("pr>%#20.15X\n", lala);
	 // printf("\n4. --------------\n");
	 printf("%%#20.15o, lala\n");
   ft_printf("ft>%#20.15o\n", lala);
	    printf("pr>%#20.15o\n", lala);
	 // printf("\n5. --------------\n");
	 // printf("%%#.15o, lala\n");
   // ft_printf("ft>%#.15o\n", lala);
	 //    printf("pr>%#.15o\n", lala);
	 // printf("\n6. --------------\n");
	 // printf("%%#20o, lala\n");
   // ft_printf("ft>%#20o\n", lala);
	 //    printf("pr>%#20o\n", lala);
	 // printf("\n7. --------------\n");
	 // printf("%%o, lala\n");
   // ft_printf("ft>%o\n", lala);
	 //    printf("pr>%o\n", lala);
	 // printf("\n8. --------------\n");
	 // printf("%%#o, 0\n");
   // ft_printf("ft>%#o\n", 0);
	 //    printf("pr>%#o\n", 0);
	 // printf("\n9. --------------\n");
	 // printf("%%#X, 1\n");
   // ft_printf("ft>%#X\n", 1);
	 //    printf("pr>%#X\n", 1);
	 // printf("\n10 --------------\n");
	 // printf("%aaa%#.0o, 0\n");
   // ft_printf("ft>aaa%#.0o\n", 0);
	 //    printf("pr>aaa%#.0o\n", 0);
	 // printf("\n11 --------------\n");
	 // printf("%%#.0X, 0\n");
   // ft_printf("ft>%#.0X\n", 0);
	 //    printf("pr>%#.0X\n", 0);
	 // printf("\n12 --------------\n");
	 // printf("%%#.4X, 0\n");
   // ft_printf("ft>%#.4X\n", 0);
	 //    printf("pr>%#.4X\n", 0);
	 // printf("\n13 --------------\n");
	 // printf("%%cyo, '/'\n");
   // ft_printf("ft>%cyo\n", '/');
	 //    printf("pr>%cyo\n", '/');
	 // printf("\n14 --------------\n");
	 // printf("%%10cyo, '/'\n");
   // ft_printf("ft>%10cyo\n", '/');
	 //    printf("pr>%10cyo\n", '/');
	 // printf("\n15 --------------\n");
	 // printf("%%-10cyo, '/'\n");
   // ft_printf("ft>%-10cyo\n", '/');
	 //    printf("pr>%-10cyo\n", '/');
	 // printf("\n16 --------------\n");
	 // printf("%%.3cyo, '/'\n");
   // ft_printf("ft>%.3cyo\n", '/');
	 //    printf("pr>%.3cyo\n", '/');
	 // printf("\n17 --------------\n");
	 // printf("%%s yo, s\n");
   // ft_printf("ft>%s yo\n", s);
	 //    printf("pr>%s yo\n", s);
	 // printf("\n18 --------------\n");
	 // printf("%%.30s yo, s\n");
   // ft_printf("ft>%.30s yo\n", s);
	 //    printf("pr>%.30s yo\n", s);
	 // printf("\n19 --------------\n");
	 // printf("%%-.30s yo, s\n");
   // ft_printf("ft>%-.30s yo\n", s);
	 //    printf("pr>%-.30s yo\n", s);
	 // printf("\n20 --------------\n");
	 // printf("%%46.30s yo, s\n");
   // ft_printf("ft>%46.30s yo\n", s);
	 //    printf("pr>%46.30s yo\n", s);
	 // printf("\n21 --------------\n");
	 // printf("%%-46.30s yo, s\n");
   // ft_printf("ft>%-46.30s yo\n", s);
	 //    printf("pr>%-46.30s yo\n", s);
	 // printf("\n22 --------------\n");
	 // printf("%%4.3s yo, s\n");
   // ft_printf("ft>%4.3s yo\n", s);
	 //    printf("pr>%4.3s yo\n", s);
	 // printf("\n23 --------------\n");
	 // printf("%%.3s yo, s\n");
   // ft_printf("ft>%.3s yo\n", s);
	 //    printf("pr>%.3s yo\n", s);
	 // printf("\n24 --------------\n");
	 // printf("%%p yo, s\n");
   // ft_printf("ft>%p yo\n", s);
	 //    printf("pr>%p yo\n", s);
	 // printf("\n25 --------------\n");
	 // printf("%%.30p yo, s\n");
   // ft_printf("ft>%.30p yo\n", s);
	 //    printf("pr>%.30p yo\n", s);
	 // printf("\n26 --------------\n");
	 // printf("%%-.30p yo, s\n");
   // ft_printf("ft>%-.30p yo\n", s);
	 //    printf("pr>%-.30p yo\n", s);
	 // printf("\n27 --------------\n");
	 // printf("%%46.30p yo, s\n");
   // ft_printf("ft>%46.30p yo\n", s);
	 //    printf("pr>%46.30p yo\n", s);
	 // printf("\n28 --------------\n");
	 // printf("%%-46.30p yo, s\n");
   // ft_printf("ft>%-46.30p yo\n", s);
	 //    printf("pr>%-46.30p yo\n", s);
	 // printf("\n29 --------------\n");
	 // printf("%%4.3p yo, s\n");
   // ft_printf("ft>%4.3p yo\n", s);
	 //    printf("pr>%4.3p yo\n", s);
	 // printf("\n30 --------------\n");
	 // printf("%%.3p yo, s\n");
   // ft_printf("ft>%.3p yo\n", s);
	 //    printf("pr>%.3p yo\n", s);
	 // printf("\n31 --------------\n");
	 // printf("%%p, 0\n");
   // ft_printf("ft>%p\n", 0);
	 //    printf("pr>%p\n", 0);
	 // printf("\n32 --------------\n");
	 // printf("%%#x, 0\n");
   // ft_printf("ft>%#x\n", 0);
	 //    printf("pr>%#x\n", 0);
	 // printf("\n33 --------------\n");
	 // printf("%%.10p, 0\n");
   // ft_printf("ft>%.10p\n", 0);
	 //    printf("pr>%.10p\n", 0);
	 // printf("\n34 --------------\n");
	 // printf("%%0.10p, 0\n");
   // ft_printf("ft>%0.10p\n", 0);
	 //    printf("pr>%0.10p\n", 0);
	 // printf("\n35 --------------\n");
	 // printf("\n\nTEST : %%p, NULL - 1\n");
   // ft_printf("ft>\n\nTEST : %p\n", NULL - 1);
	 //    printf("pr>\n\nTEST : %p\n", NULL - 1);
	 // printf("\n36 --------------\n");
	 // printf("\n%%.u, %%.0u, 0, 0\n");
   // ft_printf("ft>\n%.u, %.0u\n", 0, 0);
	 //    printf("pr>\n%.u, %.0u\n", 0, 0);
	 // printf("\n37 --------------\n");


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
//
//
// • Vous ne ferez pas la gestion de buffer présente dans la fonction printf de la libc.
// • Vous devez gérer les conversions suivantes : csp
// • Vous devez gérer les conversions suivantes : diouxX avec les flags hh, h, l, ll
// • Vous devez gérer la conversion suivante : f avec les flags l et L
// • Vous devez gérer le %%
// • Vous devez gérer les flags #0-+ et espace
// • Vous devez gérer la taille minimum du champ
// • Vous devez gérer la précision
