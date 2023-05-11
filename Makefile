NAME	= push_swap

FLAGS	= -Wall -Werror -Wextra

SRCS	=	ps.c \
			lst.c \
		 	psup.c \
			radix.c \
			fctuti.c \
			parsing.c \
			sortmini.c \

OBJS	= $(SRCS:.c=.o)

RM		= rm -rf 

$(NAME):	$(OBJS)
	gcc -g3 $(SRCS) -o $@

all:	$(NAME)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean flcean re all