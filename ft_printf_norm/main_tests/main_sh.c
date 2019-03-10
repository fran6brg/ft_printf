#include <stdio.h>
#include "../includes/t_options.h"
#include "../includes/t_functions_pointers.h"
#include "../includes/functions.h"
#include "../libft/libft.h"
//#include "includes/t_functions_pointers.h"

int main(int argc, char **argv)
{
  // printf("\n\nTEST[%%5%]\n");
  // ft_printf("YOUR[%5%]");
  //    printf("\nREAL[%5%]");
  //
  // // # 0008
  // printf("\n\nTEST[%%-5%]\n");
  // ft_printf("YOUR[%-5%]");
  //    printf("\nREAL[%-5%]");

  // # 0028 (int)
/*  printf("\n\nTEST[%%jx] 4294967296\n");
  ft_printf("YOUR[%jx]", 4294967296);
     printf("\nREAL[%jx]", 4294967296);

  // # 0029 (int)
  printf("\n\nTEST[%%jx] -4294967296\n");
  ft_printf("YOUR[%jx]", -4294967296);
     printf("\nREAL[%jx]", -4294967296);

  // # 0030 (int)
  printf("\n\nTEST[%%jx] -4294967297\n");
  ft_printf("YOUR[%jx]", -4294967297);
     printf("\nREAL[%jx]", -4294967297);

  // # 0040 (int)
  printf("\n\nTEST[%%#x] 0\n");
  ft_printf("YOUR[%#x]", 0);
     printf("\nREAL[%#x]", 0);

  // # 0044 (int)
  printf("\n\nTEST[%%#08x] 42\n");
  ft_printf("YOUR[%#08x]", 42);
     printf("\nREAL[%#08x]", 42);

  // # 0046 (int)
  printf("\n\nTEST[%%#.x %%#.0x] 0, 0\n");
  ft_printf("YOUR[%#.x %#.0x]", 0, 0);
     printf("\nREAL[%#.x %#.0x]", 0, 0);

  // # 0047 (int)
  printf("\n\nTEST[%%.x %%.0x] 0, 0\n");
  ft_printf("YOUR[%.x %.0x]", 0, 0);
     printf("\nREAL[%.x %.0x]", 0, 0);

  // # 0048 (int)
  printf("\n\nTEST[%%5.x %%5.0x] 0, 0\n");
  ft_printf("YOUR[%5.x %5.0x]", 0, 0);
     printf("\nREAL[%5.x %5.0x]", 0, 0);

  // # 0093 (int)
  printf("\n\nTEST[%%.o %%.0o] 0, 0\n");
  ft_printf("YOUR[%.o %.0o]", 0, 0);
     printf("\nREAL[%.o %.0o]", 0, 0);

  // # 0094 (int)
  printf("\n\nTEST[%%5.o %%5.0o] 0, 0\n");
  ft_printf("YOUR[%5.o %5.0o]", 0, 0);
     printf("\nREAL[%5.o %5.0o]", 0, 0);



  // # 0139 (short)
  printf("\n\nTEST[%%hd] 32768\n");
  ft_printf("YOUR[%hd]", 32768);
     printf("\nREAL[%hd]", 32768);

  // # 0142 (signed char)
  printf("\n\nTEST[%%hhd] 128\n");
  ft_printf("YOUR[%hhd]", 128);
     printf("\nREAL[%hhd]", 128);

  // # 0143 (signed char)
  printf("\n\nTEST[%%hhd] -128\n");
  ft_printf("YOUR[%hhd]", -128);
     printf("\nREAL[%hhd]", -128);

  // # 0151 (intmax_t)
  printf("\n\nTEST[%%jd] 9223372036854775807\n");
  ft_printf("YOUR[%jd]", 9223372036854775807);
     printf("\nREAL[%jd]", 9223372036854775807);


  // # 0152 (intmax_t)
  printf("\n\nTEST[%%jd] -9223372036854775808\n");
  ft_printf("YOUR[%jd]", -9223372036854775808);
     printf("\nREAL[%jd]", -9223372036854775808);

  // # 0153 (ssize_t)
  printf("\n\nTEST[%%zd] 4294967295\n");
  ft_printf("YOUR[%zd]", 4294967295);
     printf("\nREAL[%zd]", 4294967295);

  // # 0154 (ssize_t)
  printf("\n\nTEST[%%zd] 4294967296\n");
  ft_printf("YOUR[%zd]", 4294967296);
     printf("\nREAL[%zd]", 4294967296);

  // # 0167 (int)
  printf("\n\nTEST[%% 10.5d] 4242\n");
  ft_printf("YOUR[% 10.5d]", 4242);
     printf("\nREAL[% 10.5d]", 4242);

  // # 0168 (int)
  printf("\n\nTEST[%%+10.5d] 4242\n");
  ft_printf("YOUR[%+10.5d]", 4242);
     printf("\nREAL[%+10.5d]", 4242);

  // # 0170 (int)
  printf("\n\nTEST[%%03.2d] 0\n");
  ft_printf("YOUR[%03.2d]", 0);
     printf("\nREAL[%03.2d]", 0);

  // # 0171 (int)
  printf("\n\nTEST[%%03.2d] 1\n");
  ft_printf("YOUR[%03.2d]", 1);
     printf("\nREAL[%03.2d]", 1);

  // # 0172 (int)
  printf("\n\nTEST[%%03.2d] -1\n");
  ft_printf("YOUR[%03.2d]", -1);
     printf("\nREAL[%03.2d]", -1);



  // # 0186 (unsigned int)
  printf("\n\nTEST[%% u] 4294967295\n");
  ft_printf("YOUR[% u]", 4294967295);
     printf("\nREAL[% u]", 4294967295);

  // # 0190 (unsigned long)
  printf("\n\nTEST[%%lu] -42\n");
  ft_printf("YOUR[%lu]", -42);
     printf("\nREAL[%lu]", -42);

  // # 0192 (intmax_t)
  printf("\n\nTEST[%%ju] 4999999999\n");
  ft_printf("YOUR[%ju]", 4999999999);
     printf("\nREAL[%ju]", 4999999999);

  // # 0193 (size_t)
  printf("\n\nTEST[%%ju] 4294967296\n");
  ft_printf("YOUR[%ju]", 4294967296);
     printf("\nREAL[%ju]", 4294967296);

  // # 0194 (unsigned long)
  printf("\n\nTEST[%%U] 4294967295\n");
  ft_printf("YOUR[%U]", 4294967295);
     printf("\nREAL[%U]", 4294967295);

  // # 0195 (unsigned long)
  printf("\n\nTEST[%%hU] 4294967296\n");
  ft_printf("YOUR[%hU]", 4294967296);
     printf("\nREAL[%hU]", 4294967296);

  // # 0196 (unsigned long)
  printf("\n\nTEST[%%U] 4294967296\n");
  ft_printf("YOUR[%U]", 4294967296);
     printf("\nREAL[%U]", 4294967296);
*/

  return (1);
}
