SPATH	=	./srcs/
HPATH	=	./includes/
SRCS	=	$(SPATH)main.c $(SPATH)ft_gnl.c $(SPATH)ft_getargs.c \
		$(SPATH)utils.c $(SPATH)ft_exit.c $(SPATH)ft_exec_command.c \
		$(SPATH)ft_pwd.c $(SPATH)ft_setpwd.c

CC	=	gcc
CFLAG	=	-Wall -Werror -Wextra
OBJS	=	$(SRCS:.c=.o)
LIB	=	libshell.a
NAME	=	minishell

$(SPATH)%.o:	%.c
	$(CC) $(CFLAG) -c $‹

ALL:		$(LIB)

$(LIB):		$(OBJS)
		ar -rcs $(LIB) $(OBJS)
		$(CC) $(CFLAG) -L. -l shell -o $(NAME)

clean:
		rm -rf $(LIB)

fclean:
		rm -rf $(NAME) $(LIB) $(OBJS)

re:	fclean $(LIB)

.PHONY:		clean fclean re
