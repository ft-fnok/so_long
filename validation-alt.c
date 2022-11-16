/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation-alt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:54:10 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/16 21:34:20 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_input(int count, char *map_file)
{
	int		map_fd;
//	char	*buf;
	char	**map_ptr;

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
	map_fd = open(map_file, O_RDONLY);
	map_ptr = map2mem(map_fd, map_ptr);
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

char	**map2mem(int map_fd, char **map_ptr)
{
	char	*row;
	char	buf[1];
	int		readresult;
	int		i;

	map_ptr = ft_calloc(1, sizeof(char *));
	readresult = 0;
	i = 0;
	while (TRUE)
	{
		readresult = read(map_fd, buf, 1);
		if (readresult == EOF)
			return (map_ptr);
		else if (buf == '\n') // extend map_ptr
		{
			map_ptr = extend_map(map_ptr);
			i++;
		}
		else // extend ptr[i] by buf
			map_ptr[i] = ft_strjoin(map_ptr[i], buf);
	}
}

char **extend_map(char **map_ptr);
