/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:17:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/14 13:15:35 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int validate_input(int count, char *map)
{
	int		fd_map;
	char	*buf;
	
	if (count != 2)
		{	
			if (count == 1)
				ft_printf("Error, no map provided.");
			else
				ft_printf("Error, too many inputs.");
			return(INPUT_ERR);
		}
	buf = ft_calloc(ft_strlen(map), sizeof(char));
	fd_map = open(map);
	read(fd_map, buf, ft_strlen(map));
	if (validate_map(buf) == MAP_ERR)
	{
		ft_printf("Error, invalid map.");
		return(MAP_ERR);
	}
	else if (validate_path(buf) == PATH_ERR)
	{
		ft_printf("Error, invalid path.");
		return(PATH_ERR);
	}
	return(0);
}

int validate_map(char *map)
{
	int i;
	int j;
	const int map_width = get_map_width(map);
	const int map_height = get_map_height(map);

	i = 0;
	j = 0;
	while (map[i] != '\n' && map[i] != '\0')
	{
		if (map[i] != 1)
			return(MAP_ERR);
		map_width++;
		i++;
	}
	while (map[i] != '\0')
	{
		while (map[i] != '\n' && map[i] != '\0')
		{
			map_width++;
			i++;
		}
		map_height++;
		while (map[j] != '\n')
			j++;			
	} 
}
int get_map_width(char *map)
{
	int i;
	
	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	return(i);
}

int get_map_height(char *map)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			j++;
	}
	return(j);
}

int validate_path(char *map)
{
	
}