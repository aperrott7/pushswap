/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:57:22 by amaso             #+#    #+#             */
/*   Updated: 2022/01/12 19:32:27 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	i;

	i = 0;
	c = (char *) malloc (ft_strlen(s) + 1);
	if (c == NULL)
		return (c);
	while (i <= ft_strlen(s))
	{
		c[i] = s[i];
		i++;
	}
	return (c);
}
