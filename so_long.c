/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:49:21 by nlalleik          #+#    #+#             */
/*   Updated: 2022/11/13 20:50:51 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (argc, argv)
{
	if (argc != 2)
	{	
		if (argc == 1)
			ft_printf("Error, no map provided.");
		else
			ft_printf("Error, too many inputs.");
		return(0);
	}
	validate_map();
	validate_path();
	return(0);
}