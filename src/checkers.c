/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:45:02 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/14 15:06:44 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"
#include "../includes/colors.h"
#include "../includes/cub.h"
#include "../includes/init.h"
#include "../lib/libft/libft.h"

bool	is_prog_valid(t_prog *prog)
{
	if (prog == NULL)
		return (false);
	if (prog->info == NULL)
		return (false);
	if (prog->mlx == NULL)
		return (false);
	return (true);
}

void	print_controllers(void)
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

void	handle_player_direction(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dirx = 0;
		player->diry = -1;
		player->planex = 0.66;
		player->planey = 0;
	}
	else if (c == 'S')
	{
		player->dirx = 0;
		player->diry = 1;
		player->planex = -0.66;
		player->planey = 0;
	}
	else if (c == 'W')
	{
		player->dirx = -1;
		player->diry = 0;
		player->planex = 0;
		player->planey = -0.66;
	}
}

int	init_prog_data(t_prog **prog, char **av)
{
	t_map_info	*parse;
	t_player	*player;

	*prog = ft_malloc(sizeof(t_prog), 1);
	player = ft_malloc(sizeof(t_player), 1);
	parse = NULL;
	(*prog)->info = NULL;
	if (parse_map(av, &parse, &(*prog)->info) == FAILURE)
		return (FAILURE);
	print_controllers();
	if (init(&(*prog)->info, player) == FAILURE)
		return (FAILURE);
	(*prog)->player = player;
	(*prog)->attack_anim.frames = NULL;
	(*prog)->run_anim.frames = NULL;
	(*prog)->stand_anim.frames = NULL;
	(*prog)->no_mouse = 0;
	(*prog)->info->player = player;
	(*prog)->mlx = ft_malloc(sizeof(t_mlx), 1);
	(*prog)->assets = ft_malloc(sizeof(t_assets), 1);
	(*prog)->is_attacking = false;
	(*prog)->is_running = false;
	(*prog)->player = player;
	return (SUCCESS);
}
