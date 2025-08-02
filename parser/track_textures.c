/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:52:47 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/02 18:00:14 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/textures.h"


int	track_textures(char *line, int *flag, t_map *map_info, t_element **element)
{
	if (north_texture(line, flag, map_info, element) == SUCCESS)
		return (SUCCESS);
	else if (west_texture(line, flag, map_info, element) == SUCCESS)
		return (SUCCESS);
	else if (south_texture(line, flag, map_info, element) == SUCCESS)
		return (SUCCESS);
	else if (east_texture(line, flag, map_info, element) == SUCCESS)
		return (SUCCESS);
	else if (floor_color(line, flag, map_info, element) == SUCCESS)
		return (SUCCESS);
	else if (ceiling_color(line, flag, map_info, element) == SUCCESS)
		return (SUCCESS);
	else if (!line[0])
		return (SUCCESS);
	return (FAILURE);
}

int	north_texture(char *line, int *flag, t_map *map_info, t_element **element)
{
	char	*path;

	path = NULL;
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (!map_info->no)
			map_info->no = true;
		else
			return (*flag = 1, 1);
		if (check_path(line, &path) == FAILURE)
			return (*flag = 1, SUCCESS);
		add_node(element, path, T_NO);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	west_texture(char *line, int *flag, t_map *map_info, t_element **element)
{
	char	*path;

	path = NULL;
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (!map_info->we)
			map_info->we = true;
		else
			return (*flag = 1, 1);
		if (check_path(line, &path) == FAILURE)
			return (*flag = 1, SUCCESS);
		add_node(element, path, T_WE);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	east_texture(char *line, int *flag, t_map *map_info, t_element **element)
{
	char	*path;

	path = NULL;
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (!map_info->ea)
			map_info->ea = true;
		else
			return (*flag = 1, 1);
		if (check_path(line, &path) == FAILURE)
			return (*flag = 1, SUCCESS);
		add_node(element, path, T_EA);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	south_texture(char *line, int *flag, t_map *map_info, t_element **element)
{
	char	*path;

	path = NULL;
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (!map_info->so)
			map_info->so = true;
		else
			return (*flag = 1, 1);
		if (check_path(line, &path) == FAILURE)
			return (*flag = 1, SUCCESS);
		add_node(element, path, T_SO);
		return (SUCCESS);
	}
	return (FAILURE);
}
