/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:49:21 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/21 17:34:25 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_data *data)
{
	// t_data	data;
	// void	*mlx_ptr;
	// void	*mlx_window;
	
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return(MLX_CREATION_ERR);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_HGH, WIN_HGH, "so long ...");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win); //exchange for destruct-function later
 		return(MLX_CREATION_ERR);
	}
	//data->player_pos = get_player_pos(data->player_pos, data->map);
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data->mlx_win, &handle_input, &data);
	//mlx_hook(data->mlx_win, ON_DESTROY, 0, &handle_input, &data);
	//mlx_hook(data->mlx_win, ON_KEYDOWN, 0, &handle_input, &data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->mlx_ptr);

	return(0);
}