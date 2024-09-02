/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:47:22 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/13 18:47:33 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa_max(unsigned int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		i = ft_printhexa_max(n / 16);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[(n % 16)]);
	return (i + 1);
}
