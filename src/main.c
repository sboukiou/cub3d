/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:46 by hmouis            #+#    #+#             */
/*   Updated: 2025/11/04 14:36:07 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/parse_map.h"
#include "../includes/init.h"
#include "../includes/game.h"
#include "../includes/colors.h"
#include "../includes/animation.h"

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

void init(t_info **info, t_player *player)
{
	char c;

	c = 0;
	(*info)->door_textures_file = "textures/door.xpm";
	get_player_position((*info)->map, &player->posX, &player->posY, &c);
	if (c == 'N')  // North = UP on screen = negative Y direction
	{
		player->dirX = 0;
		player->dirY = -1;      // NEGATIVE (moving up decreases Y)
		player->planeX = 0.66;   // Perpendicular: points right
		player->planeY = 0;
	}
	else if (c == 'S')  // South = DOWN on screen = positive Y direction
	{
		player->dirX = 0;
		player->dirY = 1;        // POSITIVE (moving down increases Y)
		player->planeX = -0.66;  // Perpendicular: points left
		player->planeY = 0;
	}
	else if (c == 'W')  // West = LEFT on screen = negative X direction
	{
		player->dirX = -1;       // NEGATIVE (moving left decreases X)
		player->dirY = 0;
		player->planeX = 0;
		player->planeY = -0.66;  // Perpendicular: points up (negative Y)
	}
	else if (c == 'E')  // East = RIGHT on screen = positive X direction
	{
		player->dirX = 1;        // POSITIVE (moving right increases X)
		player->dirY = 0;
		player->planeX = 0;
		player->planeY = 0.66;   // Perpendicular: points down (positive Y)
	}
	(*info)->player = player;
}

int	main(int ac, char **av)
{
	t_map_info	*parse;
	t_info		*info;
	t_mlx		mlx;
	t_player	*player;
	t_prog		prog;
	t_assets	assets;

	player = malloc(sizeof(t_player));
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
	init(&info, player);
	prog.mlx = &mlx;
	prog.info = info;
	prog.assets = &assets;
	prog.is_attacking = false;
	prog.is_running = false;
	ft_bzero(prog.keys, sizeof(prog.keys));
	mlx_init_display(&mlx);
	printf("[Display is initialized successfully !]\n");

	if (load_textures(prog.info,prog.mlx) == FAILURE || load_stand_animation(&prog) == FAILURE 
			|| load_attack_animation(&prog) == FAILURE || load_run_animation(&prog) == FAILURE)
		return (FAILURE);
	/*Starting the game simulation*/
	mlx_simulate_game(&prog);
	
	return (SUCCESS);
}
