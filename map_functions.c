/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:37:55 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/20 19:45:31 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			break ;
		else if (*buf == '\n')
		{
			i++;
			map_ptr = extend_map(map_ptr, i);
		}
		else
			map_ptr[i] = ft_strjoin(map_ptr[i], buf);
	}
	free(buf);
	return (map_ptr);
}

char	**extend_map(char **map_ptr, int lines)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc((lines + 1) * sizeof(char *));
	new[lines] = ft_calloc(1, sizeof(char));
	while (i < lines)
	{
		new[i] = map_ptr[i];
		i++;
	}
	free(map_ptr);
	return (new);
}
