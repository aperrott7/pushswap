#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "lib.h"

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
		sort_tre(stack_a);
	// else if (ft_lstlen(*stack_a) <= 5)
	// 	sortFive(stack_a, stack_b);
	// else if (ft_lstlen(*stack_a) <= 100)
	// 	sortOneHundred(stack_a, stack_b);
	// else
	// 	sortFiveHundred(stack_a, stack_b);
}