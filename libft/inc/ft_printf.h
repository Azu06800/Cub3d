/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:46:52 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/18 16:17:32 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_printhexa_min(unsigned int n);
int		ft_putinnbr(unsigned int n);
int		ft_putptr(unsigned long int n);
int		ft_printhexa_max(unsigned int n);

#endif
