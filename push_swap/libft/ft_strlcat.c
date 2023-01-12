/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:28:09 by amaso             #+#    #+#             */
/*   Updated: 2022/01/13 11:53:49 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (size <= d)
		return (s + size);
	while ((d + i) < (size - 1) && src[i] != '\0')
	{
		dst[d + i] = src[i];
		i++;
	}
	if ((d + i) < size)
		dst[d + i] = '\0';
	return (s + d);
}
