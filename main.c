/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:32:54 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 22:24:52 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	ft_printf("Starting validation...\n");
	i = validate_input(argc, argv[1]);
	map = ft_calloc(1, sizeof(char *));
	if (i == 0)
	{
		s_solong.map = map2mem(open(argv[1], O_RDONLY), map);
		ft_printf("MAP\n===========\n");
		while (s_solong.map[i] != NULL)
		{
			ft_printf("[%i]%s\n", i, s_solong.map[i]);
			i++;
		}
		so_long(ft_strlen(s_solong.map[0]), get_map_height(s_solong.map));
	}
	else
		error_interpreter(i);
	return (i);
}
