/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:18:20 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 00:03:39 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_mal
{
	int					pos;
	uintptr_t			*ptr;
	int					len;
}						t_mal;
typedef struct s_dir
{
	int			i;
	int			j;
	int			n;
	int			s;
	int			w;
	int			e;
}				t_dir;

typedef struct s_paths
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	int			count_paths;
}				t_paths;

typedef struct s_colors
{
	char		*floor_color;
	char		*ceiling_color;
	int			ceiling;
	int			floor;
	int			count_rgb;
}				t_colors;

typedef struct s_main
{
	int			count;
	int			fd;
	char		*str;
	char		**sp;
	char		**map;
	char		**map2;
	void		*mlx;
	void		*win;
	void		*xpm_img;
	int			pos_y;
	int			pos_x;
	int			i;
	int			j;
	int			w;
	int			h;
	t_paths		*p;
	t_colors	*c;
}				t_main;

typedef struct s_rgb
{
	int	i;
	int	j;
	int	f;
	int	c;
}				t_rgb;

typedef struct s_fc
{
	int		i;
	int		j;
	int		count;
	int		count1;
	int		lock;
	char	*floor;
}				t_fc;

typedef struct s_fc1
{
	int	i;
	int	r;
	int	g;
	int	b;
}				t_fc1;

typedef struct s_cc
{
	int		i;
	int		j;
	int		count;
	int		count1;
	int		lock;
	char	*ceiling;
}				t_cc;

typedef struct s_cc1
{
	int	i;
	int	r;
	int	g;
	int	b;
}				t_cc1;

void			check_name(char *name);
void			new_line_inside(t_main *m);
int				map_frst_line(t_main *m);
void			check_check(t_main *m);

char			*ft_read_str(int fd, char *str);
char			*ft_strjoin1(char *left_str, char *buff);

void			create_map(t_main *m);

char			*dir_path(t_main *m);
void			items_check(t_main *m);
int				line_count(t_main *m);
int				line_len(char *s);
int				map_check_first(t_main *m);
int				map_check_last(t_main *m);

void			invalid_item(t_main *m);
int				p_check(t_main *m);

void			put_floor(t_main *m);
int				put_image(t_main *m);

void			invalid_item_error(void);
void			arg_error(void);
void			sides_error(void);
void			horinzontal_error(void);
void			duplicated_player_error(void);
void			path_error(void);
void			void_next_floor(void);
void			color_error(void);
void			undefined_line_error(void);
void			empty_line_inside(void);

int				moving_key(int keysym, t_main *m);
void			right_key(t_main *m);
void			left_key(t_main *m);
void			down_key(t_main *m);
void			up_key(t_main *m);

void			for_north(t_main *m, t_dir *dir);
void			for_south(t_main *m, t_dir *dir);
void			for_west(t_main *m, t_dir *dir);
void			for_east(t_main *m, t_dir *dir);

void			check_sides(t_main *m);
int				white_space(char c);
void			around_floor(t_main *m);
void			line_undef(t_main *m);

void			floor_before_player(t_main *m);
void			looking_right(t_main *m);
void			looking_left(t_main *m);
void			looking_up(t_main *m);
void			looking_down(t_main *m);

void			*my_malloc(size_t size);
t_mal			*head(void);
int				get_available_pos(void);
void			ft_memset1(void *pointer, int c, size_t len);
void			*ft_memcpy1(void *destination, void *source, size_t len);

char			*floor_ceiling(t_main *m);
int				merge_floor_color(t_main *m);
int				merge_ceiling_color(t_main *m);

void			fill_floor_f(t_fc *f, char *str, char *floor);
void			init_var_fcf(t_fc	*f, char *str);

void			fc_skip(t_main *m, t_fc1 *f);
int				fc_first(t_main *m, t_fc1 *f);
int				fc_second(t_main *m, t_fc1 *f);
int				fc_third(t_main *m, t_fc1 *f);
int				fc_do_all(t_main *m, t_fc1 *f);

void			fill_ceiling_f(t_cc *f, char *str, char *ceiling);
void			init_var_ccf(t_cc	*f, char *str);

void			cc_skip(t_main *m, t_cc1 *f);
int				cc_first(t_main *m, t_cc1 *f);
int				cc_second(t_main *m, t_cc1 *f);
int				cc_third(t_main *m, t_cc1 *f);
int				cc_do_all(t_main *m, t_cc1 *f);

#endif