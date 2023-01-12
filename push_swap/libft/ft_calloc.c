/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:24:35 by amaso             #+#    #+#             */
/*   Updated: 2022/01/12 16:52:48 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*a;

	a = malloc (size * nmeb);
	if (a == NULL)
		return (a);
	ft_memset(a, 0, (size * nmeb));
	return (a);
}
