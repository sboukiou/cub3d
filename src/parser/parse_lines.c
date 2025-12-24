/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:55:01 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/09 11:25:20 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse_map.h"
#include "../../includes/macros.h"

int	first_line(char *line, int flag)
{
	int	i;

	i = 0;
	if (is_empty(line, 0) == SUCCESS)
		return (FAILURE);
	while (line[i] && (line[i] == ' ' || line[i] == '1'))
		i++;
	if (line[i])
	{
		if (!flag)
			printf("ERROR\nthe first line must be ");
		else
			printf("ERROR\nthe last line must be");
		printf(" composed by a space : ' ' and wall : '1'\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_position(char c, t_map *map)
{
	if (ft_strchr("NSEW", c))
	{
		if (!map->player)
			map->player = true;
		else
			return (printf("ERROR\n%s\n", ERR_NUM_PLAYER),
				FAILURE);
	}
	return (SUCCESS);
}

int	last_letter(char *line, int i)
{
	i--;
	while (line[i] == ' ')
		i--;
	if (line[i] != '1')
		return (printf("ERROR\n%s\n", ERR_MAP_NO_WALLS), FAILURE);
	return (SUCCESS);
}

int	valid_element(char **map, t_map *map_info, int *i, t_element **element)
{
	int	flag;

	flag = 0;
	while (map[*i])
	{
		if (empty_line(map[*i], i) == SUCCESS)
			continue ;
		if (track_textures(map[*i], &flag, map_info, element) == SUCCESS
			&& flag != 2)
		{
			if (flag)
				return (printf("ERROR\ninvalide element\n"), FAILURE);
			(*i)++;
			continue ;
		}
		else
			break ;
	}
	if (all_element(*map_info) == FAILURE)
		return (printf("ERROR\nsome element are missing\n"), FAILURE);
	if (!map[*i])
		return (printf("ERROR\n%s\n", ERR_MAP_MISSING), FAILURE);
	return (SUCCESS);
}

int	pars_lines(char **map, t_map *map_info, int *i)
{
	int	flag;

	flag = 0;
	while (map[*i])
	{
		map_info->i = *i;
		if (is_empty(map[*i], 1) == SUCCESS)
			return (SUCCESS);
		if (pars_line(map[*i], flag, map_info, map) == FAILURE)
			return (FAILURE);
		(*i)++;
		flag++;
	}
	if (flag < 3)
		return (printf("ERROR\n%s\n", ERR_MAP_TOO_SMALL), FAILURE);
	return (SUCCESS);
}
