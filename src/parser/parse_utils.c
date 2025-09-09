/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:38:36 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/09 11:43:25 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	char_join(char **path, char c)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(*path) + 2));
	while (path && *path && (*path)[i])
	{
		new_str[i] = (*path)[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	*path = new_str;
}

int	count_comma(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
		if (count > 2)
			return (printf("ERROR\nmore than two ',' {%d}\n", count), FAILURE);
	}
	return (SUCCESS);
}

char	*strcpy_nl(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	while (str[i] && str[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	all_element(t_map map_info)
{
	if (!map_info.c || !map_info.f || !map_info.we || !map_info.ea
		|| !map_info.no || !map_info.so)
		return (FAILURE);
	return (SUCCESS);
}

int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
	{
		ft_putstr_fd("ERROR\nempty line\n", 2);
		return (SUCCESS);
	}
	return (FAILURE);
}
