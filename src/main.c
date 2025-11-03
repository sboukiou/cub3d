/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:46 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/17 15:22:03 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/init.h"
#include "../includes/game.h"
#include "../includes/colors.h"

static void	print_controllers(void)
{
	printf(CYAN "\n");
	printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░░░█▀▀░█▀█░█▀█░▀█▀░█▀▄░█▀█░█░░░█▀▀\n");
	printf("░█░░░█░█░█▀▄░░▀▄░█░█░░░█░░░█░█░█░█░░█░░█▀▄░█░█░█░░░▀▀█\n");
	printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░░░▀▀▀░▀▀▀░▀░▀░░▀░░▀░▀░▀▀▀░▀▀▀░▀▀▀\n");
	printf(RESET "\n");
	printf(CYAN "\tW" RESET ": move forward\t");
	printf(CYAN "\tS" RESET ": move backward\n");
	printf(CYAN "\tA" RESET ": strafe left\t");
	printf(CYAN "\tD" RESET ": strafe right\n");
	printf(CYAN "\t<" RESET ": rotate left\t");
	printf(CYAN "\t>" RESET ": rotate right\n");
	printf("\n");
}

int	main(int ac, char **av)
{
	t_map_info	*parse;
	t_info	*info;
	t_mlx	mlx;
	t_player	player;
	t_prog	prog;

	
	parse = NULL;
	info = NULL;
	if (ac != 2)
		return (printf("ERROR\nmissing file\n"), FAILURE);

	/*Parsing the map info*/
	if (parse_map(av, &parse, &info) == FAILURE)
	{
		printf("Failed to parse the map!\n");
		return (FAILURE);
	}

	/*Initializing the display, window and image attributes*/
	print_controllers();
	prog.mlx = &mlx;
	prog.info = info;
	player.posX = 9;
	player.posY = 9;
	player.dirX = -1;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0.66;
	info->player = &player;
	mlx_init_display(&mlx);
	printf("[Display is initialized successfully !]\n");

	/*Starting the game simulation*/
	mlx_simulate_game(&prog);
	
	return (SUCCESS);
}
