/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:34:12 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/20 03:02:05 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# define MIN_ANGLE 0.0
# define MAX_ANGLE 6.28318530718
# include "../pars_cub/Libft/libft.h"
# include "../pars_cub/ft_printf/ft_printf.h"
# include <fcntl.h>

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_wall_hit
{
	int		i;
	int		j;
	double	x_intersect;
	double	y_intersect;
	bool	is_facing_down;
	bool	is_facing_left;
	bool	is_facing_right;
	bool	is_facing_up;
	double	y_distance;
	double	x_distance;
	double	xstep;
	double	ystep;
}			t_wall;

typedef struct s_tex
{
	void			*text_wall;
	int				textuer_x_width;
	int				textuer_y_hight;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*texture_ptr;
	char			*buffer;

}					t_tex;

typedef struct s_map
{
	int			text_id;
	double		field_of_view;
	int			wall_width;
	double		wall_height;
	int			num_rays;
	int			size_of_sq;
	int			size_of_sq_map;
	void		*nord_texture;
	int			x;
	int			y;
	double		x_player;
	double		y_player;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			windows_height;
	int			windows_width;
	int			map_height;
	int			map_width;
	int			move_speed;
	double		rotation_speed;
	int			last_position;
	double		player_angle;
	double		vert_wall_hit_x;
	double		vert_wall_hit_y;
	double		hort_wall_hit_x;
	double		hort_wall_hit_y;
	int			find_vert_intersept;
	int			find_hort_intersept;
	int			x_offset_texture;
	int			y_offset_texture;
	int			canvas_height[4];
	int			canvas_width[4];
	int			text_height;
	int			text_width;
	double		wall_hit_x;
	double		wall_hit_y;
	double		wall_hit_x_map;
	double		wall_hit_y_map;
	double		distance_of_ray;
	double		distance_v;
	double		distance_h;
	char		**map;
	int			*tab;
	int			turn_left;
	int			turn_right;
	int			ceil_color;
	int			floor_color;
	int			map_size;
	int			scale1;
	int			scale2;
	int			prev_x;
	t_mlx		*mlx;
	t_data		*img;
	t_data		img2;
	t_tex		text[4];
}			t_map;

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
int				creat_map(t_map *map_v, t_data *img);
int				*line_count_dy(char **m);
void			move_up(t_map *map_v);
void			move_down(t_map *map_v);
void			move_left(t_map *map_v);
void			move_right(t_map *map_v);
void			update_player_position(t_map *map_v);
int				key_hook(int keycode, t_map *map_v);
int				key_reales(int keycode, t_map *map_v);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			fetch_wall_hit_v(t_map *map_v, double angle);
void			fetch_wall_hit_h(t_map *map_v, double angle);
void			render_3d_textures(t_map *vars, int k);
void			render_all_component(t_map *map_v);
void			render_all_rays(t_map *map_v);
int				get_color_texture(t_tex *tex, int x, int y, t_map *map_v);
int				distance_between_two_hits(t_map *map_v);
int				update_map(t_map *map_v);
char			**get_map(t_main *m);
char			**resize_map(char **map, int *dimensions);
void			fetch_player_position(t_map *map_v);
void			loading_all_textures(t_map *map_v, t_main *m);
void			copy_map(t_data *img, t_data *img2, t_map *map_v);
#endif