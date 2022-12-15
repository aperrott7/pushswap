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
    swap_a(stack_a);
    while(i < stack_a.size)
    {
        printf("\n POST SWAP stack_a.array[%i]=%d", i, stack_a.array[i]);
        i++;
    }
}

    // print da inserire nel mail per vedere la struttura anche nel main
    // printf("\n stack_a.size=%i \n", stack_a.size);
    // while(i < stack_a.size)
    // {
    //     printf("\n stack_a.array[%i]=%d", i, stack_a.array[i]);
    //     i++;
    // }
