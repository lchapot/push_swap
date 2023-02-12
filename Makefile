NAME	= ps.a

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

all:	$(NAME)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=o)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean : $(RM) $(OBJS)

flcean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean flcean re all