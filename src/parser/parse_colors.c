/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:53:50 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/09 11:43:06 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/textures.h"

void	fill_map_structure(t_map *map)
{
	map->player = false;
	map->so = false;
	map->f = false;
	map->c = false;
	map->ea = false;
	map->we = false;
	map->no = false;
	map->i = 0;
	map->map_index = 0;
}

int	floor_color(char *line, int *flag, t_map *map_info, t_element **element)
{
	char	*path;

	path = NULL;
	if (!ft_strncmp(line, "F ", 2))
	{
		if (!map_info->f)
			map_info->f = true;
		else
			return (*flag = 1, SUCCESS);
		if (check_path(line, &path) == FAILURE)
			return (*flag = 1, SUCCESS);
		add_node(element, path, C_floor);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	check_path(char *str, char **path)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] != ' ')
			i++;
		while (str[i] == ' ')
			i++;
		if (!str[i])
			return (FAILURE);
		while (str[i] && str[i] != ' ')
		{
			char_join(path, str[i]);
			i++;
		}
		while (str[i] == ' ')
			i++;
		if (str[i])
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ceiling_color(char *line, int *flag, t_map *map_info, t_element **element)
{
	char	*path;

	path = NULL;
	if (!ft_strncmp(line, "C ", 2))
	{
		if (!map_info->c)
			map_info->c = true;
		else
			return (*flag = 1, SUCCESS);
		if (check_path(line, &path) == FAILURE)
			return (*flag = 1, SUCCESS);
		add_node(element, path, C_CEILING);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	pars_floor_colors(t_map_info **info, char *str)
{
	int		i;
	char	**arr;

	i = 0;
	arr = NULL;
	if (count_comma(str) == FAILURE)
		return (FAILURE);
	arr = ft_split(str, ',');
	i = 0;
	while (arr[i])
		i++;
	if (i != 3)
		return (printf("ERROR\nmore or less than range : '3'"), FAILURE);
	i = 0;
	while (arr[i])
	{
		(*info)->floor[i] = ft_atoi_color(arr[i]);
		if ((*info)->floor[i] == -1)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
