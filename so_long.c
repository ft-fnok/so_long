/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:49:21 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/13 22:59:04 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int input_validation(int count, int map)
{
	if (count != 2)
	{	
		if (count == 1)
			ft_printf("Error, no map provided.");
		else
			ft_printf("Error, too many inputs.");
		return(0);
	}
	if (!validate_map(map) || !validate_path(map))
		return(0);
	return(1);
}

int main (argc, argv)
{
	void	*mlx_ptr;
	void	*mlx_window;
	
	
	if (!input_validation(argc, argv))
	{
		return(0);
	}
	
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return(0);
	mlx_window = mlx_new_window(mlx_ptr, WIN_WTH, WIN_HGH, "so long ...");
	if (mlx_window == NULL)
	{
		free(mlx_window);
		return(0);
	}	
	while (TRUE)
	{
	
	}
	mlx_destroy_window(mlx_ptr, mlx_window);	
	free(mlx_ptr);
	return(0);
}