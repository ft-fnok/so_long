/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:54:10 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 19:42:14 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_input(int count, char *map_file)
{
	int		map_fd;
	char	**map_ptr;
	int		err;

	err = 0;
	if (count != 2)
		return (INPUT_ERR);
	if (check_file_extension(map_file) < 0)
		return (INPUT_ERR_EXT);
	map_fd = open(map_file, O_RDONLY);
	map_ptr = ft_calloc(1, sizeof(char *));
	map_ptr = map2mem(map_fd, map_ptr);
	err = error_checking(map_ptr);
	free(map_ptr);
	close(map_fd);
	return (err);
}

int	validate_map(char **map)
{
	int			i;
	int			j;
	const int	map_rows = get_map_height(map);
	const int	map_cols = ft_strlen(map[0]);

	if (map_cols < 3 || map_rows < 3)
		return (MAP_ERR_WALL);
	j = 0;
	i = 0;
	if (check_upper_lower_walls(map) < 0)
		return (MAP_ERR_WALL);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != (size_t) map_cols)
			return (MAP_ERR_RECT);
		else if (check_side_walls(map, i) < 0)
			return (MAP_ERR_WALL);
		i++;
	}
	return (0);
}

int	validate_chars(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
				return (MAP_ERR_CHAR);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	error_checking(char **map_ptr)
{
	int	err;

	err = 0;
	err = validate_chars(map_ptr);
	if (err < 0)
		return (err);
	err = validate_map(map_ptr);
	if (err < 0)
		return (err);
	err = validate_setting(map_ptr, 1, 0);
	if (err < 0)
		return (err);
	err = validate_path(map_ptr);
	return (err);
}

void	error_interpreter(int err)
{
	ft_printf("Error\n");
	if (err == INPUT_ERR)
		ft_printf("No map provided or too many inputs.");
	else if (err == INPUT_ERR_EXT)
		ft_printf("File has wrong extension.\n");
	else if (err == MAP_ERR_CHAR)
		ft_printf("Detected wrong character in mapfile.\n");
	else if (err == MAP_ERR_RECT)
		ft_printf("Map not rectangular.\n");
	else if (err == MAP_ERR_WALL)
		ft_printf("Walls on map incorrect.\n");
	else if (err == MAP_ERR_SET)
		ft_printf("Incorrect setup. Check player, collectibles and exit.\n");
	else if (err == PATH_ERR)
		ft_printf("Incorrect setup. No valid path on map.\n");
}
