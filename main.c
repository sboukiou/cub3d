/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:46 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/08 10:48:03 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub.h"
#include "includes/mlx_create.h"
#include "includes/mlx_draw.h"
#include "includes/mlx_game_simulation.h"
#include "lib/mlx_linux/mlx.h"

int	main(int ac, char **av)
{
	t_map_info	*parse;
	t_info	*info;
	t_mlx	mlx;
	t_prog	prog;

	
	parse = NULL;
	info = NULL;
	if (ac != 2)
		return (printf("ERROR\nmissing file\n"), FAILURE);
<<<<<<< HEAD

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
=======
	if (parse_map(av, &parse, &info) == FAILURE)
		return (FAILURE);
	
>>>>>>> dcc9e3e47551a3229bf949060d30aa73843f189f
	return (SUCCESS);
}
