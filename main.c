/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:46 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/01 09:52:29 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub.h"
#include "includes/mlx_create.h"
#include "includes/mlx_draw.h"
#include "includes/mlx_game_simulation.h"
#include "lib/mlx_linux/mlx.h"

int	main(int ac, char **av)
{
	t_map_info	*map_info;
	t_info	*info;
	t_mlx	mlx;
	t_prog	prog;

	
	map_info = NULL;
	info = NULL;
	if (ac != 2)
		return (printf("ERROR\nmissing file\n"), FAILURE);

	/*Parsing the map info*/
	if (parse_map(av, &map_info, &info) == FAILURE)
		return (FAILURE);
	printf("[Parsing done successfully !]\n");

	/*Initializing the display, window and image attributes*/
	mlx_init_display(&mlx);
	printf("[Display is initialized successfully !]\n");

	/*Starting the game simulation*/
	prog.mlx = &mlx;
	prog.info = info;
	mlx_simulate_game(&prog);
	return (SUCCESS);
}
