CC= cc 
GFLAGS= -Wall -Wextra -Werror -fsanitize=address -g
NAME=get_next_line.a
SRCS=	get_next_line.c \
		get_next_line_utils.c \
		get_next_line_test.c \

OBJS= $(SRCS:*.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)

fclean: 
	rm -rf *.a