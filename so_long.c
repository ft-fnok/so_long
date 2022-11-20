/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:49:21 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 22:32:54 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(int height, int width)
{
	void	*mlx_ptr;
	void	*mlx_window;
	
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return(MLX_CREATION_ERR);
	mlx_window = mlx_new_window(mlx_ptr, (height * 80), (width * 80), "so long ...");
	if (mlx_window == NULL)
	{
		free(mlx_window);
		return(MLX_CREATION_ERR);
	}
	mlx_loop(mlx_ptr);

	mlx_destroy_window(mlx_ptr, mlx_window);
	free(mlx_ptr);
	return(0);
}