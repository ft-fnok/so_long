/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:35:37 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/13 22:51:20 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_HGH	400
# define WIN_WTH	800
# define TRUE		1
# define FALSE		0

# include <stdio.h>
# include <unistd.h>
# include "./printf/libftprintf.h"
# include "./minilibx_mac/mlx.h"

// initial checks
validate_input(int count, int map);
validate_map(int map);
validate_path(int map);

//  

#endif