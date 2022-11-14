/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:49:21 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/14 10:56:40 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (argc, argv)
{
	void	*mlx_ptr;
	void	*mlx_window;
	int		map;
	
	validate_input(argc, argv);
	
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return(MLX_CREATION_ERR);
	mlx_window = mlx_new_window(mlx_ptr, WIN_WTH, WIN_HGH, "so long ...");
	if (mlx_window == NULL)
	{
		free(mlx_window);
		return(MLX_CREATION_ERR);
	}	
	while (TRUE)
	{
		pause();
	}
	mlx_destroy_window(mlx_ptr, mlx_window);	
	free(mlx_ptr);
	return(0);
}