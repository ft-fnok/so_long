/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:35:37 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/21 18:26:20 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_HGH			400
# define WIN_WTH			800
# define TRUE				1
# define FALSE				0
// # define INPUT_ERR			-10
// # define INPUT_ERR_EXT		-11
// # define MAP_ERR_CHAR		-20
// # define MAP_ERR_RECT		-21
// # define MAP_ERR_WALL		-22
// # define MAP_ERR_SET		-23
// # define PATH_ERR			-30
// # define MLX_CREATION_ERR	-40

// enums
enum program_codes {
		ON_DESTROY			=	17,
		ON_KEYDOWN			=	2,
		INPUT_ERR 			=	-10,
		INPUT_ERR_EXT		=	-11,
		MAP_ERR_CHAR		=	-20,
		MAP_ERR_RECT		=	-21,
		MAP_ERR_WALL		=	-22,
		MAP_ERR_SET			=	-23,
		PATH_ERR			=	-30,
		MLX_CREATION_ERR	=	-40,
};

# include <stdio.h>
// include for use of malloc
# include <unistd.h>
// include for use of minilibx functions
# include <mlx.h>
// include for use of read
# include <fcntl.h>
// 42 curriculum
# include "./libft/libft.h"
# include "./printf/libftprintf.h"

// typedefs

typedef struct	s_data
{
	char	**map;
	int		player_y;
	int		player_x;
	int		collectibles;
	int		moves;
	void	*mlx_ptr;
	void	*mlx_win;
}				t_data;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

// initial checks
int		validate_input(int count, char *map);
int		error_checking(char **map_ptr);
int		validate_map(char **map);
int		validate_chars(char **map);
int		validate_setting(char **map, int i, int j);
int		validate_path(char **map_ptr);
int		get_map_height(char **map);
int		check_side_walls(char **map, int i);
int		check_upper_lower_walls(char **map);
int		check_file_extension(char *map);
void	error_interpreter(int err);

// path verification
int		validate_path(char **map_ptr);
void	get_player_pos(int *player_pos, char **map_ptr);
void	pour_water(int pos_y, int pos_x, char **map_ptr);
int		check_flooded_map(char **map_ptr);

// reading map to memory
char	**map2mem(int map_fd, char **map_ptr);
char	**extend_map(char **map_ptr, int lines);

// game functions
void	init_data(t_data *data);
int		so_long(t_data *data);
void	better_mlx_pixel_put(t_img *data, int x, int y, int color);
int		handle_no_event(void);
int		handle_input(int keycode, t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	init_collectibles(t_data *data);
void	player_yx(t_data *data);

#endif