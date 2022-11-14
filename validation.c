/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:17:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/14 14:04:51 by nlalleik         ###   ########.fr       */
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
int get_map_width(char *map)
{
	int i;
	
	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	if (i < 3)
		return(MAP_ERR);
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
		i++;
	}
	if (j < 3)
		return(MAP_ERR);
	return(j);
}

int validate_path(char *map)
{
	
}

int	check_side_walls(char *map, int i)
{
	if (map[i - 1] == 1 && (map[i + 1] == 1 || map[i + 1] == '\0'))
		return (0);
	return(MAP_ERR);
}

int	check_upper_lower_walls(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
	{
		if (map[i] != 1)
			return (MAP_ERR);
		i++;
	}
	i = ft_strlen(map);
	if (map[i] != '\n')
		i--;
	while (map[i] != '\n')
	{
		if (map[i] != 1)
			return (MAP_ERR);
		i--;
	}
	return (0);
}