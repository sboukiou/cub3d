/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:16:43 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/14 15:03:17 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_string(const char *str, char c)
{
	size_t	size;
	char	*buffer;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != c)
		size++;
	buffer = ft_calloc(size + 1, sizeof(char), 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, str, size + 1);
	return (buffer);
}

static char	**ft_allocate_list(const char *str, char c)
{
	char	**list;
	int		index;
	int		size;

	index = 0;
	size = 0;
	list = NULL;
	if (!str)
		return (NULL);
	while (str[index])
	{
		while (str[index] && str[index] == c)
			index++;
		if (str[index])
			size++;
		while (str[index] && str[index] != c)
			index++;
	}
	list = ft_calloc(size + 1, sizeof(char *), 1);
	return (list);
}

char	**ft_split(const char *str, char c)
{
	int		index;
	int		size;
	char	**list;

	index = 0;
	size = 0;
	list = ft_allocate_list(str, c);
	if (!list)
		return (NULL);
	while (str[index])
	{
		while (str[index] && str[index] == c)
			index++;
		if (str[index])
		{
			list[size] = ft_create_string(str + index, c);
			if (list[size] == NULL)
				return (NULL);
			size++;
		}
		while (str[index] && str[index] != c)
			index++;
	}
	list[size] = NULL;
	return (list);
}
