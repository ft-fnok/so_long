/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation-alt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:54:10 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 13:52:58 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_input(int count, char *map_file)
{
	int		map_fd;
	char	**map_ptr;
	//counter for printf
	
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
	else if (validate_chars(map_ptr) == MAP_ERR)
	{
		ft_printf("Error, invalid char.\n");
		free(map_ptr);
		return (MAP_ERR);
	}
	else if (validate_setting(map_ptr, 1, 0) == MAP_ERR)
	{
		ft_printf("Error, invalid setting.\n");
		free(map_ptr);
		return (MAP_ERR);
	}
	// else if (validate_path(map_ptr) == PATH_ERR)
	// {
	// 	ft_printf("Error, invalid path.\n");
	// 	return (PATH_ERR);
	// }
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
	const int	map_rows = get_map_height(map);
 	const int 	map_cols = ft_strlen(map[0]); //get_map_width(map[0]);
	
	ft_printf("Cols: %i, rows: %i\n", map_cols, map_rows);

	if (map_cols < 3 || map_rows < 3)
		return(MAP_ERR);
	i = 0;
	j = 0;
	if (check_upper_lower_walls(map) < 0)
		return (MAP_ERR);
	ft_printf("Upper / lower wall - verified.\n");
	while (map[i] != NULL)
	{
		if(ft_strlen(map[i]) != (size_t) map_cols)
		{
			ft_printf("Lines not of equal length.\n");
			return(MAP_ERR);
		}
		else if (check_side_walls(map, i) < 0)
		{
			ft_printf("Side walls check failed.\n");
			return(MAP_ERR);
		}
			
		i++;
	}
	ft_printf("Map validated.\n");
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
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return(i);
}
int validate_chars(char **map)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(map[i] != NULL)
	{
		while(map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' &&
				map[i][j] != 'p' && map[i][j] != 'e' && map[i][j] != 'c')
			{
				ft_printf("Wrong char detected.");
				return(MAP_ERR);
			}
		j++;
		}
		j = 0;
		i++;
	}
	ft_printf("Chars validated.\n");
	return (0);
}

int	validate_setting(char **map, int i, int j)
{
	int	player;
	int	exit;
	int	collectibles;

	player = 0;
	exit = 0;
	collectibles = 0;
	while (map[i] != NULL)
	{
		while ( map[i][j] != '\0')
		{
			if (map[i][j] == 'P' || map[i][j] == 'p')
				player++;
			else if (map[i][j] == 'C' || map[i][j] == 'c')
				collectibles++;
			else if (map[i][j] == 'E' || map[i][j] == 'e')
				exit++;
			j++;
		}
		j = 0;
		i++;
	}
	if (player != 1 || exit != 1 || collectibles < 1)
		return (MAP_ERR);
	ft_printf("Setting validated.\n");
	return (0);
}
