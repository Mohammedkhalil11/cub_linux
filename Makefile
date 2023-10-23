NAME = cub3D
NAME_BONUS = cub3D_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = cub3d.c\
			pars_cub/create_map.c\
			pars_cub/error.c\
			pars_cub/error1.c\
			pars_cub/ft_strjoin1.c\
			pars_cub/direction_paths.c\
			pars_cub/direction_paths_utils.c\
			pars_cub/parssing.c\
			pars_cub/parssing1.c\
			pars_cub/parssing2.c\
			pars_cub/parssing3.c\
			pars_cub/read_map.c\
			pars_cub/my_malloc.c\
			pars_cub/my_malloc_utils.c\
			pars_cub/rgb.c\
			pars_cub/rgb1.c\
			pars_cub/rgb1_1.c\
			pars_cub/rgb2.c\
			pars_cub/rgb2_2.c\
			moves.c\
			horizontal_hit.c\
			vertical_hit.c\
			3d_textures.c\
			all_component.c\
			get_color.c\
			get_map.c\
			hook.c\
			loading_textures.c\

BONUS = bonus_fi/cub3d_bonus.c\
			bonus_fi/2d_map_bonus.c\
			bonus_fi/all_component_bonus.c\
			bonus_fi/cub3d_bonus_utils.c\
			bonus_fi/loading_textures_bonus.c\
			pars_cub/create_map.c\
			pars_cub/error.c\
			pars_cub/error1.c\
			pars_cub/ft_strjoin1.c\
			pars_cub/direction_paths.c\
			pars_cub/direction_paths_utils.c\
			pars_cub/parssing.c\
			pars_cub/parssing1.c\
			pars_cub/parssing2.c\
			pars_cub/parssing3.c\
			pars_cub/read_map.c\
			pars_cub/my_malloc.c\
			pars_cub/my_malloc_utils.c\
			pars_cub/rgb.c\
			pars_cub/rgb1.c\
			pars_cub/rgb1_1.c\
			pars_cub/rgb2.c\
			pars_cub/rgb2_2.c\
			moves.c\
			horizontal_hit.c\
			vertical_hit.c\
			3d_textures.c\
			get_color.c\
			get_map.c\
			hook.c\

LIBFT_OB = pars_cub/Libft/libft.a\

FT_PRINTF_OB = pars_cub/ft_printf/libftprintf.a\

OBJECTS_BONUS = ${BONUS:.c=.o}
OBJECTS = ${SOURCES:.c=.o}


all : $(NAME) $(LIBFT_OB)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):	$(OBJECTS) $(LIBFT_OB)
	$(CC) $(CFLAGS) $(OBJECTS)  $(FT_PRINTF_OB) $(LIBFT_OB) -Lmlx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus : $(NAME_BONUS) $(LIBFT_OB)
$(NAME_BONUS):	$(OBJECTS_BONUS) $(LIBFT_OB)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(FT_PRINTF_OB) $(LIBFT_OB) -Lmlx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_BONUS)

$(LIBFT_OB):
	make all -C pars_cub/Libft
	make -C pars_cub/ft_printf

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)
	make clean -C pars_cub/Libft
	make clean -C pars_cub/ft_printf

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make fclean -C pars_cub/Libft
	make fclean -C pars_cub/ft_printf

re: clean fclean all
	make re -C pars_cub/Libft
	make re -C pars_cub/ft_printf

re_bonus: clean fclean bonus
	make re -C pars_cub/Libft
	make re -C pars_cub/ft_printf

.PHONY: all clean fclean re
