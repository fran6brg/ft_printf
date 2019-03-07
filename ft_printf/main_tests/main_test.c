#include <stdio.h>
#include "../includes/t_options.h"
#include "../includes/t_functions_pointers.h"
#include "../includes/functions.h"
#include "../libft/libft.h"
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
	ft_printf("\033[0;33mYOUR>\t[%-10d]\n", 3);
      printf("\033[0;31mREAL>\t[%-10d]\n", 3);
  ft_printf("\033[0;33mYOUR>\t[% d]\n", 3);
     printf("\033[0;31mREAL>\t[% d]\n", 3);
  ft_printf("\033[0;33mYOUR>\t[%+d]\n", 3);
   	 printf("\033[0;31mREAL>\t[%+d]\n", 3);
	 ft_printf("\033[0;33mYOUR>\t[%010d]\n", 1);
	    printf("\033[0;31mREAL>\t[%010d]\n", 1);
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









// test2

// no need




// test3

*/
// 1
//    printf("\033[0;33mTEST>\t[%%#01.X %%01X %%05.5X %%8.2hhX %%0#8.2hhx %%#40.4o]\", -65498, -65498, 65498, -1426800127, 0\n");
// ft_printf("\033[0;33mYOUR>\t[%#01.X]\033[0m\n", -65498);
//    printf("\033[0;31mREAL>\t[%#01.X]\033[0m\n", -65498);
// ft_printf("\033[0;33mYOUR>\t[%#01X]\033[0m\n", -65498);
//    printf("\033[0;31mREAL>\t[%#01X]\033[0m\n", -65498);
// ft_printf("\033[0;33mYOUR>\t[%#05.5X]\033[0m\n", 65498);
//    printf("\033[0;31mREAL>\t[%#05.5X]\033[0m\n", 65498);
//    ft_printf("\033[0;33mYOUR>\t[%0#8.2hhX]\033[0m\n", -1426800127);
//    printf("\033[0;31mREAL>\t[%0#8.2hhX]\033[0m\n", -1426800127);
// ft_printf("\033[0;33mYOUR>\t[%#40.4o]\033[0m\n", 0);
//    printf("\033[0;31mREAL>\t[%#40.4o]\033[0m\n", 0);
// 2
// 3
/*   printf("\033[0;33mTEST>\t[%%24.8hho %%42.10o %%14.36o %%2.44o]\", 2004675854, -140307224, 0, -0\n");
ft_printf("\033[0;33mYOUR>\t[!%#24.8hho!]\033[0m\n", 2004675854);
   printf("\033[0;31mREAL>\t[!%#24.8hho!]\033[0m\n", 2004675854);
ft_printf("\033[0;33mYOUR>\t[%#42.10o]\033[0m\n", -140307224);
   printf("\033[0;31mREAL>\t[%#42.10o]\033[0m\n", -140307224);
ft_printf("\033[0;33mYOUR>\t[>-<%#14.36o>-<]\033[0m\n", -0);
   printf("\033[0;31mREAL>\t[>-<%#14.36o>-<]\033[0m\n", -0);
ft_printf("\033[0;33mYOUR>\t[%2.44o]\033[0m\n", -0);
   printf("\033[0;31mREAL>\t[%2.44o]\033[0m\n", -0);
// 4
// 5
printf("\033[0;33mTEST>\t[%%#0+ 01.X %%0+ 01X %%0+ 5.5X %%0#8.2hhX %%#40.4zo]\", 65498, 0, 0x132, 142680017, 0\n");
ft_printf("\033[0;33mYOUR>\t[%#0+ 01.X]\033[0m\n", 65498);
   printf("\033[0;31mREAL>\t[%#0+ 01.X]\033[0m\n", 65498);
ft_printf("\033[0;33mYOUR>\t[%#0+ 01X]\033[0m\n", 0);
   printf("\033[0;31mREAL>\t[%#0+ 01X]\033[0m\n", 0);
ft_printf("\033[0;33mYOUR>\t[%#0+ 5.5X]\033[0m\n", 0x132);
   printf("\033[0;31mREAL>\t[%#0+ 5.5X]\033[0m\n", 0x132);
ft_printf("\033[0;33mYOUR>\t[!%0#8.2hhX!]\033[0m\n", 142680017);
   printf("\033[0;31mREAL>\t[!%0#8.2hhX!]\033[0m\n", 142680017);
ft_printf("\033[0;33mYOUR>\t[!%#40.4zo!]\033[0m\n", 0);
   printf("\033[0;31mREAL>\t[!%#40.4zo!]\033[0m\n", 0);
// 6
// 7
	 printf("\033[0;33mTEST>\t[%%#24.8hho %%#42.10o %%#14.36o %%2.44o]\", -4675854, 140307224, 12, -42LL\n");
	 ft_printf("\033[0;33mYOUR>\t[%#24.8hho]\033[0m\n", -4675854);
	    printf("\033[0;31mREAL>\t[%#24.8hho]\033[0m\n", -4675854);
	 ft_printf("\033[0;33mYOUR>\t[%#42.10o]\033[0m\n", 140307224);
	    printf("\033[0;31mREAL>\t[%#42.10o]\033[0m\n", 140307224);
	 ft_printf("\033[0;33mYOUR>\t[%#14.36o]\033[0m\n", 12);
	    printf("\033[0;31mREAL>\t[%#14.36o]\033[0m\n", 12);
	 ft_printf("\033[0;33mYOUR>\t[%2.44o]\033[0m\n", -42LL);
	    printf("\033[0;31mREAL>\t[%2.44o]\033[0m\n", -42LL);
// 8
	 printf("\033[0;33mTEST>\t[%%37.30o %%-#42.16o]\", NULL - 1, -1998712178\n");
	 ft_printf("\033[0;33mYOUR>\t[%-#37.30o]\033[0m\n", NULL - 1);
	    printf("\033[0;31mREAL>\t[%-#37.30o]\033[0m\n", NULL - 1);
	 ft_printf("\033[0;33mYOUR>\t[%-#42.16o]\033[0m\n", -1998712178);
	    printf("\033[0;31mREAL>\t[%-#42.16o]\033[0m\n", -1998712178);

*/



