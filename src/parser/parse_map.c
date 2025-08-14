/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:20:28 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/02 18:07:10 by hmouis           ###   ########.fr       */
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
		else if (ft_strchr(" 1NSEW", line[i]))
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

int	pars_element(t_element *element, t_map_info **info)
{
	int	fd;

	fd = 0;
	while (element)
	{
		if (element->type == C_CEILING)
		{
			if (pars_floor_colors(info, element->content) == FAILURE)
				return (FAILURE);
		}
		else if (element->type == C_floor)
		{
			if (pars_ceiling_colors(info, element->content) == FAILURE)
				return (FAILURE);
		}
		else
		{
			fd = open(element->content, O_RDONLY);
			if (fd < 0)
				return (printf("ERROR\nthis texture isn't available '%s'\n",
						element->content), FAILURE);
			close(fd);
		}
		element = element->next;
	}
	return (SUCCESS);
}

char **fill_map_arr(char **map, int j)
{
	int i;
	char **arr;

	i = j;
	while (map[i])
		i++;
	arr = malloc(sizeof(char *) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (map[j])
	{
		arr[i] = ft_strdup(map[j]);
		j++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	get_player_position(char **map, int *player_x, int *player_y)
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
				return ;
			}
		}
	}
}

void	fill_struct_info(t_map_info *info, t_info **final_info)
{
	int	i;

	i = -1;
	while (info->element)
	{
		if (info->element->type == T_EA)
			(*final_info)->east_textures_file = ft_strdup(info->element->content);
		else if (info->element->type == T_WE)
			(*final_info)->west_textures_file = ft_strdup(info->element->content);
		else if (info->element->type == T_SO)
			(*final_info)->south_textures_file = ft_strdup(info->element->content);
		else if (info->element->type == T_NO)
			(*final_info)->north_textures_file = ft_strdup(info->element->content);
		info->element = info->element->next;
	}
	while (++i < 3)
		(*final_info)->ceiling_colors[i] = info->ceiling[i];
	i = -1;
	while (++i < 3)
		(*final_info)->floor_colors[i] = info->floor[i];
	(*final_info)->map = info->map;
	get_player_position((*final_info)->map, &(*final_info)->player_x, &(*final_info)->player_y);
}

int	parse_map(char **av, t_map_info **info, t_info **final_info)
{
	char	**map;
	t_map map_info;

	fill_map_structure(&map_info);
	if (file_name(av[1]) == false)
		return (printf("ERROR\ninvalide name\n"), -1);
	if (fill_map(&map, av[1]) == -1)
		return (-1);
	if (is_valid_map(map, info, &map_info) == FAILURE)
		return (-1);
	if (pars_element((*info)->element, info) == FAILURE)
		return (-1);
	(*info)->map = fill_map_arr(map, map_info.map_index);
	*final_info = malloc(sizeof(t_info));
	fill_struct_info(*info, final_info); 
	return (1);
}
