/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation-helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:14:45 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 11:47:12 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **extend_map(char **map_ptr, int lines)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc((lines + 1) * sizeof(char *));
	new[lines] = ft_calloc(1, sizeof(char));
	while (i < lines)
	{
		new[i] = map_ptr[i];
		i++;
	}
	free(map_ptr);
	return (new);
}

int	check_side_walls(char **map, int i)
{
	if (map[i][0] == '1' && map[i][(ft_strlen(map[i]) - 1)] == '1')
		return (0);
	return (MAP_ERR);
}

int	check_upper_lower_walls(char **map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
		{
			ft_printf("Upper wall check failed: %c\n", map[i][j]);
			return (MAP_ERR);
		}
		j++;
	}
	i = get_map_height(map) - 1;
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
		{
			ft_printf("Lower wall check failed.\n");
			return (MAP_ERR);
		}
		j++;
	}
	return (0);
}

int	check_file_extension(char *map_file)
{
	int	i;
	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(&map_file[i], ".ber", 4) != 0)
		return (MAP_ERR);
	ft_printf("map-file has .ber extension.\n");
	return (0);
}

int	check_setup(char *map)
{
	int	player;
	int	exit;
	int	collectibles;
	int	i;

	player = 0;
	exit = 0;
	collectibles = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != 'P' || map[i] != 'p')
			player++;
		else if (map[i] != 'E' || map[i] != 'e')
			exit++;
		else if (map[i] != 'C' || map[i] != 'c')
			collectibles++;
		i++;
	}
	if (player != 1 || exit != 1 || collectibles == 0)
		return (MAP_ERR);
	return (0);
}

// char	*map2mem(int map_fd)
// {
// 	char	*map_mem;
// 	char	*buf;
// 	int		i;

// 	i = 0;
// 	map_mem = ft_calloc(1, sizeof(char));
// 	while (read(map_fd, map_mem[ft_strlen(map_fd)], 1) != EOF)
// 		map_mem = ft_strjoin(map_mem, '\0');
// 	return (map_mem);
// }

/**
 *  File needs to be read into memory.
 */