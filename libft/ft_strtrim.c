/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:20:34 by amaso             #+#    #+#             */
/*   Updated: 2022/01/19 18:07:48 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	get_i(char const *s1, char const *set)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = 0;
	while (set[c] != '\0')
	{
		if (s1[i] == set[c])
		{
			i++;
			c = 0;
		}
		else
			c++;
	}
	return (i);
}

static size_t	get_len(char const *s1, char const *set)
{
	size_t	c;
	size_t	len;

	c = 0;
	len = ft_strlen(s1);
	if (len > 0)
		len--;
	while (set[c] != '\0' && len > 0)
	{
		if (s1[len] == set[c])
		{
			len--;
			c = 0;
		}
		else
			c++;
	}
	return (len);
}

static char	*fillstr(char const *s1, size_t len, size_t i)
{
	size_t	c;
	char	*str;

	c = 0;
	str = (char *) malloc(sizeof(char) * ((len - i)) + 2);
	if (str == NULL)
		return (NULL);
	while (i <= len)
	{
		str[c] = s1[i];
		i++;
		c++;
	}
	str[c] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	c;
	size_t	i;

	if (!s1 || !set)
		return (0);
	i = get_i(s1, set);
	c = 0;
	len = get_len(s1, set);
	if (i > len)
	{
		str = (char *) malloc (1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	else
		return (fillstr(s1, len, i));
}
