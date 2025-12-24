/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:23:08 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/14 17:13:02 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_map.h"
#include "../includes/init.h"
#include "../includes/game.h"
#include "../includes/events.h"
#include "../includes/checkers.h"
#include "../includes/animation.h"
#include "../lib/libft/libft.h"

int	init(t_info **info, t_player *player)
{
	char	c;
	int		fd;

	fd = open("textures/door.xpm", O_RDONLY);
	if (fd < 0)
		return (printf("ERROR\n Failed to open door texture file\n"), FAILURE);
	close(fd);
	c = 0;
	(*info)->door_textures_file = "textures/door.xpm";
	get_player_position((*info)->map, &player->posx, &player->posy, &c);
	if (c == 'N' || c == 'S' || c == 'W')
		handle_player_direction(player, c);
	else if (c == 'E')
	{
		player->dirx = 1;
		player->diry = 0;
		player->planex = 0;
		player->planey = 0.66;
	}
	(*info)->player = player;
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_prog		*prog;

	if (ac != 2)
		return (printf("ERROR\nmissing file\n"), FAILURE);
	if (init_prog_data(&prog, av) == FAILURE)
		return (ft_exit(NULL), FAILURE);
	ft_bzero(prog->keys, sizeof(prog->keys));
	if (mlx_init_display(prog->mlx))
		return (destroy_program(prog), FAILURE);
	printf("[Display is initialized successfully !]\n");
	if (load_textures(prog->info, prog->mlx) == FAILURE
		|| load_animation(prog, &prog->stand_anim,
			STAND_FRAMES, "textures/stand/") == FAILURE
		|| load_animation(prog, &prog->attack_anim,
			ATTACK_FRAMES, "textures/attack/") == FAILURE
		|| load_animation(prog, &prog->run_anim,
			RUN_FRAMES, "textures/run/") == FAILURE)
		return (destroy_program(prog), FAILURE);
	mlx_simulate_game(prog);
	return (destroy_program(prog), SUCCESS);
}
