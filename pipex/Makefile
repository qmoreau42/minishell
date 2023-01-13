NAME        =    pipex

IDIR        =    pipex.h

SRCS		=	pipex.c \
				ft_libft.c \
				ft_split.c \
				exec.c \

OBJS		=	$(SRCS:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
NORM		=	norminette *.h && norminette *.c 

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

n			:
	$(NORM)

clean		:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

.PHONY:		all clean fclean re bonus
