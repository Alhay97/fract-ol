NAME		=	fractol
LIBX_DIR	=	minilibx
LIBX		=	libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = $(wildcard *.c)
OBJS		=	$(SRCS:%c=%o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g

%.o : %.
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	Make -C minilibx/
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME) ./minilibx/libmlx.a

all : $(NAME)

clean:
	rm -rf ${OBJS}

fclean: clean
	Make clean -C ./minilibx
	rm -rf ${NAME} fract-ol

re: fclean all

