/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:49:50 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/13 18:50:00 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		i = ft_putptr(n / 16);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[(n % 16)]);
	return (i + 1);
}
