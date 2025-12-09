/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:46 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/09 11:52:52 by hmouis           ###   ########.fr       */
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
	get_player_position((*info)->map, &player->posx, &player->posy, &c);
	if (c == 'N')  // North = UP on screen = negative Y direction
	{
		player->dirx = 0;
		player->diry = -1;      // NEGATIVE (moving up decreases y)
		player->planex = 0.66;   // Perpendicular: points right
		player->planey = 0;
	}
	else if (c == 'S')  // South = DOWN on screen = positive y direction
	{
		player->dirx = 0;
		player->diry = 1;        // POSITIVE (moving down increases y)
		player->planex = -0.66;  // Perpendicular: points left
		player->planey = 0;
	}
	else if (c == 'W')  // West = LEFT on screen = negative x direction
	{
		player->dirx = -1;       // NEGATIVE (moving left decreases x)
		player->diry = 0;
		player->planex = 0;
		player->planey = -0.66;  // Perpendicular: points up (negative y)
	}
	else if (c == 'E')  // East = RIGHT on screen = positive x direction
	{
		player->dirx = 1;        // POSITIVE (moving right increases x)
		player->diry = 0;
		player->planex = 0;
		player->planey = 0.66;   // Perpendicular: points down (positive y)
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
	prog.player = player;
	ft_bzero(prog.keys, sizeof(prog.keys));
	mlx_init_display(&mlx);
	printf("[Display is initialized successfully !]\n");

	if (load_textures(prog.info,prog.mlx) == FAILURE || load_animation(&prog, &prog.stand_anim, STAND_FRAMES, "textures/stand/") == FAILURE 
			|| load_animation(&prog, &prog.attack_anim, ATTACK_FRAMES, "textures/attack/") == FAILURE || load_animation(&prog, &prog.run_anim, RUN_FRAMES, "textures/run/") == FAILURE)
		return (FAILURE);
	/*Starting the game simulation*/
	mlx_simulate_game(&prog);
	
	return (SUCCESS);
}
