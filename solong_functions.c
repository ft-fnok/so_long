/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:56:33 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/21 19:17:42 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	better_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	handle_no_event(void)
{
	return (0);
}

int	handle_input(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	else if (keycode == 0 || keycode == 123)
		move_left(data);
	else if (keycode == 1 || keycode == 125)
		move_down(data);
	else if (keycode == 2 || keycode == 124)
		move_right(data);
	else if (keycode == 13 || keycode == 126)
		move_up(data);
	return (0);
}

void	move_up(t_data *data)
{
	int x;
	int y;
	//ft_printf("retrieving data->p-pos y:%i, x:%i\n", data->player_pos[0], data->player_pos[1]);

	y = data->player_y;
	x = data->player_x;
	if (data->map[y - 1][x] != '1')
	{
		
		ft_printf("Updating map at old p-pos\n");
		// if (data->map[y - 1][x] != 'C')
		// 	collect(*data);
		data->map[y][x] = '0';
		ft_printf("Updating map at new p-pos\n");
		data->map[y - 1][x] = 'P';
		ft_printf("Setting new data->p-pos\n");
		player_yx(data);
		ft_printf("Updating moves++\n");
		data->moves++;
		ft_printf("Moves: %i\n", data->moves);	
	}
}

void	move_down(t_data *data)
{
	int x;
	int y;
	
	y = data->player_y;
	x = data->player_x;
	if (data->map[y + 1][x] != '1')
	{
		// if (data->map[y - 1][x] != 'C')
		// 	collect(*data);
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		player_yx(data);
		data->moves++;
		ft_printf("Moves: %i", data->moves);	
	}
}

void	move_left(t_data *data)
{
	int x;
	int y;
	
	y = data->player_y;
	x = data->player_x;
	if (data->map[y][x - 1] != '1')
	{
		// if (data->map[y - 1][x] != 'C')
		// 	collect(*data);
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		player_yx(data);
		data->moves++;
		ft_printf("Moves: %i", data->moves);	
	}
}

void	move_right(t_data *data)
{
	int x;
	int y;
	
	y = data->player_y;
	x = data->player_x;
	if (data->map[y][x + 1] != '1')
	{
		// if (data->map[y - 1][x] != 'C')
		// 	collect(*data);
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		player_yx(data);
		data->moves++;
		ft_printf("Moves: %i", data->moves);	
	}
}

void	init_data(t_data *data)
{
	init_collectibles(data);
	player_yx(data);
	data->moves = 0;
}

void	init_collectibles(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->collectibles = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'C')
				data->collectibles++;
			j++;
		}
		j = 0;
		i++;
	}
	ft_printf("Collectibles on map: %i\n", data->collectibles);
}

void	player_yx(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				data->player_y = y;
				data->player_x = x;
				break;
			}
			x++;
		}		
		x = 0;
		y++;
	}
}