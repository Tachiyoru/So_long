NAME =		so_long

SRCS_DIR = srcs/
CHECK_DIR = check/

GNL_DIR = GNL/

SRCS =		main.c									\
			utils.c									\
			check_map.c			\
			check_map2.c				\
			error.c						\
			map_way_ok.c						\
			${GNL_DIR}get_next_line.c								\
			${GNL_DIR}get_next_line_utils.c

OBJS =		${SRCS:.c=.o}

DEFAULT			=	\033[0m
RED				=	\033[1;31m
GREEN			=	\033[1;32m

CC =		clang

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g

MLX =		./mlx

MLX_LIB = 	./mlx/libmlx_Linux.a

.c.o:		${DEPS}
		${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} $(MLX_LIB)
		${CC} ${CFLAGS}  ${OBJS} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		@echo "$(GREEN)##### so_long est compilé ! #####$(DEFAULT)"

$(MLX_LIB):
		make -C ${MLX} -j


all:		${NAME}

clean:
		${RM} ${OBJS}
		make clean -C ${MLX}

fclean:		clean
		${RM} ${NAME}
		${RM} ${NAME} ${MLX_LIB}
		@echo "\n${RED}#### Tout est supprimé ! ####${DEFAULT}"

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re
