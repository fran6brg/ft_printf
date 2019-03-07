#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/functions.h"

int	main(int ac, char **av)
{
	int me = 0;
	int rl = 0;
	int no = 1;
	int pas = 0;
		printf("\033[0;32mThis is a tester for the ft_printf project, made by maabou-h\nusing various tests from other people and/or automated testers.\nPassing all tests does not mean your ft_printf project is perfect but\nmeans that you handled most of the special cases and some random tests,\nthis tester also contains lots of undefined behaviour tests that you do not necessarily\nneed to do to pass your project. Keep in mind that you should\nmake your own test suite and that you are free to use any tests from this tester.\nGood luck for the moulinette. \n\n ► You may press any key to begin testing.\033[0m\n\n"); getchar();
			printf("\033[0;32m----\ttest phase 1\033[0m\n\n");

			printf("\033[0;33mTEST>\t[%%-10d %% d %%+d %%010d %%hhd %%llda]\", 3, 3, 3, 1, 0, 18446744065119617025LL\n");
			me = ft_printf("\033[0;33mYOUR>\t[%-10d //% d //%+d //%010d //%hhd //%llda]\n", 3, 3, 3, 1, 0, 18446744065119617025LL);
			   rl = printf("\033[0;31mREAL>\t[%-10d //% d //%+d //%010d //%hhd //%llda]\n", 3, 3, 3, 1, 0, 18446744065119617025LL);
				 //rl = printf("\033[0;31mREAL>\t[\n//%-10d \n//% d \n//%+d \n//%010d \n//%hhd \n//%llda]\n", 3, 3, 3, 1, 0, 18446744065119617025LL);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%10.8lld=%%#25.22llda=%%#-+ 08.5llda]\", 100LL, -1LL, 100LL\n");
			me = ft_printf("\033[0;33mYOUR>\t[%10.8lld=%#25.22llda=%#-+ 08.5llda]\n", 100LL, -1LL, 100LL);
				 rl = printf("\033[0;31mREAL>\t[%10.8lld=%#25.22llda=%#-+ 08.5llda]\n", 100LL, -1LL, 100LL);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%% .40d=%% 10.40d=%% 10.40d=%%10.0d=%%+010.d=%%10.0d=%%+ 010.d]\", 1, 10, -10, -10, -10, 10, 10\n");
			me = ft_printf("\033[0;33mYOUR>\t[% .40d=% 10.40d=% 10.40d=%10.0d=%+010.d=%10.0d=%+ 010.d]\n", 1, 10, -10, -10, -10, 10, 10);
			rl = printf("\033[0;31mREAL>\t[% .40d=% 10.40d=% 10.40d=%10.0d=%+010.d=%10.0d=%+ 010.d]\n", 1, 10, -10, -10, -10, 10, 10);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%% 10.0d=%%+ 010.d=%% 10.0d]\", -10, -10, 10\n");
			me = ft_printf("\033[0;33mYOUR>\t[% 10.0d=%+ 010.d=% 10.0d]\n", -10, -10, 10);
				 rl = printf("\033[0;31mREAL>\t[% 10.0d=%+ 010.d=% 10.0d]\n", -10, -10, 10);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%% 10.40d=%% 10.40d=%%+010.d=%%10.0d=%%+010.d=%%10.0d=%%+ 010.d=%% 10.0d]\", 0, -0, 0, -0, 0, 0, 0, 0\n");
			me = ft_printf("\033[0;33mYOUR>\t[% 10.40d=% 10.40d=%+010.d=%10.0d=%+010.d=%10.0d=%+ 010.d=% 10.0d]\n", 0, -0, 0, -0, 0, 0, 0, 0);
				 rl = printf("\033[0;31mREAL>\t[% 10.40d=% 10.40d=%+010.d=%10.0d=%+010.d=%10.0d=%+ 010.d=% 10.0d]\n", 0, -0, 0, -0, 0, 0, 0, 0);
		//	rl = printf("\033[0;31mREAL>\t[\n% 10.40d=\n% 10.40d=\n%+010.d=\n%10.0d=\n%+010.d=\n%10.0d=\n%+ 010.d=\n% 10.0d]\n", 0, -0, 0, -0, 0, 0, 0, 0);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[=%%10.0d=%%+010.d=%%10.0d=%%+ 010.d=%% 10.0d-%%d-%%.0d-%%.8d-%%8.0d-%%8.8d-]\", -0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n");
			me = ft_printf("\033[0;33mYOUR>\t[ %10.0d1//%+010.d2//%10.0d3//%+ 010.d4//% 10.0d5//%d6//%.0d7//%.8d8//%8.0d9//%8.8d10//]\n", -0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				 rl = printf("\033[0;31mREAL>\t[ %10.0d1//%+010.d2//%10.0d3//%+ 010.d4//% 10.0d5//%d6//%.0d7//%.8d8//%8.0d9//%8.8d10//]\n", -0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%+ 010.d=%%5.3d=%%-+5.3d=%%d %%d %%d %%d %%d %%d %%d %%d %%d]\", -0, 424LL, 424LL, 0, 1, 9, 10, 11, 9999, 10000, 100001, -258733\n");
			me = ft_printf("\033[0;33mYOUR>\t[%+ 010.d=%5.3d=%-+5.3d=%d %d %d %d %d %d %d %d %d]\n", -0, 424LL, 424LL, 0, 1, 9, 10, 11, 9999, 10000, 100001, -258733);
				 rl = printf("\033[0;31mREAL>\t[%+ 010.d=%5.3d=%-+5.3d=%d %d %d %d %d %d %d %d %d]\n", -0, 424LL, 424LL, 0, 1, 9, 10, 11, 9999, 10000, 100001, -258733);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%% 10.0d=%%4.5d=%%+#4.5d=%% 0-54.2d=%% 0-54.2d=%%- 0.2d=%%+-d=%% +-d-%%.4d-%%.4d-%%.d-%%.0d-%%d %%hd %%d %%ld]\", 0, 42, -42U, 2147483777LL, NULL - 1, NULL, 2147483647, -2147483648, 7, 12345, 1, 9, 126, 12356, 1456, -3456\n");
			me = ft_printf("\033[0;33mYOUR>\t[1//% 10.0d2//%4.5d3//%+#4.5d4//% 0-54.2d5//% 0-54.2d6//%- 0.2d7//%+-d8//% +-d9//%.4d10//%.4d11//%.d12//%.0d13//%d14//%hd15//%d16//%ld]\n", 0, 42, -42U, 2147483777LL, NULL - 1, NULL, 2147483647, -2147483648, 7, 12345, 1, 9, 126, 12356, 1456, -3456);
			rl = printf("\033[0;31mREAL>\t[1//% 10.0d2//%4.5d3//%+#4.5d4//% 0-54.2d5//% 0-54.2d6//%- 0.2d7//%+-d8//% +-d9//%.4d10//%.4d11//%.d12//%.0d13//%d14//%hd15//%d16//%ld]\n", 0, 42, -42U, 2147483777LL, NULL - 1, NULL, 2147483647, -2147483648, 7, 12345, 1, 9, 126, 12356, 1456, -3456);
			//rl = printf("\033[0;31mREAL>\t[\n1//% 10.0d\n2//%4.5d\n3//%+#4.5d\n4//% 0-54.2d\n5//% 0-54.2d\n6//%- 0.2d\n7//%+-d\n8//% +-d\n9//%.4d\n10//%.4d\n11//%.d\n12//%.0d\n13//%d\n14//%hd\n15//%d\n16//%ld]\n", 0, 42, -42U, 2147483777LL, NULL - 1, NULL, 2147483647, -2147483648, 7, 12345, 1, 9, 126, 12356, 1456, -3456);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;
			printf("\033[0;33mTEST>\t[%%d %%d %%+d %%+d %% d %% d %%+ d %%+ d %% +d %% +d]\", 7, -7, 7, -7, 7, -7, 7, -7, 7, -7\n");
			me = ft_printf("\033[0;33mYOUR>\t[%d %d %+d %+d % d % d %+ d %+ d % +d % +d]\n", 7, -7, 7, -7, 7, -7, 7, -7, 7, -7);
				 rl = printf("\033[0;31mREAL>\t[%d %d %+d %+d % d % d %+ d %+ d % +d % +d]\n", 7, -7, 7, -7, 7, -7, 7, -7, 7, -7);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t['%%-d'%%-+d'%%+-d'%%+d'%% d'%% .0d'%% +d'%%03d'%%-03d'%%-+0003d'%%0+ 3d']\", 5, 5, 5, 5, -5, -5, 0, 5, 5, -5, -5, -5U\n");
			me = ft_printf("\033[0;33mYOUR>\t['%-d'%-+d'%+-d'%+d'% d'% .0d'% +d'%03d'%-03d'%-+0003d'%0+ 3d']\n", 5, 5, 5, 5, -5, -5, 0, 5, 5, -5, -5, -5U);
				 rl = printf("\033[0;31mREAL>\t['%-d'%-+d'%+-d'%+d'% d'% .0d'% +d'%03d'%-03d'%-+0003d'%0+ 3d']\n", 5, 5, 5, 5, -5, -5, 0, 5, 5, -5, -5, -5U);
			printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

