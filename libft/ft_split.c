/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:06:52 by amaso             #+#    #+#             */
/*   Updated: 2022/01/26 12:07:54 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	**ft_countwords(char const *s, char c, size_t i, size_t n)
{
	char	**matrix;

	matrix = NULL;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] != c && i < ft_strlen(s))
				i++;
			n++;
			i--;
		}
		i++;
	}
	matrix = (char **) malloc (sizeof(char *) * (n + 1));
	if (matrix == NULL)
		return (NULL);
	matrix[n] = NULL;
	return (matrix);
}

char	**matrixgen(char const *s, char c, size_t i, char **matrix)
{
	size_t	n;
	size_t	len;

	len = 0;
	n = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i + len] != c && i + len < ft_strlen(s))
				len++;
			matrix[n] = ft_substr(s, (unsigned int)i, len);
			n++;
			i = i + len;
			len = 0;
			i--;
		}
		i++;
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	n;

	if (!s)
		return (NULL);
	matrix = NULL;
	n = 0;
	i = 0;
	matrix = ft_countwords(s, c, i, n);
	if (matrix == NULL)
		return (NULL);
	return (matrixgen(s, c, i, matrix));
}
