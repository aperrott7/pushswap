#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "lib.h"


// static char	*dfltcase(char const *s, unsigned int start, size_t len);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// static unsigned int	count_words(const char *str, char div);
// char	**create_list(char **list, const char *s, char c);
// char	**ft_split(char const *s, char c);
// int	ft_isdigit(char c);
// char	*ft_strjoin(char const *s1, char const *s2);


int check_input(int argc, char **argv, t_stack *stack_a)
{
    int i;

    i = 1;
    if (argc<2)
        return (0);
    stack_a->joined = argv[1];
    while (i < argc - 1)
    {
        stack_a->joined = ft_strjoin(stack_a->joined, argv[i + 1]);
        i++;
    }
	printf("\n joined=%s", stack_a->joined);
    i = 0;

    while(i < strlen(stack_a->joined))
    {
        //printf("\nCHECK NUM joined[%i] = %c \n", i, joined[i]);
        if(ft_isdigit(stack_a->joined[i]) == 0)
            {
				printf("\nErrore - Carattere non numerico!\n");
				return(0);
			}
        i++;
    }
    return(1);
}

void split_input(t_stack *stack_a)
{
    char **splitted;
    int i;

    i = 0;
	splitted = ft_split(stack_a->joined, 32);
	while(*splitted)
	{
    	printf("\nsplitted[%i]=%s", i, *splitted);
		splitted++;
		i++;
	}
	splitted -= i;
	stack_a->array =  malloc(sizeof(int) * i);
    i = 0;
    while (*splitted)
    {
         stack_a->array[i] = atoi(*splitted);
         printf("\n stack_a->array[%i]=%d", i, stack_a->array[i]);
         i++;
		 splitted++;
    }
    stack_a->size = i;
    printf("\n stack_a->size=%i \n", stack_a->size);
	splitted -= stack_a->size;
}

int main (int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;

    int i;

    i = 0;
    if(check_input(argc, argv, &stack_a) == 0)
        return(0);
    split_input(&stack_a);
    stack_b.array = malloc(sizeof(int) * i);
    stack_b.size = i;
    sorting(&stack_a, &stack_b);

    return(0);

    /* check vari */
    /* ___________*/

    swap_a(stack_a);
    printf("\n____SWAP A ESEGUITO___\n");

   while(i < stack_a.size)
    {
        printf("\n stack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
    push_b(&stack_a, &stack_b);
    i = 0;
    printf("\n____PUSH_B ESEGUITO___\n");
    while(i < stack_a.size)
    {
        printf("\nstack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
    printf("\n");

    i = 0;
    while(i < stack_b.size)
        {
        printf("\nstack_b.array[%i]=%d\n", i, stack_b.array[i]);
        i++;
        }

    push_b(&stack_a, &stack_b);

    /* altro print */
    printf("\n____PUSH_B ESEGUITO altra volta___\n");
    i = 0;
    while(i < stack_a.size)
    {
        printf("\nstack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
    printf("\n");

    i = 0;
    while(i < stack_b.size)
        {
        printf("\nstack_b.array[%i]=%d", i, stack_b.array[i]);
        i++;
        }
    printf("\n");

     push_b(&stack_a, &stack_b);

    /* altro print */
    printf("\n____PUSH_B ESEGUITO altra volta___\n");
    i = 0;
    while(i < stack_a.size)
    {
        printf("\nstack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
    printf("\n");

    i = 0;
    while(i < stack_b.size)
        {
        printf("\nstack_b.array[%i]=%d", i, stack_b.array[i]);
        i++;
        }
    printf("\n");

    push_a(&stack_a, &stack_b);

    /* altro print */
    printf("\n__-_PUSH_A ESEGUITO ___\n");
    i = 0;
    while(i < stack_a.size)
    {
        printf("\nstack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
    printf("\n");

    i = 0;
    while(i < stack_b.size)
        {
        printf("\nstack_b.array[%i]=%d", i, stack_b.array[i]);
        i++;
        }
    printf("\n");

    swap_b(stack_b);
    printf("\n____SWAP B ESEGUITO___\n");

    i = 0;
   while(i < stack_b.size)
    {
        printf("\n stack_b.array[%i]=%d", i, stack_b.array[i]);
        i++;
    }

    swap_s(stack_a, stack_b);

    /* altro print */
    printf("\n__s_ SWAP S ESEGUITO ___\n");
    i = 0;
    while(i < stack_a.size)
    {
        printf("\nstack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
    printf("\n");

    i = 0;
    while(i < stack_b.size)
        {
        printf("\nstack_b.array[%i]=%d", i, stack_b.array[i]);
        i++;
        }
    printf("\n");

    rotate_a(stack_a);

    printf("\n__s_ ROTATE A ESEGUITO ___\n");
    i = 0;
    while(i < stack_a.size)
    {
        printf("\nstack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
    printf("\n");

    rotate_b(stack_b);

    printf("\n__s_ ROTATE B ESEGUITO ___\n");
    i = 0;
    while(i < stack_b.size)
    {
        printf("\nstack_b.array[%i]=%d", i, stack_b.array[i]);
        i++;
    }
    printf("\n");

    revrotate_a(&stack_a);

    printf("\n_rr_ revROTATE A ESEGUITO ___\n");
    i = 0;
    while(i < stack_a.size)
    {
        printf("\nstack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
    printf("\n");

    printf("\n check math. stack_b.array[1] + stack_a.array[5] = %i \n", stack_b.array[1] + stack_a.array[5]);
}
