/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:54:11 by amaso             #+#    #+#             */
/*   Updated: 2022/01/17 14:00:34 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_stack {
    char    *joined;
	int     size;
    int     *array;
}				t_stack;

static char	        *dfltcase(char const *s, unsigned int start, size_t len);
char	            *ft_substr(char const *s, unsigned int start, size_t len);
static unsigned int	count_words(const char *str, char div);
char            	**create_list(char **list, const char *s, char c);
char	            **ft_split(char const *s, char c);
int	                ft_isdigit(char c);
char            	*ft_strjoin(char const *s1, char const *s2);
void	            swap_a(t_stack stack);
void            	swap_b(t_stack stack_b);
void	            swap_s(t_stack stack, t_stack stack2);
void            	push_a(t_stack *stack_a, t_stack *stack_b);
void            	push_b(t_stack *stack_a, t_stack *stack_b);
void	            rotate_a(t_stack stack_a);
void	            rotate_b(t_stack stack_b);
void	            rotate_s(t_stack stack_a, t_stack stack_b);
void            	revrotate_a(t_stack *stack_a);
void            	revrotate_b(t_stack *stack_b);
void            	revrotate_s(t_stack *stack_a, t_stack *stack_b);
void            	sorting(t_stack *stack_a, t_stack *stack_b);
void            	sort_tre(t_stack *stack_a);
#endif
