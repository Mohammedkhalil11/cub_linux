# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 20:24:10 by iszitoun          #+#    #+#              #
#    Updated: 2023/03/01 13:49:37 by iszitoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
src =	ft_isdigit.c\
		ft_isalpha.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_memset.c\
		ft_memcpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_bzero.c\
		ft_strdup.c\
		ft_calloc.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\

OBJECTS = ${src:.c=.o}

all	:	$(NAME)

$(NAME):	$(OBJECTS)
		ar -rc $(NAME) $(OBJECTS) 
		
clean :
	$(RM) $(OBJECTS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY: all clean fclean re
