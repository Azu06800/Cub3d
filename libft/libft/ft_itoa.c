/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:43:51 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/04 17:44:12 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_nbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
	}
	if (!n)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*dst;
	int			i;
	long int	nbr;

	i = count_nbr(n);
	dst = malloc(i * sizeof(char) + 1);
	if (!dst)
		return (0);
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		dst[0] = '-';
	}
	dst[i--] = '\0';
	if (n == 0)
		dst[i] = '0';
	while (nbr)
	{
		dst[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	return (dst);
}
