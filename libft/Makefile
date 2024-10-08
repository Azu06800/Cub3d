# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dravaono <dravaono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 11:31:47 by dravaono          #+#    #+#              #
#    Updated: 2024/07/16 15:23:54 by dravaono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL_PATH = ./gnl
GNL_SRCS = ${addprefix ${GNL_PATH}/, get_next_line_bonus.c \
										get_next_line_utils_bonus.c}

LIBFT_PATH = ./libft
LIBFT_SRCS = ${addprefix ${LIBFT_PATH}/, ft_atoi.c \
											ft_bzero.c \
											ft_calloc.c \
											ft_isalnum.c \
											ft_isalpha.c \
											ft_isascii.c \
											ft_isdigit.c \
											ft_isprint.c \
											ft_itoa.c \
											ft_lstadd_back.c \
											ft_lstadd_front.c \
											ft_lstclear.c \
											ft_lstdelone.c \
											ft_lstiter.c \
											ft_lstlast.c \
											ft_lstnew.c \
											ft_lstsize.c \
											ft_memchr.c \
											ft_memcmp.c \
											ft_memcpy.c \
											ft_memmove.c \
											ft_memset.c \
											ft_putchar_fd.c \
											ft_putendl_fd.c \
											ft_putnbr_fd.c \
											ft_putstr_fd.c \
											ft_split.c \
											ft_strdup.c \
											ft_striteri.c \
											ft_strjoin.c \
											ft_strlcat.c \
											ft_strlcpy.c \
											ft_strlen.c \
											ft_strmapi.c \
											ft_strncmp.c \
											ft_strnstr.c \
											ft_strrchr.c \
											ft_strtrim.c \
											ft_substr.c \
											ft_tolower.c \
											ft_toupper.c \
											newutils.c}
											
PRINTF_PATH = ./printf
PRINTF_SRCS = ${addprefix ${PRINTF_PATH}/, ft_printf.c \
											ft_printhexa_max.c \
											ft_printhexa_min.c \
											ft_putchar.c \
											ft_putinnbr.c \
											ft_putnbr.c \
											ft_putptr.c \
											ft_putstr.c \
											ft_strchr.c}

SRCS = ${GNL_SRCS} ${PRINTF_SRCS} ${LIBFT_SRCS}

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = ./inc

%.o:%.c ${INCLUDE}
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

NAME = libft.a
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@echo "COMPILED ${NAME}"

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
