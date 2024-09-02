/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:53:26 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/10 13:22:14 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;

	j = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (size <= j)
	{
		return (size + srclen);
	}
	while (src[i] && j + 1 < size)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(src + i) + j);
}

/*int main()
{
	char dst[] = "je22";
	char src[] = "suis";
	
	printf("%zu\n", ft_strlcat(dst, src, 2));
}*/
