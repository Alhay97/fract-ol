NAME		=	fract-ol
LIBX_DIR	=	minilibx
LIBX		=	libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = $(wildcard *.c)
OBJS		=	$(SRCS:%c=%o)
CC			=	gcc
CFLAGS		=	-Ofast

%.o : %.c
	$(CC) -g  -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)

all : $(NAME)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME} fract-ol

re: fclean all

