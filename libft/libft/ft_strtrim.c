/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:49:37 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/04 15:57:23 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	start = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (start == ft_strlen(s1))
	{
		str = ft_strdup("");
		return (str);
	}
	while (ft_strchr(set, s1[len - 1]) && len > start)
		len--;
	str = ft_substr(s1, start, len - start);
	return (str);
}
