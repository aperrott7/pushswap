#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "lib.h"

void	sort_tre(t_stack *stack_a)
{
    if ((stack_a->array[0] > stack_a->array[1] && stack_a->array[0] < stack_a->array[2] && stack_a->array[1] < stack_a->array[2])
		|| (stack_a->array[0] > stack_a->array[1] && stack_a->array[0] > stack_a->array[2] && stack_a->array[1] > stack_a->array[2])
		|| (stack_a->array[0] < stack_a->array[1] && stack_a->array[1] > stack_a->array[2] && stack_a->array[0] < stack_a->array[2])
		|| (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] == stack_a->array[2]))
        {
            swap_a(*stack_a);
            //revrotate_a(stack_a);
        }
    if (stack_a->array[2] < stack_a->array[0] && stack_a->array[0] < stack_a->array[1])
        revrotate_a(stack_a);
	if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] < stack_a->array[2])
		rotate_a(*stack_a);
    // else
    //     printf("\n NO IN REALTA' NON HA ESEGUITO NULLA\n");
    printf("\n DENTRO SORT TRE ESEGUITO \n stack_a->array[0] = %i, stack_a->array[1] = %i, stack_a->array[2]= %i\n",stack_a->array[0], stack_a->array[1], stack_a->array[2]);
}