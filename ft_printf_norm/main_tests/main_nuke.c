#include <stdio.h>
#include "includes/t_options.h"
#include "includes/t_functions_pointers.h"
#include "includes/functions.h"
#include "libft/libft.h"
//#include "includes/t_functions_pointers.h"

int main(int argc, char **argv)
{
  // i
  char *t = 5500;

     printf("\nTEST[^.^/%%56.51zi^.^/], 0\n\n");
  ft_printf("YOUR[^.^/%56.51zi^.^/]\n", 0);
     printf("REAL[^.^/%56.51zi^.^/]\n", 0);

     printf("\nTEST[^.^/%%48.52zi^.^/], 0\n\n");
  ft_printf("YOUR[^.^/%48.52zi^.^/]\n", 0);
     printf("REAL[^.^/%48.52zi^.^/]\n", 0);


  // s
     printf("\nTEST[!%%46.6ls!], une chaine de putes\n\n");
     printf("REAL[%48.6ls]\n", L"une chaine de putes");
     ft_printf("YOUR[%48.6ls]\n", L"une chaine de putes");

  return (1);
}
