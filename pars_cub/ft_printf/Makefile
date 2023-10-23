NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = 	call.c\
			ft_printf.c\

OBJECTS = ${SOURCES:.c=.o}

all : $(NAME)

$(NAME):	$(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	$(RM)	$(OBJECTS)

fclean:	clean
	$(RM) $(NAME)

re:clean fclean all

.PHONY: all clean fclean re