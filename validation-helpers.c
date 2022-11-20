/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation-helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:14:45 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 19:44:13 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_side_walls(char **map, int i)
{
	if (map[i][0] == '1' && map[i][(ft_strlen(map[i]) - 1)] == '1')
		return (0);
	return (MAP_ERR_WALL);
}

int	check_upper_lower_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			return (MAP_ERR_WALL);
		j++;
	}
	i = get_map_height(map) - 1;
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			return (MAP_ERR_WALL);
		j++;
	}
	return (0);
}

int	check_file_extension(char *map_file)
{
	int	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(&map_file[i], ".ber", 4) != 0)
		return (INPUT_ERR_EXT);
	return (0);
}

int	get_map_height(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	validate_setting(char **map, int i, int j)
{
	int	player;
	int	exit;
	int	collectibles;

	player = 0;
	exit = 0;
	collectibles = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'C')
				collectibles++;
			else if (map[i][j] == 'E')
				exit++;
			j++;
		}
		j = 0;
		i++;
	}
	if (player != 1 || exit != 1 || collectibles < 1)
		return (MAP_ERR_SET);
	return (0);
}
