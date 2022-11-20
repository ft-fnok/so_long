/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation-helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:14:45 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 14:46:16 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	get_map_height(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return(i);
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
		while ( map[i][j] != '\0')
		{
			if (map[i][j] == 'P' || map[i][j] == 'p')
				player++;
			else if (map[i][j] == 'C' || map[i][j] == 'c')
				collectibles++;
			else if (map[i][j] == 'E' || map[i][j] == 'e')
				exit++;
			j++;
		}
		j = 0;
		i++;
	}
	if (player != 1 || exit != 1 || collectibles < 1)
		return (MAP_ERR);
	ft_printf("Setting validated.\n");
	return (0);
}