(pas == 10) ? printf("\033[0;33m----\tYou passed all 10 tests\033[0m\n\n", pas) : printf("\033[0;32m----\tYou passed %d out of 10 tests\033[0m\n\n", pas);
printf("\033[1;31mQUICK TIP: HOLD COMMAND KEY AND ARROW KEY TO NAVIGATE YOUR TERMINAL\033[0m\n");  printf("PRESS ANY KEY TO BEGIN NEXT PHASE\n"); getchar();

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

printf("\033[0;32m----\ttest phase 2\033[0m\n\n");

pas = 0;
			printf("\033[0;33mTEST>\t[%%s %%4s %%4s %%04s %%04s %%.4s %%.4s %%.s]\", NULL, A, ABCDEF, A, ABCDEF, 2, ABCDEF, [][\n");
			me = ft_printf("\033[0;33mYOUR>\t[%s-%4s-%4s-%04s-%04s-%.4s-%.4s-%.s-]\n", NULL, "A", "ABCDEF", "A", "ABCDEF", "2", "ABCDEF", "[][");
			rl = printf("\033[0;31mREAL>\t[%s-%4s-%4s-%04s-%04s-%.4s-%.4s-%.s-]\n", NULL, "A", "ABCDEF", "A", "ABCDEF", "2", "ABCDEF", "[][");
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%6.4s %%4.6s %%#s %%0s %%+s %%0-s %%5.5s %%5s %%.5s]\", ABCDE, ABCDE, ABC, ABC, ^%%n, A{BC, A@#5448{BC, A@#5448{BC, A@#5448{BC\n");
			me = ft_printf("\033[0;33mYOUR>\t[-%6.4s-%4.6s-%#s %0s-%+s %0-s-%5.5sa-%5sa-%.5sa]\n", "ABCDE", "ABCDE", "ABC", "ABC", "^%n", "A{BC", "A@#5448{BC", "A@#5448{BC", "A@#5448{BC");
			rl = printf("\033[0;31mREAL>\t[-%6.4s-%4.6s-%#s %0s-%+s %0-s-%5.5sa-%5sa-%.5sa]\n", "ABCDE", "ABCDE", "ABC", "ABC", "^%n", "A{BC", "A@#5448{BC", "A@#5448{BC", "A@#5448{BC");
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%.6s %%-5s %%5s %%6.2s]\", abc, abc, abc, abc\n");
			me = ft_printf("\033[0;33mYOUR>\t[%.6sa][%-5sa][%5sa][%6.2sa]\n", "abc", "abc", "abc", "abc");
			rl = printf("\033[0;31mREAL>\t[%.6sa][%-5sa][%5sa][%6.2sa]\n", "abc", "abc", "abc", "abc");
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%2c %%6c %%2c %%6c %%6c %%2c %%2c %%6c]\", a, a, a, 0, 0, 0, 400, -42\n");
			me = ft_printf("\033[0;33mYOUR>\t[%2ca][%6ca][%2ca][%6ca][%6ca][%2ca][%2ca][%6ca]\n", 'a', 'a', 'a', 0, 0, 0, 40, 42);
			rl = printf("\033[0;31mREAL>\t[%2ca][%6ca][%2ca][%6ca][%6ca][%2ca][%2ca][%6ca]\n", 'a', 'a', 'a', 0, 0, 0, 40, 42);
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%2c %%6c %%6c %%2c]\", NULL, a, a, a \n");
			me = ft_printf("\033[0;33mYOUR>\t[%2ca][%6ca][%6ca][%2ca]\n", NULL, 'a', 'a', 'a');
			rl = printf("\033[0;31mREAL>\t[%2ca][%6ca][%6ca][%2ca]\n", NULL, 'a', 'a', 'a');
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%06.2c %%06c %%0.2c %%06.2c %%06c %%0.2c %%-6.2c %%-6c %%-6c %%-.2c]\", 0, 0, 400U, -42, NULL, b, b, b, Y\n");
			me = ft_printf("\033[0;33mYOUR>\t[%2ca][%6ca][%2ca][%2ca][%6ca][%2ca][%-2ca][%-6ca][%-12ca]\n", 0, 0, 40, 42, NULL, 'b', 'b', 'Y');
			rl = printf("\033[0;31mREAL>\t[%2ca][%6ca][%2ca][%2ca][%6ca][%2ca][%-2ca][%-6ca][%-12ca]\n", 0, 0, 40, 42, NULL, 'b', 'b', 'Y');
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%-6.2c %%-6c %%-.2c %%-6.2c %%-6c %%-.2c]\", 0, 0, -1, 400, -42, NULL - 1\n");
			me = ft_printf("\033[0;33mYOUR>\t[%-62ca][%-6ca][%-2ca][%-2ca][%-6ca][%-2ca]\n", 0, 0, 'c', 40, 42, NULL);
			rl = printf("\033[0;31mREAL>\t[%-62ca][%-6ca][%-2ca][%-2ca][%-6ca][%-2ca]\n", 0, 0, 'c', 40, 42, NULL);
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%s %%4s %%4s %%04s %%04s %%.4s %%.4s %%.s]\", NULL, A, ABCDEF, A, ABCDEF, 2, ABCDEF, [][\n");
			me = ft_printf("\033[0;33mYOUR>\t[%6.2%=%6%=%.2%=%6.2%=%6%=%.2%=%6.2%=%6%=%.2%=%.2%=%06.2%=%06%=%0.2%=%06.2%=%06%=%0.2%=%-6.2%=%-6%=%-.2%=%-6.2%=%-6%=%-.2%=%-6.2%=%-6%=%-.2%]\n");
			rl = printf("\033[0;33mREAL>\t[%6.2%=%6%=%.2%=%6.2%=%6%=%.2%=%6.2%=%6%=%.2%=%.2%=%06.2%=%06%=%0.2%=%06.2%=%06%=%0.2%=%-6.2%=%-6%=%-.2%=%-6.2%=%-6%=%-.2%=%-6.2%=%-6%=%-.2%]\n");
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%p %%p %%p %%p %%p %%p %%6p %%6.p %%p%%-p %%5p]\", NULL, 0, 0x123, main, NULL, NULL, 0, 0x123L, main\n");
			me = ft_printf("\033[0;33mYOUR>\t[%p][%p][%p][%p][%6p][%6p][%p][%-p][%5p]\n", NULL, 0, 0x123, main, NULL, NULL, 0, 0x123L, main);
			rl = printf("\033[0;31mREAL>\t[%p][%p][%p][%p][%6p][%6p][%p][%-p][%5p]\n", NULL, 0, 0x123, main, NULL, NULL, 0, 0x123L, main);
		//	rl = printf("\033[0;31mREAL>\t\n%p\n%p\n%p\n%p\n%6p\n%6p\n%p\n%-p\n%5p\n", NULL, 0, 0x123, main, NULL, NULL, 0, 0x123L, main);
printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%+040.2i %%040.2i %%+012.2ji %%0+32.2i]\", -2097948570, -2097948570, 0, -1046073861\n");
			me = ft_printf("\033[0;33mYOUR>\t[%+040.2i][%040.2i][!%+012.2ji!][%0+32.2i]\n", -2097948570, -2097948570, 0, -1046073861);
			rl = printf("\033[0;31mREAL>\t[%+040.2i][%040.2i][!%+012.2ji!][%0+32.2i]\n", -2097948570, -2097948570, 0, -1046073861);
		printf ("\033[0m%d/10: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

(pas == 10) ? printf("\033[0;33m----\tYou passed all 10 tests\033[0m\n\n", pas) : printf("\033[0;32m----\tYou passed %d out of 10 tests\033[0m\n\n", pas);
printf("\033[1;31mQUICK TIP: HOLD COMMAND KEY AND ARROW KEY TO NAVIGATE YOUR TERMINAL\033[0m\n");  printf("PRESS ANY KEY TO BEGIN NEXT PHASE\n"); getchar();

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

printf("\033[0;32m----\ttest phase 3\033[0m\n\n");
pas = 0;

			printf("\033[0;33mTEST>\t[%%#01.X %%01X %%05.5X %%8.2hhX %%0#8.2hhx %%#40.4o]\", -65498, -65498, 65498, -1426800127, 0\n");
			me = ft_printf("\033[0;33mYOUR>\t[%#01.X][%#01X][%#05.5X][!%0#8.2hhX!][!%#40.4o!]\033[0m\n", -65498, -65498, 65498, -1426800127, 0);
			rl = printf("\033[0;31mREAL>\t[%#01.X][%#01X][%#05.5X][!%0#8.2hhX!][!%#40.4o!]\033[0m\n", -65498, -65498, 65498, -1426800127, 0);
			printf ("%d/8: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%#20.2o %%31o %%28.28o %%31o]\", 144491672, 0, 2147452292, 0\n");
			me = ft_printf("\033[0;33mYOUR>\t[%#20.2o][%#31o][%#28.28o][%#31o]\033[0m\n", 144491672, 0, 2147452292, 0);
			rl = printf("\033[0;31mREAL>\t[%#20.2o][%#31o][%#28.28o][%#31o]\033[0m\n", 144491672, 0, 2147452292, 0);
			printf ("%d/8: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%24.8hho %%42.10o %%14.36o %%2.44o]\", 2004675854, -140307224, 0, -0\n");
			me = ft_printf("\033[0;33mYOUR>\t[!%#24.8hho!][%#42.10o][>-<%#14.36o>-<][%2.44o]\033[0m\n", 2004675854, -140307224, 0, -0);
			rl = printf("\033[0;31mREAL>\t[!%#24.8hho!][%#42.10o][>-<%#14.36o>-<][%2.44o]\033[0m\n", 2004675854, -140307224, 0, -0);
			printf ("%d/8: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%-#37.30o %%-#42.16o]\", 0, -1998712178\n");
			me = ft_printf("\033[0;33mYOUR>\t[%-#37.30o][%-#42.16o]\033[0m\n", 0, -1998712178);
			rl = printf("\033[0;31mREAL>\t[%-#37.30o][%-#42.16o]\033[0m\n", 0, -1998712178);
			printf ("%d/8: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%#0+ 01.X %%0+ 01X %%0+ 5.5X %%0#8.2hhX %%#40.4zo]\", 65498, 0, 0x132, 142680017, 0\n");
			me = ft_printf("\033[0;33mYOUR>\t[%#0+ 01.X][%#0+ 01X][%#0+ 5.5X][!%0#8.2hhX!][!%#40.4zo!]\033[0m\n", 65498, 0, 0x132, 142680017, 0);
			rl = printf("\033[0;31mREAL>\t[%#0+ 01.X][%#0+ 01X][%#0+ 5.5X][!%0#8.2hhX!][!%#40.4zo!]\033[0m\n", 65498, 0, 0x132, 142680017, 0);
			printf ("%d/8: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%#20.2o %%#31o %%28.28o %%31o]\", -144491672, 0, 2147492, 40\n");
			me = ft_printf("\033[0;33mYOUR>\t[%#20.2o][%#31o][%#28.28o][%#31o]\033[0m\n", -144491672, 0, 2147492, 40);
			rl = printf("\033[0;31mREAL>\t[%#20.2o][%#31o][%#28.28o][%#31o]\033[0m\n", -144491672, 0, 2147492, 40);
			printf ("%d/8: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%#24.8hho %%#42.10o %%#14.36o %%2.44o]\", -4675854, 140307224, 12, -42LL\n");
			me = ft_printf("\033[0;33mYOUR>\t[%#24.8hho][%#42.10o][%#14.36o][%2.44o]\033[0m\n", -4675854, 140307224, 12, -42LL);
			rl = printf("\033[0;31mREAL>\t[%#24.8hho][%#42.10o][%#14.36o][%2.44o]\033[0m\n", -4675854, 140307224, 12, -42LL);
			printf ("%d/8: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;

			printf("\033[0;33mTEST>\t[%%37.30o %%-#42.16o]\", NULL - 1, -1998712178\n");
			me = ft_printf("\033[0;33mYOUR>\t[%-#37.30o][%-#42.16o]\033[0m\n", NULL - 1, -1998712178);
			rl = printf("\033[0;31mREAL>\t[%-#37.30o][%-#42.16o]\033[0m\n", NULL - 1, -1998712178);
			printf ("%d/8: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n"); (me == rl) ? pas++ : 0;


(pas == 8) ? printf("\033[0;33m----\tYou passed all 8 tests\033[0m\n\n", pas) : printf("\033[0;32m----\tYou passed %d out of 8 tests\033[0m\n\n", pas);
printf("\033[1;31mQUICK TIP: HOLD COMMAND KEY AND ARROW KEY TO NAVIGATE YOUR TERMINAL\033[0m\n"); printf("PRESS ANY KEY TO BEGIN NEXT PHASE\n"); getchar();

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	printf("\033[0;32m----\ttest phase 4 - made by ede-ram\033[0m\n\n");
	char *lala = "hello\n\tworld";
	char *s = "moulitest: \t";
	no = 1;

    printf("\n1. --------------\n");
    printf("%%06.d, 36\n");
 me = ft_printf("ft>%06.d\n", 36);
    rl = printf("pr>%06.d\n", 36);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n2. --------------\n");
    printf("%%06.d, 123456789\n");
 me = ft_printf("ft>%06.d\n", 123456789);
    rl = printf("pr>%06.d\n", 123456789);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n3. --------------\n");
    printf("%%#20.15X, lala\n");
 me = ft_printf("ft>%#20.15X\n", lala);
    rl = printf("pr>%#20.15X\n", lala);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n4. --------------\n");
    printf("%%#20.15o, lala\n");
 me = ft_printf("ft>%#20.15o\n", lala);
    rl = printf("pr>%#20.15o\n", lala);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n5. --------------\n");
    printf("%%#.15o, lala\n");
 me = ft_printf("ft>%#.15o\n", lala);
    rl = printf("pr>%#.15o\n", lala);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n6. --------------\n");
    printf("%%#20o, lala\n");
 me = ft_printf("ft>%#20o\n", lala);
    rl = printf("pr>%#20o\n", lala);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n7. --------------\n");
    printf("%%o, lala\n");
 me = ft_printf("ft>%o\n", lala);
    rl = printf("pr>%o\n", lala);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n8. --------------\n");
    printf("%%#o, 0\n");
 me = ft_printf("ft>%#o\n", 0);
    rl = printf("pr>%#o\n", 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n9. --------------\n");
    printf("%%#X, 1\n");
 me = ft_printf("ft>%#X\n", 1);
    rl = printf("pr>%#X\n", 1);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n10 --------------\n");
    printf("%aaa%#.0o, 0\n");
 me = ft_printf("ft>aaa%#.0o\n", 0);
    rl = printf("pr>aaa%#.0o\n", 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n11 --------------\n");
    printf("%%#.0X, 0\n");
 me = ft_printf("ft>%#.0X\n", 0);
    rl = printf("pr>%#.0X\n", 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n12 --------------\n");
    printf("%%#.4X, 0\n");
 me = ft_printf("ft>%#.4X\n", 0);
    rl = printf("pr>%#.4X\n", 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n13 --------------\n");
    printf("%%cyo, '/'\n");
 me = ft_printf("ft>%cyo\n", '/');
    rl = printf("pr>%cyo\n", '/');
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n14 --------------\n");
    printf("%%10cyo, '/'\n");
 me = ft_printf("ft>%10cyo\n", '/');
    rl = printf("pr>%10cyo\n", '/');
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n15 --------------\n");
    printf("%%-10cyo, '/'\n");
 me = ft_printf("ft>%-10cyo\n", '/');
    rl = printf("pr>%-10cyo\n", '/');
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n16 --------------\n");
    printf("%%.3cyo, '/'\n");
 me = ft_printf("ft>%.3cyo\n", '/');
    rl = printf("pr>%.3cyo\n", '/');
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n17 --------------\n");
    printf("%%s yo, s\n");
 me = ft_printf("ft>%s yo\n", s);
    rl = printf("pr>%s yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n18 --------------\n");
    printf("%%.30s yo, s\n");
 me = ft_printf("ft>%.30s yo\n", s);
    rl = printf("pr>%.30s yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n19 --------------\n");
    printf("%%-.30s yo, s\n");
 me = ft_printf("ft>%-.30s yo\n", s);
    rl = printf("pr>%-.30s yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n20 --------------\n");
    printf("%%46.30s yo, s\n");
 me = ft_printf("ft>%46.30s yo\n", s);
    rl = printf("pr>%46.30s yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n21 --------------\n");
    printf("%%-46.30s yo, s\n");
 me = ft_printf("ft>%-46.30s yo\n", s);
    rl = printf("pr>%-46.30s yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n22 --------------\n");
    printf("%%4.3s yo, s\n");
 me = ft_printf("ft>%4.3s yo\n", s);
    rl = printf("pr>%4.3s yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n23 --------------\n");
    printf("%%.3s yo, s\n");
 me = ft_printf("ft>%.3s yo\n", s);
    rl = printf("pr>%.3s yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n24 --------------\n");
    printf("%%p yo, s\n");
 me = ft_printf("ft>%p yo\n", s);
    rl = printf("pr>%p yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n25 --------------\n");
    printf("%%.30p yo, s\n");
 me = ft_printf("ft>%.30p yo\n", s);
    rl = printf("pr>%.30p yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n26 --------------\n");
    printf("%%-.30p yo, s\n");
 me = ft_printf("ft>%-.30p yo\n", s);
    rl = printf("pr>%-.30p yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n27 --------------\n");
    printf("%%46.30p yo, s\n");
 me = ft_printf("ft>%46.30p yo\n", s);
    rl = printf("pr>%46.30p yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n28 --------------\n");
    printf("%%-46.30p yo, s\n");
 me = ft_printf("ft>%-46.30p yo\n", s);
    rl = printf("pr>%-46.30p yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n29 --------------\n");
    printf("%%4.3p yo, s\n");
 me = ft_printf("ft>%4.3p yo\n", s);
    rl = printf("pr>%4.3p yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n30 --------------\n");
    printf("%%.3p yo, s\n");
 me = ft_printf("ft>%.3p yo\n", s);
    rl = printf("pr>%.3p yo\n", s);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n31 --------------\n");
    printf("%%p, 0\n");
 me = ft_printf("ft>%p\n", 0);
    rl = printf("pr>%p\n", 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n32 --------------\n");
    printf("%%#x, 0\n");
 me = ft_printf("ft>%#x\n", 0);
    rl = printf("pr>%#x\n", 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n33 --------------\n");
    printf("%%.10p, 0\n");
 me = ft_printf("ft>%.10p\n", 0);
    rl = printf("pr>%.10p\n", 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n34 --------------\n");
    printf("%%0.10p, 0\n");
 me = ft_printf("ft>%0.10p\n", 0);
    rl = printf("pr>%0.10p\n", 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n35 --------------\n");
    printf("\n\nTEST : %%p, NULL - 1\n");
 me = ft_printf("ft>\n\nTEST : %p\n", NULL - 1);
    rl = printf("pr>\n\nTEST : %p\n", NULL - 1);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n36 --------------\n");
    printf("\n%%.u, %%.0u, 0, 0\n");
 me = ft_printf("ft>\n%.u, %.0u\n", 0, 0);
    rl = printf("pr>\n%.u, %.0u\n", 0, 0);
		printf ("\033[0m%d/36: [%d] [%d]\n", no++, me, rl); (me == rl) ? printf("\033[1;32m✔︎ GOOD RETURN\033[0m\n") : printf("\033[1;31m✖︎ BAD RETURN\033[0m\n");
		printf("\n37 --------------\n");
	return (0);
}
