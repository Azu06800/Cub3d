RED		=	\033[31m
GRE		=	\033[32m
BLU		=	\033[36m
YEL		=	\033[33m
EOC		=	\033[0m
BEI		=	\033[38;5;223m

DEF		=	\033[0m
BOLD	=	\033[1m
CUR		=	\033[3m
UL		=	\033[4m
UP		=	\033[A

NAME		=	cub3D

SOURCES		=	./src
INCLUDES	=	./include
OBJECTS		=	./bin

SRCS			=	utils_for_cpy_tab_maps.c map_final_function.c utils_for_maps.c main.c function_free.c Raycasting.c Raycasting2.c Movement.c mlx_functions.c mlx_functions2.c utils.c\
					$(addprefix first_part/, check_file_nd_cpy.c cpy_tab_textur.c parsing_tab_direction.c size_str_texture_2.c size_str_texture.c parsing_tab_texture.c tab_to_int.c)


OBJS		=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))
LIBFT 		= ./libft
MLX_DIR 	=	./minilibx/
CFLAGS		=	-Wall -Wextra -Werror -g -I$(MLX_DIR) -Iinclude -lm
CC			=	gcc
CINCLUDES	=	-I ${INCLUDES}
# ---------------------------------------------------------------------------- #

SRCS_COUNT = 0
SRCS_TOT = ${shell find ./src/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR =  ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

${OBJECTS}/%.o: ${SOURCES}/%.c
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}
	@echo ""
	@echo "\r\033[K -> Compilation de ""$(YEL)${notdir $<}$(EOC). ⏳"
	@printf "   ${BEI}[%-23.${BAR}s] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}${UP}"

all: start ${NAME}

start:
	@if [ ! -e "bin" ]; then \
		echo "🚀 Début de la compilation de $(BLU)${NAME} 🚀$(EOC)"; \
	else \
		echo "make: Nothing to be done for \`all'."; \
	fi

${NAME}: ${OBJS}
	@clear
	@echo "$(GRE)✅ Compilation terminée.$(EOC)"	
	@${MAKE} -C ${LIBFT}/
	@$(CC) -L$(MLX_DIR) -o $@ $^ -lmlx $(CFLAGS) -lX11 -lXext ${LIBFT}/libft.a

clean:
	@echo "🗑  $(RED)Supression des fichiers binaires (.o).$(EOC) 🗑"
	@rm -rf ${OBJECTS}

fclean: clean
	@echo "🗑  $(RED)Supression des executables et librairies.$(EOC) 🗑"
	@rm -f ${NAME}
	@rm -rf includes/readline
	@clear

re: fclean all

fcleanr: clean
	@echo "🗑  $(RED)Supression des executables et librairies.$(EOC) 🗑"
	@rm -f ${NAME}
	@clear

rer: fcleanr all

.PHONY:	all clean fclean re