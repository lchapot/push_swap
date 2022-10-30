NAME	= ps.a

FLAGS	= -Wall -Werror -Wextra

SRCS	= 	ps_supp.c \
			ps_supp2.c \
			algo.c \
			ps.c \

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