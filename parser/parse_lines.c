/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:55:01 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/02 17:03:53 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_map.h"

int	first_line(char *line, int flag)
{
	int	i;

	i = 0;
	if (is_empty(line) == SUCCESS)
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
			return (ft_putstr_fd("ERROR\nmultiple position of player\n", 2), FAILURE);
	}
	return (SUCCESS);
}

int	last_letter(char *line, int i)
{
	i--;
	while (line[i] == ' ')
		i--;
	if (line[i] != '1')
		return (ft_putstr_fd("ERROR\nthe last letter must be a wall : '1'\n",
				2), FAILURE);
	return (SUCCESS);
}

int	valid_element(char **map, t_map *map_info, int *i, t_element **element)
{
	int	flag;

	flag = 0;
	while (map[*i])
	{
		if (track_textures(map[*i], &flag, map_info, element) == SUCCESS && flag != 2)
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
		return (printf("ERROR\nthere is no map\n"), FAILURE);
	return (SUCCESS);
}

int	pars_lines(char **map, t_map *map_info, int *i)
{
	int	flag;

	flag = 0;
	while (map[*i])
	{
		map_info->i = *i;
		if (pars_line(map[*i], flag, map_info, map) == FAILURE)
			return (FAILURE);
		(*i)++;
		flag++;
	}
	if (flag < 3)
		return (printf("ERROR\nmap size not valide\n"), FAILURE);
	return (SUCCESS);
}
