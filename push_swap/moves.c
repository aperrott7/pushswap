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

void	swap_b(t_stack stack)
{
	swap_a(stack);
}

void	swap_s(t_stack stack, t_stack stack2)
{
	swap_a(stack);
	swap_b(stack2);
}
 

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->size > 0)
	{
		i = stack_b->size;
		while (i--)
			stack_b->array[i + 1] = stack_b->array[i];
		stack_b->array[0] = stack_a->array[0];
		stack_b->size += 1;
		i = 1;
		while (i < stack_a->size)
		{
			//printf("\nstack_a->array[%i - 1] (= %i) = stack_a->array[%i] (= %i) \n", i, stack_a->array[i - 1], i, stack_a->array[i]);
			stack_a->array[i - 1] = stack_a->array[i];
			i++;
		}
		stack_a->size -= 1;
		// if (bool == 1)
		// 	write(1, "pb\n", ft_strlen("pb\n"));
	}
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	push_b(stack_b, stack_a);
}

void	rotate_a(t_stack stack_a)
{
	int i;
	int *temp;

	temp = malloc(stack_a.size);
	i = stack_a.size;
	while(i--)
		temp[i] = stack_a.array[i];

	while(i < stack_a.size - 1)
		{
			stack_a.array[i] = temp[i + 1];
			i++;
		}
	//printf("stack_a.size = %i, i = %i, stack_a.array[stack_a.size] = %i , temp[0] = %i\n", stack_a.size, i, stack_a.array[stack_a.size], temp[0]);
	stack_a.array[i] = temp[0];
}

void	rotate_b(t_stack stack_b)
{
	rotate_a(stack_b);
}

void	rotate_s(t_stack stack_a, t_stack stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	revrotate_a(t_stack *stack_a)
{
	int	i;
	int	tmp;

	if (stack_a->size > 1)
	{
		tmp = stack_a->array[stack_a->size - 1];
		i = stack_a->size - 1;
		while (i--)
			stack_a->array[i + 1] = stack_a->array[i];
		stack_a->array[0] = tmp;
		// if (bool == 1)
		// 	write(1, "rra\n", ft_strlen("rra\n"));
	}
}

void	revrotate_b(t_stack *stack_b)
{
	int	i;
	int	tmp;

	if (stack_b->size > 1)
	{
		tmp = stack_b->array[stack_b->size - 1];
		i = stack_b->size - 1;
		while (i--)
			stack_b->array[i + 1] = stack_b->array[i];
		stack_b->array[0] = tmp;
		// if (bool == 1)
		// 	write(1, "rrb\n", ft_strlen("rrb\n"));
	}
}

void	revrotate_s(t_stack *stack_a, t_stack *stack_b)
{
	revrotate_a(stack_a);
	revrotate_b(stack_b);
	// if (bool == 1)
	// 	write(1, "rrr\n", ft_strlen("rrr\n"));
}
