NAME =		so_long
NAME_B =	so_long_b

SRCS_DIR = srcs/

GNL_DIR = GNL/
BONUS_DIR = bonus/

MAIN = 		main.c							\
			${SRCS_DIR}check_map2.c

SRCS =		${SRCS_DIR}utils.c				\
			${SRCS_DIR}utils2.c				\
			${SRCS_DIR}close.c				\
			${SRCS_DIR}gaming.c				\
			${SRCS_DIR}gaming_mov.c			\
			${SRCS_DIR}mapping.c			\
			${SRCS_DIR}setup_mlx.c			\
			${SRCS_DIR}check_map.c			\
			${SRCS_DIR}error.c				\
			${SRCS_DIR}map_way_ok.c			\
			${GNL_DIR}get_next_line.c		\
			${GNL_DIR}get_next_line_utils.c

B_SRCS =	${BONUS_DIR}main_b.c			\
			${BONUS_DIR}check_map2_b.c		\
			${BONUS_DIR}mstr_utils.c		\
			${BONUS_DIR}ennemy.c

MAIN_M =	${MAIN:.c=.o}
OBJS =		${SRCS:.c=.o}
OBJS_B =	${B_SRCS:.c=.o}

DEFAULT			=	\033[1;0m
RED				=	\033[1;31m
GREEN			=	\033[1;32m

CC =		clang

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -fstandalone-debug -g3 -I.

MLX =		./mlx

MLX_LIB = 	./mlx/libmlx_Linux.a

all:		${NAME}

.c.o:
		${CC} ${CFLAGS} -I${MLX} -c $< -o ${<:.c=.o}

$(MLX_LIB):
		make -C ${MLX} -j

$(NAME):	${MAIN_M} ${OBJS} $(MLX_LIB)
		${CC} ${CFLAGS} ${MAIN_M} ${OBJS} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		@echo "$(GREEN)##### so_long est compilé ! #####$(DEFAULT)"

bonus : $(NAME_B)

$(NAME_B):	${OBJS} ${OBJS_B} $(MLX_LIB)
		${CC} ${CFLAGS} ${OBJS} ${OBJS_B} -o ${NAME_B} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		@echo "$(GREEN)##### so_long est compilé avec bonus! #####$(DEFAULT)"
		
clean:
		${RM} ${OBJS}
		${RM} ${MAIN_M}
		${RM} ${OBJS_B}
		make clean -C ${MLX}

fclean:		clean
		${RM} ${NAME}
		${RM} ${NAME_B}
		${RM} ${NAME} ${MLX_LIB}
		@echo "\n${RED}#### Tout est supprimé ! ####${DEFAULT}"

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re
