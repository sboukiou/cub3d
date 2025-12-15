/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:36:22 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/14 17:09:32 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse_map.h"
#include "../../includes/macros.h"

bool	file_name(char *path, char *str)
{
	char	*name;

	if (path == NULL)
		return (false);
	name = ft_strchr(path, '.');
	if (name == NULL)
		return (false);
	while (name && ft_strchr(name + 1, '.'))
		name = ft_strchr(name + 1, '.');
	if (ft_strcmp(name, str))
		return (false);
	return (true);
}

int	count_lines(int *fd, char *file_name)
{
	int		len;
	char	*line;

	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("ERROR\n", 2);
		perror(file_name);
		return (-1);
	}
	len = 0;
	line = get_next_line(*fd);
	while (line)
	{
		line = get_next_line(*fd);
		len++;
	}
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("ERROR\n", 2);
		perror(file_name);
		return (-1);
	}
	return (len);
}

int	fill_map(char ***map, char *file_name)
{
	int	map_len;
	int	i;
	int	words;
	int	fd;

	i = 0;
	words = 0;
	map_len = count_lines(&fd, file_name);
	if (map_len < 0)
		return (-1);
	*map = ft_malloc(sizeof(char *) * (map_len + 1), 1);
	while (i < map_len)
	{
		(*map)[words] = strcpy_nl(get_next_line(fd));
		i++;
		words++;
	}
	(*map)[words] = NULL;
	return (SUCCESS);
}

int	pars_0(char *line, char **arr, int flag, int i)
{
	if ((size_t)i >= ft_strlen(arr[flag - 1]))
		return (printf("ERROR\n%s\n", ERR_INV_0_POS), FAILURE);
	if ((size_t)i >= ft_strlen(arr[flag + 1]))
		return (printf("ERROR\n%s\n", ERR_INV_0_POS), FAILURE);
	if (line[i - 1] == ' ' || line[i + 1] == ' ' || arr[flag - 1][i] == ' '
		|| arr[flag + 1][i] == ' ')
		return (printf("ERROR\n%s\n", ERR_INV_0_POS), FAILURE);
	return (SUCCESS);
}

int	pars_empty_line(int *i, char *line)
{
	if (is_empty(line, 0) == SUCCESS)
		return (FAILURE);
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] != '1')
		return (printf("ERROR\n%s\n", ERR_MAP_NO_WALLS), FAILURE);
	return (SUCCESS);
}
