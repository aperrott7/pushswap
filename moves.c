#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "lib.h"

void	swap_a(t_stack stack)
{
	int temp;
	int i;
	
	i = 0;
	temp = stack.array[i];
	stack.array[i] = stack.array[i + 1];
	stack.array [i + 1] = temp;
}

void	swap_b(t_stack stack_b)
{
	swap_a(stack_b);
}

void	swap_s(t_stack stack, t_stack stack2)
{
	swap_a(stack);
	swap_b(stack2);
}

void	push_a(int *a)
{
    // int temp;

	// while(*a)
	// {
	// 	*a++ = *a;
	// }
}


/*TEST PYTHON TUTOR */
// void    push_a(int *a, int size)
// {
//      int aux[size];
//      int i;
     
//      i = 0;
//      while(i < size)
//         aux[i] = a[i++];
//      a = malloc(sizeof(int)*6);
//     i = 1;
//     while(i < size)
//       a[i] = aux[i++ - 1];
//   }

// void    swap_a(int *a)
// {
//     int temp;

//     temp = *a;
//     *a++ = *a;
//     *a= temp;
// }

// int main() 
// {
//   int a[] ={1, 3, 5, 7, 9};
//   int size = 5;
  
//   push_a(a, size);
//   return 0;
// }