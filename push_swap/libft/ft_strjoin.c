/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:59:58 by amaso             #+#    #+#             */
/*   Updated: 2022/01/18 21:10:23 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	l1;
	size_t	l2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *) malloc (sizeof(char) * (l1 + l2 + 1));
	if (str == NULL)
		return (NULL);
	while (i < l1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i <= (l1 + l2))
	{
		str[i] = s2[i - l1];
		i++;
	}
	return (str);
}
