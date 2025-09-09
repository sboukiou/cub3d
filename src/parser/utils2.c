/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:47:56 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/09 12:14:46 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse_map.h"
#include "../../includes/utils.h"

int	check_color(t_map_info **info, t_element *element)
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
	return (SUCCESS);
}

int	pars_element(t_element *element, t_map_info **info)
{
	int	fd;

	fd = 0;
	while (element)
	{
		if (element->type == C_CEILING || element->type == C_floor)
		{
			if (check_color(info, element) == FAILURE)
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

char	**fill_map_arr(char **map, int j)
{
	int		i;
	char	**arr;

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
