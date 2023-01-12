/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:46:50 by amaso             #+#    #+#             */
/*   Updated: 2022/01/17 13:59:20 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dfltcase(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	c;

	i = 0;
	c = (ft_strlen(s) - (size_t) start);
	if (ft_strlen(s) - start > len)
		sub = (char *) malloc((sizeof(char) * (len + 1)));
	else
		sub = (char *) malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && i < c)
	{
		sub[i] = s[(size_t) start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) > (size_t) start)
		return (dfltcase(s, start, len));
	else
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
}
