/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:32:54 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/21 19:13:40 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;
	t_data	data;

	ft_printf("Starting validation...\n");
	i = validate_input(argc, argv[1]);
	map = ft_calloc(1, sizeof(char *));
	
	if (i == 0)
	{
		data.map = map2mem(open(argv[1], O_RDONLY), map);
		ft_printf("MAP\n===========\n");
		while (data.map[i] != NULL)
		{
			ft_printf("[%i]%s\n", i, data.map[i]);
			i++;
		}
		init_data(&data);
		ft_printf("Data initialized. Player y: %i, x: %i\n", data.player_y, data.player_x);
		so_long(&data);
	}
	else
		error_interpreter(i);
	return (i);
}
