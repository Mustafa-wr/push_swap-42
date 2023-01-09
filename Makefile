NAME = push_swap

SRCS = ft_printf/ft_printf.c		\
	   ft_printf/ft_supp.c			\
	   par.c						\
	   main.c						\
	   utils.c						\
	   ft_split.c					\
	   moves/moves.c				\
	   lsts/ft_lstnew.c				\
	   lsts/ft_lstadd_back.c		\
	   lsts/ft_lstadd_front.c		\
	   lsts/ft_lstlast.c			\
	   moves/moves2.c				\
	   moves/moves3.c				\
	   sorting.c					\
	   lsts/ft_lstsize.c


OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
