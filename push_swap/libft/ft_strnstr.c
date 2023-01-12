/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:27:26 by amaso             #+#    #+#             */
/*   Updated: 2022/01/12 17:31:16 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	d;

	d = 1;
	i = 0;
	if (to_find[i] == '\0')
		return ((char *) str);
	if (str[i] == '\0' || len < (size_t) ft_strlen(to_find))
		return (0);
	len = len - (size_t) ft_strlen(to_find);
	while (i <= len)
	{
		if (str[i] == to_find[0])
		{
			while (to_find[d] != '\0' && to_find[d] == str[i + d])
				d++;
			if (to_find[d] == '\0')
				return ((char *) &str[i]);
			else
				d = 1;
		}
		i++;
	}
	return (0);
}
