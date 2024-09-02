/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:31:35 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/02 19:19:37 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;

	cdst = (char *)dest;
	csrc = (char *)src;
	if (!dest && !src)
		return (0);
	if (cdst > csrc)
	{
		while (n)
		{
			cdst[n - 1] = csrc[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
