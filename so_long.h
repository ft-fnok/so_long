/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:35:37 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 11:22:45 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_HGH			400
# define WIN_WTH			800
# define TRUE				1
# define FALSE				0
# define INPUT_ERR			-1
# define MAP_ERR			-2
# define PATH_ERR			-3
# define MLX_CREATION_ERR	-4

# include <stdio.h>
// include for use of malloc
# include <unistd.h>
// include for use of minilibx functions
//# include <mlx.h>
// include for use of read
# include <fcntl.h>
// 42 curriculum
# include "./libft/libft.h"
# include "./printf/libftprintf.h"

// initial checks
int 	validate_input(int count, char *map);
int		validate_map(char **map);
int		validate_path(char *map);
int		get_map_width(char *map);
int		get_map_height(char **map);
int		check_side_walls(char **map, int i);
int		check_upper_lower_walls(char **map);
int		check_file_extension(char *map);

// reading map to memory
//char	**map2mem(int map_fd, char **map_ptr);
char	**map2mem(int map_fd, char **map_ptr);
char	**extend_map(char **map_ptr, int lines);


//

#endif