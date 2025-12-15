/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:42:43 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/14 15:08:13 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse_map.h"
#include "../../includes/utils.h"

int	pars_ceiling_colors(t_map_info **info, char *str)
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
		(*info)->ceiling[i] = ft_atoi_color(arr[i]);
		if ((*info)->ceiling[i] == -1)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	ft_atoi_color(char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		if (result > 255)
			return (printf("ERROR\n'%d' not in range [0, 255]\n", result), -1);
		i++;
	}
	if (str[i])
		return (printf("ERROR\nnot a digit '%c'\n", str[i]), -1);
	else if (result >= 0 && result <= 255)
		return (result);
	else
		return (printf("ERROR\n'%d' not in range [0, 255]\n", result), -1);
}

char	**fill_final_map(char **map)
{
	int		i;
	char	**new_map;

	new_map = NULL;
	i = 0;
	while (map[i])
		i++;
	new_map = ft_malloc(sizeof(char *) * (i + 1), 1);
	if (new_map == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (new_map[i] == NULL)
			return (NULL);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	fill_tex_file(char *str, t_info **final_info, t_type type)
{
	if (type == T_EA)
		(*final_info)->east_textures_file = ft_strdup(str);
	else if (type == T_WE)
		(*final_info)->west_textures_file = ft_strdup(str);
	else if (type == T_SO)
		(*final_info)->south_textures_file = ft_strdup(str);
	else if (type == T_NO)
		(*final_info)->north_textures_file = ft_strdup(str);
}

void	fill_struct_info(t_map_info *info, t_info **final_info)
{
	int	i;

	i = -1;
	while (info->element)
	{
		fill_tex_file(info->element->content, final_info, info->element->type);
		info->element = info->element->next;
	}
	while (++i < 3)
		(*final_info)->ceiling_colors[i] = info->ceiling[i];
	i = -1;
	while (++i < 3)
		(*final_info)->floor_colors[i] = info->floor[i];
	(*final_info)->map = fill_final_map(info->map);
}
