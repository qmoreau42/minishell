NAME        =    minishell

IDIR        =    minish.h

NAME_LFT	=	libft/libft.a

SRCS		=	main.c \
				token-izer.c \
				tok_lst.c \
				lexer.c \
				ft_split_cmd.c \
				dollar.c \
				launch_minishell.c \
				init_token.c \
				bin_path.c \
				exec_cmd.c \
				parsing.c \
				gestion_error.c \
				pars.c

OBJS		=	$(SRCS:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -g #-Werror
LINK		=	-lreadline -Llibft -lft
RM			=	rm -f
NORM		=	norminette *.h && norminette *.c 

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME)  $(OBJS) $(LINK)

n			:
	$(NORM)

clean		:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C libft

fclean		:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_LFT)

re			:	fclean all

.PHONY:		all clean fclean re
