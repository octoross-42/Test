NAME = fdf

SRCS =  display/display.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) -I/usr/include -Iinclude/ -Imlx_linux -g3 -O3 -c $< -o ${<:.c=.o}	

$(NAME): ${OBJS}
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all : ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

