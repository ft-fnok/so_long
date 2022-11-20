/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path-validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:48:05 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 16:09:41 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_path(char **map_ptr/*, int count_col*/)
{
	int	*player_pos;
//	int count_col_rem;
	
//	count_col_rem = count_col;
	player_pos = (int *)malloc(2 * sizeof(int));
	player_pos = get_player_pos(player_pos, map_ptr);
	pour_water(player_pos, map_ptr);
	free(player_pos);
	return (0);
}

int	*get_player_pos(int *player_pos,char **map_ptr)
{
	int	y;
	int x;
	
	y = 0;
	x = 0;
	while (map_ptr[y] != NULL)
	{
		while (map_ptr[y][x] != '\0')
		{
			if (map_ptr[y][x] == 'p' || map_ptr[y][x] == 'P')
			{
				player_pos[0] = y;
				player_pos[1] = x;
				break;
			}
			x++;
		}
		x= 0;
		y++;
	}
	ft_printf("Player at: y: %i x: %i\n", player_pos[0], player_pos[1]);
	return (player_pos);
}

void	pour_water(int *pos, char **map_ptr)
{
	int y;
	int x;
	
	y = pos[0];
	x = pos[1];
	if (map_ptr[y][x] != '1')
	{
		map_ptr[y][x] = 'W';
		pour_water(&pos[(y - 1), x], map_ptr);
		pour_water(&pos[y, (x - 1)], map_ptr);
		pour_water(&pos[(y + 1), x], map_ptr);
		pour_water(&pos[y, (x + 1)], map_ptr);
	}
}