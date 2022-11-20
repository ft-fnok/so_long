/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path-validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:48:05 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 19:47:43 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_path(char **map_ptr)
{
	int	*player_pos;

	player_pos = (int *)malloc(2 * sizeof(int));
	player_pos = get_player_pos(player_pos, map_ptr);
	pour_water(player_pos[0], player_pos[1], map_ptr);
	free(player_pos);
	return (check_flooded_map(map_ptr));
}

int	*get_player_pos(int *player_pos, char **map_ptr)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map_ptr[y] != NULL)
	{
		while (map_ptr[y][x] != '\0')
		{
			if (map_ptr[y][x] == 'P')
			{
				player_pos[0] = y;
				player_pos[1] = x;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (player_pos);
}

void	pour_water(int pos_y, int pos_x, char **map_ptr)
{
	if (map_ptr[pos_y][pos_x] != '1' && map_ptr[pos_y][pos_x] != '*')
	{
		map_ptr[pos_y][pos_x] = '*';
		pour_water((pos_y - 1), pos_x, map_ptr);
		pour_water(pos_y, (pos_x - 1), map_ptr);
		pour_water((pos_y + 1), pos_x, map_ptr);
		pour_water(pos_y, (pos_x + 1), map_ptr);
	}
}

int	check_flooded_map(char **map_ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_ptr[i] != NULL)
	{
		while (map_ptr[i][j] != '\0')
		{
			if (map_ptr[i][j] == 'C' || map_ptr[i][j] == 'E')
				return (PATH_ERR);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
