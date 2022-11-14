/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:17:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/14 17:40:24 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_input(int count, char *map_file)
{
	int		map_fd;
//	char	*buf;
	char	*map_ptr;

	if (count != 2)
	{	
		if (count == 1)
			ft_printf("Error, no map provided.");
		else
			ft_printf("Error, too many inputs.");
		return (INPUT_ERR);
	}
	if (check_file_extension(char *map_file) < 0)
		return (MAP_ERR);
//	buf = ft_calloc(ft_strlen(map), sizeof(char));
	map_fd = open(map_file, O_RDONLY);
	map_ptr = map2mem(map_fd);
//	read(fd_map, buf, ft_strlen(map));
	if (validate_map(map_ptr) == MAP_ERR)
	{
		ft_printf("Error, invalid map.\n");
		return (MAP_ERR);
	}
	else if (validate_path(map_ptr) == PATH_ERR)
	{
		ft_printf("Error, invalid path.\n");
		return (PATH_ERR);
	}
	return (0);
}

int validate_map(char *map)
{
	int			i;
	int			j;
	const int 	map_width = get_map_width(map);
	const int 	map_height = get_map_height(map);

	if (map_width < 0 || map_height < 0)
		return(MAP_ERR);
	i = 0;
	j = 0;
	if (check_upper_lower_walls < 0)
		return (MAP_ERR);
	while (map[i] != '\0')
	{
		if(map[i] == '\n')
		{
			if (j != map_width || check_side_walls(map, i) < 0)
				return(MAP_ERR);
			j = 0;
		}
		i++;
		j++;
	}
	return (0);
}

int	get_map_width(char *map)
{
	int i;
	
	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	if (i < 3)
		return(MAP_ERR);
	return(i);
}

int	get_map_height(char *map)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			j++;
		i++;
	}
	if (j < 3)
		return(MAP_ERR);
	return(j);
}

int	validate_path(char *map)
{

}
