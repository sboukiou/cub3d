/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:20:28 by hmouis            #+#    #+#             */
/*   Updated: 2025/11/04 14:17:28 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse_map.h"

int	pars_line(char *line, int flag, t_map *map, char **arr)
{
	int	i;

	i = 0;
	if (!flag || flag == -1)
		return (first_line(line, flag));
	if (pars_empty_line(&i, line) == FAILURE)
		return (FAILURE);
	while (line[i])
	{
		if (line[i] == '0')
		{
			if (pars_0(line, arr, map->i, i) == FAILURE)
				return (FAILURE);
		}
		else if (ft_strchr(" 1NSEWD", line[i]))
		{
			if (check_position(line[i], map) == FAILURE)
				return (FAILURE);
		}
		else
			return (printf("ERROR\ninvalide char : '%c'\n", line[i]), FAILURE);
		i++;
	}
	return (last_letter(line, i));
}

int	is_valid_map(char **map, t_map_info **info, t_map *map_info)
{
	int			i;
	t_element	*element;

	i = 0;
	element = NULL;
	if (valid_element(map, map_info, &i, &element) == FAILURE)
		return (FAILURE);
	map_info->map_index = i;
	if (pars_lines(map, map_info, &i) == FAILURE)
		return (FAILURE);
	if (!map[i])
		i--;
	map_info->i = i;
	if (pars_line(map[i], -1, map_info, map) == FAILURE)
		return (FAILURE);
	if (!map_info->player)
	{
		ft_putstr_fd("ERROR\nplayer position is necessary\n", 2);
		return (FAILURE);
	}
	*info = creat_node_info(element);
	return (SUCCESS);
}

void	get_player_position(char **map, double *player_x, double *player_y, char *c)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NESW", map[i][j]))
			{
				*player_x = j;
				*player_y = i;
				*c = map[i][j];
				return ;
			}
		}
	}
}

int	get_width(char **map)
{
	int	i;
	int	max;

	max = 0;
	i = -1;
	while (map[++i])
	{
		if (max < (int)ft_strlen(map[i]))
			max = (int)ft_strlen(map[i]);
	}
	return (max);
}

int	parse_map(char **av, t_map_info **info, t_info **final_info)
{
	char	**map;
	t_map	map_info;

	fill_map_structure(&map_info);
	if (file_name(av[1]) == false)
		return (printf("ERROR\ninvalide name\n"), FAILURE);
	if (fill_map(&map, av[1]) == -1)
		return (FAILURE);
	if (is_valid_map(map, info, &map_info) == FAILURE)
		return (FAILURE);
	if (pars_element((*info)->element, info) == FAILURE)
		return (FAILURE);
	(*info)->map = fill_map_arr(map, map_info.map_index);
	*final_info = malloc(sizeof(t_info));
	fill_struct_info(*info, final_info);
	(*final_info)->map_height = 0;
	while ((*final_info)->map[(*final_info)->map_height])
		(*final_info)->map_height++;
	(*final_info)->map_width = get_width((*final_info)->map);
	(*final_info)->door = creat_doors((*final_info)->map, &(*final_info)->n_doors);
	return (SUCCESS);
}
