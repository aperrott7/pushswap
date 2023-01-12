/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:13:27 by amaso             #+#    #+#             */
/*   Updated: 2022/01/24 12:33:09 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*get_i_and_sign(int *n, int *sign, int *i)
{
	int		m;
	char	*str;

	str = NULL;
	m = (*n);
	while (m != 0)
	{
		m /= 10;
		(*i)++;
	}
	if ((*n) < 0)
	{
		(*sign) = -1;
		(*n) = (*n) * (*sign);
	}
	if ((*sign) == -1)
		str = (char *) malloc (sizeof(char) * (*i) + 2);
	else
		str = (char *) malloc (sizeof(char) * (*i) + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

static int	ft_power(int i)
{
	int	res;

	res = 1;
	while (i > 1)
	{
		res = res * 10;
		i--;
	}
	return (res);
}

static char	*ft_limitcases(int n, char *str)
{
	if (n == -2147483648)
	{
		str = (char *) malloc (sizeof(char) * 12);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		str[1] = 2 + '0';
		str[2] = 1 + '0';
		str[3] = 4 + '0';
		str[4] = 7 + '0';
		str[5] = 4 + '0';
		str[6] = 8 + '0';
		str[7] = 3 + '0';
		str[8] = 6 + '0';
		str[9] = 4 + '0';
		str[10] = 8 + '0';
		str[11] = '\0';
		return (str);
	}
	str = (char *) malloc (sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = 0 + '0';
	str[1] = '\0';
	return (str);
}

static char	*strfill(char *str, int n, int i, int m)
{
	while (n != 0)
	{
		str[m] = (n / (ft_power(i))) + '0';
		n = n - ((str[m] - '0') * ft_power(i));
		i--;
		m++;
		if (n == 0 && i > 0)
		{
			while (i > 0)
			{
				str[m] = 0 + '0';
				i--;
				m++;
			}
		}
	}
	str[m] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		m;
	int		sign;

	str = NULL;
	sign = 1;
	m = 0;
	i = 0;
	if (n == 0 || n == -2147483648)
		return (ft_limitcases(n, str));
	str = get_i_and_sign(&n, &sign, &i);
	if (str == NULL)
		return (NULL);
	if (sign == -1)
	{
		str[m] = 45;
		m++;
	}
	str = strfill(str, n, i, m);
	return (str);
}
