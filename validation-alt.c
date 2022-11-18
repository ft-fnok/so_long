/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation-alt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:54:10 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/18 21:41:21 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_input(int count, char *map_file)
{
	int		map_fd;
	char	**map_ptr;

	if (count != 2)
	{
		if (count == 1)
			ft_printf("Error, no map provided.");
		else
			ft_printf("Error, too many inputs.");
		return (INPUT_ERR);
	}
	if (check_file_extension(map_file) < 0)
		return (MAP_ERR);
	map_fd = open(map_file, O_RDONLY);
	map_ptr = ft_calloc(1, sizeof(char *));
	map_ptr = map2mem(map_fd, map_ptr);
	ft_printf("FD: %i -- Map loaded to memory.\n", map_fd);
	if (validate_map(map_ptr) == MAP_ERR)
	{
		ft_printf("Error, invalid map.\n");
		free(map_ptr);
		return (MAP_ERR);
	}
	// else if (validate_path(map_ptr) == PATH_ERR)
	// {
	// 	ft_printf("Error, invalid path.\n");
	// 	return (PATH_ERR);
	// }
	ft_printf("Map validated.\n");
	free(map_ptr);
	return (0);
}

char	**map2mem(int map_fd, char **map_ptr)
{
	char	*buf;
	int		readresult;
	int		i;

	readresult = 0;
	i = 0;
	buf = ft_calloc(2, sizeof(char));
	map_ptr[0] = ft_calloc(1, sizeof(char));
	while (TRUE)
	{
		readresult = read(map_fd, buf, 1);
		if (readresult != 1)
			break;
		else if (*buf == '\n') // extend map_ptr
		{
			i++;
			map_ptr = extend_map(map_ptr, i);
		}
		else // extend ptr[i] by buf
			map_ptr[i] = ft_strjoin(map_ptr[i], buf);
	}
	free(buf);
	return(map_ptr);
}

int validate_map(char **map)
{
	int			i;
	int			j;
	const int 	map_cols = ft_strlen(map[0]); //get_map_width(map[0]);
	const int 	map_rows = get_map_height(map);
	ft_printf("Cols: %i, rows: %i\n", map_cols, map_rows);

	if (map_cols < 3 || map_rows < 3)
		return(MAP_ERR);
	i = 0;
	j = 0;
	if (check_upper_lower_walls < 0)
		return (MAP_ERR);
	while (map[i])
	{
		if(ft_strlen(map[i]) != (size_t) map_cols || check_side_walls(map, i) < 0)
				return(MAP_ERR);
		i++;
	}
	return (0);
}

// int	get_map_width(char *map)
// {
// 	int i;

// 	i = 0;
// 	while (map[i] != '\n' && map[i] != '\0')
// 		i++;
// 	if (i < 3)
// 		return(MAP_ERR);
// 	return(i);
// }

int	get_map_height(char **map)
{
	int i;

	i = 0;
	while (map[i][0] != 0)
		i++;
	return(i);
}