// test4

 char *lala = "hello\n\tworld";
 char *s = "moulitest: \t";

	 // printf("\n1. --------------\n");
	 // printf("%%06.d, 36\n");
   // ft_printf("YOUR[%06.d]\n", 36);
	 //    printf("REAL[%06.d]\n", 36);
	 // // printf("\n2. --------------\n");
	 // printf("%%06.d, 123456789\n");
   // ft_printf("YOUR[%06.d]\n", 123456789);
	 //    printf("REAL[%06.d]\n", 123456789);
	 // // printf("\n3. --------------\n");
	 // printf("%%#20.15X, lala\n");
   // ft_printf("YOUR[%#20.15X]\n", lala);
	 //    printf("REAL[%#20.15X]\n", lala);
	 // // printf("\n4. --------------\n");
	 // printf("%%#20.15o, lala\n");
   // ft_printf("YOUR[%#20.15o]\n", lala);
	 //    printf("REAL[%#20.15o]\n", lala);
	 // printf("\n5. --------------\n");
	 // printf("%%#.15o, lala\n");
   // ft_printf("YOUR[%#.15o]\n", lala);
	 //    printf("REAL[%#.15o]\n", lala);
	 // printf("\n6. --------------\n");
	 // printf("%%#20o, lala\n");
   // ft_printf("YOUR[%#20o]\n", lala);
	 //    printf("REAL[%#20o]\n", lala);
	 // printf("\n7. --------------\n");
	 // printf("%%o, lala\n");
   // ft_printf("YOUR[%o]\n", lala);
	 //    printf("REAL[%o]\n", lala);
	 // printf("\n8. --------------\n");
	 // printf("%%#o, 0\n");
   // ft_printf("YOUR[%#o]\n", 0);
	 //    printf("REAL[%#o]\n", 0);
	 // printf("\n9. --------------\n");
	 // printf("%%#X, 1\n");
   // ft_printf("YOUR[%#X]\n", 1);
	 //    printf("REAL[%#X]\n", 1);
	 // printf("\n10 --------------\n");
	 // printf("%aaa%#.0o, 0\n");
   // ft_printf("YOUR[aaa%#.0o]\n", 0);
	 //    printf("REAL[aaa%#.0o]\n", 0);
	    printf("\n11 --------------\n");
	    printf("TEST[%%#.0u], 0\n");
   ft_printf("YOUR[%#.0u]\n", 0);
	    printf("REAL[%#.0u]\n", 0);
	 	  printf("\nend 11 --------------\n");
		  printf("\n11 --------------\n");

      printf("TEST[%%X], 0\n");
   ft_printf("YOUR[%X]\n", 0);
      printf("REAL[%X]\n", 0);
      printf("\nend 11 --------------\n");

      printf("TEST[%%.x], 0\n");
   ft_printf("YOUR[%.x]\n", 0);
      printf("REAL[%.x]\n", 0);
      printf("\nend 11 --------------\n");
	 // printf("\n12 --------------\n");
	 // printf("%%#.4X, 0\n");
   // ft_printf("YOUR[%#.4X]\n", 0);
	 //    printf("REAL[%#.4X]\n", 0);
	 // printf("\n13 --------------\n");
	 // printf("%%cyo, '/'\n");
   // ft_printf("YOUR[%cyo]\n", '/');
	 //    printf("REAL[%cyo]\n", '/');
	 // printf("\n14 --------------\n");
	 // printf("%%10cyo, '/'\n");
   // ft_printf("YOUR[%10cyo]\n", '/');
	 //    printf("REAL[%10cyo]\n", '/');
	 // printf("\n15 --------------\n");
	 // printf("%%-10cyo, '/'\n");
   // ft_printf("YOUR[%-10cyo]\n", '/');
	 //    printf("REAL[%-10cyo]\n", '/');
	 // printf("\n16 --------------\n");
	 // printf("%%.3cyo, '/'\n");
   // ft_printf("YOUR[%.3cyo]\n", '/');
	 //    printf("REAL[%.3cyo]\n", '/');

	 // printf("\n17 --------------\n");
	 // printf("%%s, s\n");
   // ft_printf("YOUR[%s]\n", s);
	 //    printf("REAL[%s]\n", s);
	 // printf("\n18 --------------\n");
	 // printf("%%.30s, s\n");
   // ft_printf("YOUR[%.30s]\n", s);
	 //    printf("REAL[%.30s]\n", s);
	 // printf("\n19 --------------\n");
	 // printf("%%-.30s, s\n");
   // ft_printf("YOUR[%-.30s]\n", s);
	 //    printf("REAL[%-.30s]\n", s);
	 // printf("\n20 --------------\n");
	 // printf("%%46.30s, s\n");
   // ft_printf("YOUR[%46.30s]\n", s);
	 //    printf("REAL[%46.30s]\n", s);
	 // printf("\n21 --------------\n");
	 // printf("%%-46.30s, s\n");
   // ft_printf("YOUR[%-046.30s]\n", s);
	 //    printf("REAL[%-046.30s]\n", s);
	 // printf("\n22 --------------\n");
	 // printf("%%4.3s yo, s\n");
   // ft_printf("YOUR[%4.3s yo]\n", s);
	 //    printf("REAL[%4.3s yo]\n", s);
	 // printf("\n23 --------------\n");
	 // printf("%%.3s yo, s\n");
   // ft_printf("YOUR[%.3s yo]\n", s);
	 //    printf("REAL[%.3s yo]\n", s);
	 // printf("\n24 --------------\n");
	 // printf("%%p yo, s\n");
   // ft_printf("YOUR[%p yo]\n", s);
	 //    printf("REAL[%p yo]\n", s);

	 // printf("\n25 --------------\n");
	 // printf("%%.30p yo, s\n");
   // ft_printf("YOUR[%.30p yo]\n", s);
	 //    printf("REAL[%.30p yo]\n", s);
	 // printf("\n26 --------------\n");
	 // printf("%%-.30p yo, s\n");
   // ft_printf("YOUR[%-.30p yo]\n", s);
	 //    printf("REAL[%-.30p yo]\n", s);
	 // printf("\n27 --------------\n");
	 // printf("%%46.30p yo, s\n");
   // ft_printf("YOUR[%46.30p yo]\n", s);
	 //    printf("REAL[%46.30p yo]\n", s);
	 // printf("\n28 --------------\n");
	 // printf("%%-46.30p yo, s\n");
   // ft_printf("YOUR[%-46.30p yo]\n", s);
	 //    printf("REAL[%-46.30p yo]\n", s);
	 // printf("\n29 --------------\n");
	 // printf("%%4.3p yo, s\n");
   // ft_printf("YOUR[%4.3p yo]\n", s);
	 //    printf("REAL[%4.3p yo]\n", s);
	 // printf("\n30 --------------\n");
	 // printf("%%.3p yo, s\n");
   // ft_printf("YOUR[%.3p yo]\n", s);
	 //    printf("REAL[%.3p yo]\n", s);

	 // printf("\n31 --------------\n");
	 // printf("%%p, 0\n");
   // ft_printf("YOUR[%p]\n", 0);
	 //    printf("REAL[%p]\n", 0);
	 // printf("\n32 --------------\n");
	 // printf("%%#x, 0\n");
   // ft_printf("YOUR[%#x]\n", 0);
	 //    printf("REAL[%#x]\n", 0);
	 // printf("\n33 --------------\n");
	 // printf("%%.10p, 0\n");
   // ft_printf("YOUR[%.10p]\n", 0);
	 //    printf("REAL[%.10p]\n", 0);
	 // printf("\n34 --------------\n");
	 // printf("%%0.10p, 0\n");
   // ft_printf("YOUR[%0.10p]\n", 0);
	 //    printf("REAL[%0.10p]\n", 0);
	 printf("\n35 --------------\n");
	 printf("TEST : %%p, NULL - 1\n");
   ft_printf("YOUR[TEST : %p]\n", NULL - 1);
	    printf("REAL[TEST : %p]\n", NULL - 1);

	 // printf("\n36 --------------\n");
	 // printf("\n%%.u, %%.0u, 0, 0\n");
   // ft_printf("YOUR[\n%.u, %.0u]\n", 0, 0);
	 //    printf("REAL[\n%.u, %.0u]\n", 0, 0);
	 // printf("\n37 --------------n");







/*	printf("\033[0;33mTEST>\t[%%#20.2o %%#31o %%#28.28o %%#31o]\", -144491672, 0, 2147492, 40\n");
	ret = ft_printf("\033[0;33mYOUR>\t[%#20.2o]\033[0m\n", -144491672);
		 ret2 = printf("\033[0;31mREAL>\t[%#20.2o]\033[0m\n", -144491672);
	ret = ft_printf("\033[0;33mYOUR>\t[%#31o]\033[0m\n", 0);
		 ret2 = printf("\033[0;31mREAL>\t[%#31o]\033[0m\n", 0);
	ret = ft_printf("\033[0;33mYOUR>\t[%#28.28o]\033[0m\n", 2147492);
		 ret2 = printf("\033[0;31mREAL>\t[%#28.28o]\033[0m\n", 2147492);
	ret = ft_printf("\033[0;33mYOUR>\t[%#31o]\033[0m\n", 40);
		 ret2 = printf("\033[0;31mREAL>\t[%#31o]\033[0m\n", 40);*/
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
